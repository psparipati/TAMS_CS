#include "animal.h"
#include "cow.h"
#include <vector>

int main() {
    vector<Animal*> cows(3);

    // Get all of the needed information from keyboard input
    for (int i = 0; i < 3; ++i) {
        float weight;
        string name;
        char gender;
        string color_desc;
        string breed;
        bool is_spayed_neutered;
        string id;
        string comments;
        char response;

        cout << "Enter information for cow " << (i + 1) << ":" << endl;

        // Name
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        
        // Gender
        do {
            cout << "Gender (M/F): ";
            cin >> response;
            if (response == 'M' || response == 'm') {
                gender = 'm';
                break;
            }
            else if (response == 'F' || response == 'f') {
                gender = 'f';
                break;
            }
            else {
                cout << "Please try again. Valid responses are M or F." << endl;
            }
        } while (true);
        
        // Weight
        cout << "Weight: ";
        cin >> weight;

        // Color Description
        cout << "Color Description: ";
        cin.ignore();
        getline(cin, color_desc);
        
        // Breed
        cout << "Breed: ";
        getline(cin, breed);
        
        // Spayed/Neutered
        do {
            cout << "Spayed/Neutered (as Y or N): ";
            cin >> response;
            if (response == 'Y' || response == 'y') {
                is_spayed_neutered = true;
                break;
            }
            else if (response == 'N' || response == 'n') {
                is_spayed_neutered = false;
                break;
            }
            else {
                cout << "Please try again. Valid responses are Y or N." << endl;
            }
        } while (true);
        
        // ID
        cout << "ID: ";
        cin.ignore();
        getline(cin, id);
        
        // Comments
        cout << "Comments: ";
        getline(cin, comments);
        
        // Save all of the above info to a new Cow instance in the vector
        cows[i] = new Cow(weight, name, gender, color_desc, breed, is_spayed_neutered, id, comments);
    }
    
    cout << "\n-------------------------------------------------------\n\n";
    
    // Print the information for each Cow
    for (int i = 0; i < 3; ++i) {
	    cout << "Information for Cow " << i + 1 << ": " << endl;
        cows.at(i)->Display();
    }

    // Clean up all allocated space
    for (int i = 0; i < 3; ++i) {
        delete cows.at(i);
    }

    return 0;
}