#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    // Declare variables
    string name;
    double salary, bonus;
    int rate;
    cout.precision(2);
    cout.setf(ios::fixed);

    // Get name
    printf("Enter your name: ");
    getline(cin, name);

    // Get salary
    cout << "Hello, " << name << ". Please enter your salary: ";
    cin >> salary;

    // Get bonus rate
    printf("Thank you. Please enter the bonus rate: ");
    cin >> rate;

    // Calculate bonus
    bonus = salary * (static_cast<double>(rate) / 100);

    // Output bonus
    cout << name << " earned a bonus of $" << bonus << endl;
    return 0;
}
