#include "dog.h"

Dog Input() {
    // Variables to assist input
    string breed;
    float weight;
    string name;
    char gender;
    bool is_spayed;
    string id;
    string color;
    string comments;
    
    // Grab Name (may be more than one word)
    cout << "Enter the dog's name: ";
    getline(cin, name);

    // Grab Breed (may be more than one word)
    cout << "Enter the dog's breed: ";
    getline(cin, breed);

    // Grab Dog's Weight
    cout << "Enter the dog's weight (number only, decimals allowed): ";
    cin >> weight;

    // Grab Gender using loop
    do {
        cout << "What is the dog's gender (M or F)?" << endl;
        cin >> gender;
        if (gender == 'M') gender = 'm';
        if (gender == 'F') gender = 'f';
        if (gender == 'm' || gender == 'f') {
            break;
        }
        cout << "Please try again." << endl;
    } while(true);

    // Find out whether dog has been spayed or neutered
    do {
        cout << "Has the dog been spayed or neutered (Y or N)?" << endl;
        char tmp;
        cin >> tmp;
        if (is_spayed == 'y' || is_spayed == 'Y') {
            is_spayed = true;
            break;
        }
        else if (is_spayed == 'n' || is_spayed == 'N') {
            is_spayed = false;
            break;
        }
        cout << "Please try again." << endl;
    } while(true);

    // Grab Dog's ID
    cout << "Enter the dog's id: ";
    cin >> id;

    // Grab Dog's Color (good chance it is more than one word)
    cout << "What is the dog's color? ";
    getline(cin, color);

    // Grab any comments
    cout << "Additional Comments: ";
    getline(cin, comments);

    return Dog(breed, weight, name, gender, is_spayed, id, color, comments);
}

bool compare(Dog& a, Dog& b) {
    return a.GetName() < b.GetName();
}

int main() {
    vector<Dog> dogs(5);
    
    // Greet the user
    cout << "Hello! Please enter the details for the dogs as requested." << endl;
    
    // Ask to input info for 5 dogs
    for (int i = 0; i != 5; i++) {
        cout << "Please enter the details for Dog " << i + 1 << ":" << endl;
        dogs.at(i) = Input();
    }
    
    // Sort dogs using name
    sort(dogs.begin(), dogs.end(), compare);

    // Display the info of every dog
    for (int i = 0; i != 5; i++) {
        cout << "Dog " << i + 1 << ": ";
        dogs.at(i).PrintInfo();
    }
    
    return 0;
}