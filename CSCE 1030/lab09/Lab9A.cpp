#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    ifstream data("data.dat");
    ofstream average("average.dat");
    if (!data.is_open()) {
        cout << "Error opening data file." << endl;
        exit(EXIT_FAILURE);
    }
    if (!average.is_open()) {
        cout << "Error opening average file." << endl;
        exit(EXIT_FAILURE);
    }
    int a, b, c;
    while (!data.eof()) {
        data >> a >> b >> c;
        double avg = (a + b + c) / 3.0;
        average << fixed << setprecision(2) << avg << endl;
    }
    return 0;
}
