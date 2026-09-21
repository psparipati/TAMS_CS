#include "snake.h"

int main() {
	Snake* snakes = new Snake[4];
	string nbreed;
	float nweight;
	string nname;
	char ngender;
	int nlength;
	string foods[4];
	string ncolor;
	string ncomments;

	for (int i = 0; i < 4; i++) {
		cout << "What is the snake's name? "; getline(cin, nname);
		cout << "What breed is the snake? "; getline(cin, nbreed);
		cout << "How much does it weigh (number only please, decimals allowed)? "; cin >> nweight;
		cout << "How long is it (in inches)? "; cin >> nlength;
		cout << "Is it male (m) or female (f)? "; cin >> ngender;
		cout << "What color is it? (Describe in as much detail as needed.) "; getline(cin, ncolor); cin.ignore();
		cout << "What other things do we need to know? "; getline(cin, ncomments); cin.ignore();
		cout << "What is the snake's favorite food? "; cin >> foods[i];
		snakes[i] = Snake(nbreed, nweight, nname, ngender, nlength, foods[i], ncolor, ncomments);
	}

	for (int i = 0; i < 4; i++) {
		snakes[i].PrintInfo();
	}

	for (int i = 0; i < 4; i++) {
		delete snakes[i].GetFood();
	}

	delete[] snakes;
	
	return 0;
}