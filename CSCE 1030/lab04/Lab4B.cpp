#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int inputNum, randNum;
	cout << endl <<"Enter a number between 100 and 200: ";
	cin >> inputNum;
	srand(time(NULL));
	if ((inputNum >= 100) && (inputNum <= 200)) {
		randNum = (rand() % 101) + 100;
		printf("My number was %d.\n", randNum);
		if (inputNum > randNum) {
			cout << "Your number was larger than mine!\n\n";
		}
		else if (inputNum == randNum) {
			cout << "You guessed my number perfectly! How???\n\n";
		}
		else {
			cout << "Your number was smaller than mine!\n\n";
		}
	}
	else {
		printf("Number is outside of range.\n\n");
	}
	return 0;
}
