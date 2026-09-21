#include <iostream>
using namespace std;

int main()
{
    // Variable Initializations
	int var1;
	char var2;
	float var3, var4;
	
    // Variable Declarations
    var1 = 40;
	var2 = 'P';
	var3 = 4.6;

    // Calculation and Display
	var4 = var3 + var2 % var1;
	cout << var4 << endl;
	return 0;
}
