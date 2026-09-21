#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	// Declare variables
	double numSales, storeBonus;
	int numExperiences;

	// Read sales
	printf("\nEnter the amount of sales: ");
	scanf("%lf", &numSales);

	// Read experience
	printf("\nEnter the years of experience: ");
	scanf("%d", &numExperiences);

	// Calculations
	storeBonus = 100.00;
	storeBonus += (numExperiences >= 10) ? (numSales * .03) : (numSales * .02);
	storeBonus += (numSales <= 100000.00) ? (0) : (500);

	// Display result
	printf("\nSales Bonus: %.2lf\n\n", storeBonus);

	return 0;
}
