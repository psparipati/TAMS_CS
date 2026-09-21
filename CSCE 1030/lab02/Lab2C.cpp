#include <iostream>
using namespace std;

int main()
{
	//Initial Declarations
	float r, h;
	float pi = 3.14159;

	//Inputs from User
	cout << "Enter the radius of the cylinder: "; cin >> r;
	cout << "Enter the height of the cylinder: "; cin >> h
	
	//Calculations
	float surface_area = 2 * pi * r * (r + h);

	//Display Final Result
	cout << "The surface area of the cylinder is: " << surface_area << endl;
}
