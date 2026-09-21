#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	//Declare variables
	cout.precision(3);
	cout.setf(ios::fixed);
	const int acceleration = 32;
	float time, distance;
	
	//Extract time
	printf("Enter the amount of time the object was in the air: ");
	cin >> time;

	//Calculate and display distance
	distance = (acceleration * pow(time, 2.0)) / 2;
	cout << "From what we have, the distance your object might have travelled is " << distance <<" feet.\n";
	return 0;
}
