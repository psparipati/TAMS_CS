#include <iostream>
using namespace std;

double compute_bonus(double base_salary, int experience);

int main() {
    double base_salary;
    int experience;
    cout << "Enter base salary: "; cin >> base_salary;
    cout << "Enter experience: "; cin >> experience;
    cout << "Bonus earned: $" << compute_bonus(base_salary, experience) << endl;
    return 0;
}

double compute_bonus(double base_salary, int experience) {
    double bonus;
    if (experience >= 10) {
        bonus = base_salary * 0.05;
    }
    else {
        bonus = base_salary * 0.03;
    }
    return bonus;
}
