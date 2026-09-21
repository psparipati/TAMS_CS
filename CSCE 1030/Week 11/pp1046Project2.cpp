#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

enum option {MATCH = 1, DISPLAY, GIVEUP, EXIT};
const int SIZE = 4;

string getName() {
    string username;
    cout << "Welcome to the Memory Game!" << endl;
    bool goodName = false;
    while (!goodName) {
        cout << "Enter a username: ";
        getline(cin, username);
        goodName = true;
        for (int i = 0; i < username.length(); i++) {
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
    return username;
}

int genRandomIndex() {
    return rand() % SIZE;
}

void shuffle(int cards[][SIZE]) {
    int x1, x2, y1, y2, temp;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            x1 = genRandomIndex();
            y1 = genRandomIndex();
            x2 = genRandomIndex();
            y2 = genRandomIndex();
            temp = cards[x1][y1];
            cards[x1][y1] = cards[x2][y2];
            cards[x2][y2] = temp;
        }
    }
}

void initialize(int cards[][SIZE], int status[][SIZE]) {
    int value = 1;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cards[i][j] = value;
            if ((i * SIZE + j + 1) % 2 == 0) {
                ++value;
            }
            status[i][j] = 0;
        }
    }
    shuffle(cards);
}

void showCards(int cards[][SIZE], int status[][SIZE], bool showReal = false) {
    cout << "    0    1    2    3\n  +------------------+" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << i << " | ";
        for (int j = 0; j < SIZE; ++j) {
            if (j == SIZE - 1) {
                if (showReal) {
                    cout << cards[i][j] << " |";
                    continue;
                }
                if (status[i][j] == 1) {
                    cout << cards[i][j] << " |";
                } else {
                    cout << "* |";
                }
            }
            else {
                if (showReal) {
                    cout << cards[i][j] << "    ";
                    continue;
                }
                if (status[i][j] == 1) {
                    cout << cards[i][j] << "    ";
                } else {
                    cout << "*    ";
                }
            }
        }
        cout << endl;
    }
    cout << "  +------------------+" << endl;
}

bool allFaceUp(int status[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (status[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool checkInputs(int x, int y, int faceup) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        return false;
    }
    if (faceup == 1) {
        return false;
    }
    return true;
}

void match(int cards[][SIZE], int status[][SIZE], int& points) {
    showCards(cards, status, false);
    int x1, y1, x2, y2;
    cout << "Your coordinates must be numbers from 0 to 3." << endl;
    cout << "Enter the coordinates of the first card (y x): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second card (y x): ";
    cin >> x2 >> y2;
    if (checkInputs(x1, y1, status[x1][y1]) && checkInputs(x2, y2, status[x2][y2])) {
        status[x1][y1] = 1;
        status[x2][y2] = 1;
        showCards(cards, status, false);
        if (cards[x1][y1] == cards[x2][y2]) {
            cout << "You found a match!" << endl;
            points += 5;
        }
        else {
            cout << "You got it wrong, I'll give you 5 seconds to remember this arrangement." << endl;
            for (int i = 5; i > 0; --i) {
                cout << i << endl;
                sleep(1);
            }
            system("clear");
            status[x1][y1] = 0;
            status[x2][y2] = 0;
            points -= 1;
        }
    } else {
        cout << "Invalid coordinates or card already face up. Try again." << endl;
        return;
    }
}

void display(int cards[][SIZE], int status[][SIZE], int& points) {
    if (points < 10) {
        cout << "Insfficient funds to recieve a hint." << endl;
        return;
    }
    int xi, yi, xt, yt;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (status[i][j] == 0) {
                xi = i;
                yi = j;
                break;
            }
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (cards[i][j] == cards[xi][yi] && (i != xi || j != yi)) {
                xt = i;
                yt = j;
                break;
            }
        }
    }
    status[xi][yi] = 1;
    status[xt][yt] = 1;
    showCards(cards, status, false);
    cout << "You have been given a hint!" << endl;
    points -= 10;
    return;
}

int main() {
    int points = 50;
    int cards[SIZE][SIZE], status[SIZE][SIZE];
    string name;
    bool contin = true;
	srand(time(NULL));
    initialize(cards, status);
    cout << "\nStudent Name: Prabhav Sai Paripati\nStudent EUID: pp1046\nCourse Number: CSCE 1030 - Computer Science I\nEmail: PrabhavParipati@my.unt.edu\n(My) Department: Texas Academy of Mathematics and Science\n" << endl;
    name = getName();
    cout << "Hello, " << name << "!\n" << endl;
    cout << "You have " << points << " points." << endl;
    do {
        cout << "\n1. Match" << endl;
        cout << "2. Display" << endl;
        cout << "3. Give up" << endl;
        cout << "4. Exit\n" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (static_cast<option>(choice)) {
            case MATCH:
                match(cards, status, points);
                break;
            case DISPLAY:
                display(cards, status, points);
                break;
            case GIVEUP:
                showCards(cards, status, true);
                cout << "You have ended with " << points << " points." << endl;
            case EXIT:
				contin = false;
                cout << "Thank you for playing! Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        if (allFaceUp(status)) {
            int playAgain;
            cout << "Congratulations! You have matched all the cards!" << endl;
            cout << "You have ended with " << points << " points." << endl;
            cout << "Would you like to play again? (1 for yes, 0 for no): ";
            cin >> playAgain;
            if (playAgain == 1) {
                points = 50;
                initialize(cards, status);
            } else {
                cout << "Thank you for playing! Goodbye!" << endl;
                return 0;
            }
        }
        cout << "You have " << points << " points." << endl;
    } while (points > -1 && contin);
    return 0;
}