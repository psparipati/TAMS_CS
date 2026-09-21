#include <iostream>
#include <fstream>

using namespace std;

double computeMin(double* arr, int size) {
    double min = arr[0];
    for (int i = 1; i < size; i++) if (arr[i] < min) min = arr[i];
    return min;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    double* arr = new double[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> arr[i];
    }
    double minimum = computeMin(arr, size);
    ofstream outmin("outmin.txt");
    if (!outmin.is_open()) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }
    outmin << "The minimum value is " << minimum << "." << endl;
    outmin.close();
    free(arr);
    return 0;
}