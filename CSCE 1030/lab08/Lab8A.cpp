#include <iostream>
#include <cstdlib>
using namespace std;

int getRandom() {
    return rand() % 100 + 1;
}

void compare(int guess) {
    int number = getRandom();
    if (guess == number) {
        cout << "You guessed the number!" << endl;
    } else if (guess < number) {
        cout << "Random number was " << number << ". Your guess was lower." << endl;
    } else {
        cout << "Random number was " << number << ". Your guess was higher." << endl;
    }
}

int main() {
    int guess;
    cout << "Enter your guess: ";
    cin >> guess;
    compare(guess);
    return 0;
}