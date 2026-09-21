#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(){
	char first, last;
	srand(time(NULL));
	first = (rand() % 25) + 65;
	last = (rand() % 25) + 65;
	cout << "Randomly generated initials: " << first << last << endl;
	return 0;
}
