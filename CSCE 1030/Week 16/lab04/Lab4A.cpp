#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	// Declare variables/extras
	char a, b;
	int c, d;
	double e, f;
	cout.precision(4);
	cout.setf(ios::fixed);

	// Get characters
	printf("\nHello! Please enter two characters: ");
	scanf("%c %c", &a, &b);
	
	// Get integers
	printf("Now enter two numbers: ");
	scanf("%d %d", &c, &d);
	
	// Get doubles
	printf("Finally, enter two decimals: ");
	scanf("%lf %lf", &e, &f);
	
	// Print all variables
	printf("You entered: \na: %c\nb: %c\nc: %d\nd: %d\ne: %.6lf\nf: %.6e\n\n", a, b, c, d, e, f);
	return 0;
}
