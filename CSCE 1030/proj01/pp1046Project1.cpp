#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main() {
    // Header information for the program.
    cout << "\nStudent Name: Prabhav Sai Paripati\nStudent EUID: pp1046\nCourse Number: CSCE 1030 - Computer Science I\nEmail: PrabhavParipati@my.unt.edu\n(My) Department: Texas Academy of Mathematics and Science\n" << endl;
    
    // Initial variables.
    int points = 100;
    enum operands {ADD, SUBTRACT, DISPLAY, GIVEUP, EXIT};
	
	// Control how we get, parse, and format the username.
    string username;
	bool goodName = false;
    while (!goodName) {
		// Extract username from input.
        cout << "Enter a username: ";
        getline(cin, username);
		// The iteration doesn't break immediately because we add this statement.
        goodName = true;
        for (int i = 0; i < username.length(); i++) {
			// Make sure that everything is space or alphabet, otherwise, break out of the for loop and go again.
            if ((isalpha(username[i])) || (isspace(username[i]))) {
                continue;
            }
            else {
                cout << "You can only have letters or spaces in your username. Please try again.\n" << endl;
                goodName = false;
                break;
            }
        }
    }
	// Reformat the username.
    bool capitalize = true;
    for (int i = 0; i < username.length(); i++) {
        if (isspace(username[i])) {
            capitalize = true;
        }
		else if (capitalize) {
            username[i] = toupper(username[i]);
            capitalize = false;
        }
		else {
            username[i] = tolower(username[i]);
        }
    }
	
	// Welcome the player to the game.
    cout << "Welcome " << username << "!\n";

    // This boolean controls whether the game is still occurring or not, and the loop uses this to determine whether to continue or not.
    bool isIn = true;
	// This boolean controls whether we need to regenerate the numbers.
	bool regenNum = true;
    while (isIn) {
        // Basic integers to control what the user is doing and what they have inputted.
        int choice, guess;
		int rand1, rand2;
        
        // Reusable boolean to control whether you want to play again or exit.
        bool innerChoice = true;
		
		// Logic statement to control whether we need to regenerate the numbers in the new iteration.
		if (regenNum) {
			// Generating fresh numbers every iteration.
			srand(time(NULL));
			do {
				rand1 = rand() % 51 + 100;
				rand2 = rand() % 51 + 100;
			} while (rand1 < rand2);
		}

        // Main menu for the game.
        cout << "\n1. ADD\n2. SUBTRACT\n3. DISPLAY\n4. GIVE UP\n5. EXIT\n";
        cout << "\nEnter your choice (number next to choice): ";
        cin >> choice;
		
		// Define these constants outside so that if the player switches games, we can easily catch up to them.
		int radd = rand1 + rand2;
		int rsub = rand1 - rand2;
		
        switch (static_cast<operands>(choice - 1)) {
            case ADD:
				// Get guess from user input.
                cout << "I have two random numbers, guess their sum.\n";                
				cout << "\nEnter your guess: ";
				cin >> guess;
				// We can't judge whether they are correct, only if they are pretty close to the answer.
				if ((guess > (radd - 5)) && (guess < (radd + 5))) {
					cout << "You are either correct, or pretty close. (I'm not telling you which one.)\n";
					points += 5;
					// This allows the player to generate new numbers and restart the game.
					cout << "Go again? (1 for yes, 0 for no): ";
					cin >> innerChoice;
					if (!innerChoice) {
						// The loop will end once the break statement is executed.
						cout << "You have ended with " << points << " points.\n";
						isIn = false;
					}
					else {
						regenNum = true;
					}
				}
				else {
					// Force the player to either guess again or put another operation.
					points -= 1;
					cout << "You are nowhere near the correct answer.\nYou now have " << points << " points." << endl;
				}
                break;
            case SUBTRACT:
				// Get guess from user input.
                cout << "I have two random numbers, guess their difference." << endl;
                cout << "\nEnter your guess: ";
				cin >> guess;
				if ((guess > (rsub - 5)) && (guess < (rsub + 5))) {
					cout << "You are either correct, or pretty close. (I'm not telling you which one.)" << endl;
					points += 5;
					// This allows the player to generate new numbers and restart the game.
					cout << "Go again? (1 for yes, 0 for no): ";
					cin >> innerChoice;
					if (!innerChoice) {
						// The loop will end once the break statement is executed.
						cout << "You have ended with " << points << " points.\n";
						isIn = false;
					}
					else {
						regenNum = true;
					}
				}
				else {
					// Force the player to either guess again or put another operation.
					points -= 1;
					cout << "You are nowhere near the correct answer.\nYou now have " << points << " points." << endl;
				}
                break;
            case DISPLAY:
				// We force the player to lose three points for asking for a hint, but they will only know one number in this iteration.
                cout << "This is one of the numbers (" << rand1 <<"), but you will lose 3 points for getting a hint." << endl;
                points -= 3;
                cout << "You now have " << points << " points." << endl;
				regenNum = false;
                break;
            case GIVEUP:
				// Display the numbers that were used.
                cout << "The two numbers were " << rand1 << " and " << rand2 << "." << endl;
                cout << "You now have " << points << " points.\n\nGo again? (1 for yes, 0 for no): ";
                cin >> innerChoice;
                if (innerChoice) {
					// The game will restart once the statement is executed.
					points = 100;
					regenNum = true;
                    continue;
                }
                else {
					// The loop will end once the break statement is executed.
                    isIn = false;
                }
                break;
            case EXIT:
				// The loop will end once the break statement is executed.
                cout << "You have ended with " << points << " points." << endl;
                isIn = false;
                break;
			default:
				// Force the player to enter a correct decision because they didn't.
				cout << "You weren't supposed to do that.\n" << endl;
				regenNum = false;
				break;
        }
    }
	
	// Thank the player for playing the game.
    cout << "Thank you for playing, " << username << "!\n" << endl;

    return 0;
}