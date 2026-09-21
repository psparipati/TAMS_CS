#include <iostream>

using namespace std;

int main() {
    const int SIZE = 12;
    int sum_height = 0;
    int counter = 0;
    int height[SIZE];
    int above_average[SIZE];
    double average_height = 0;
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter height " << i + 1 << ": ";
        cin >> height[i];
        sum_height += height[i];
    }
    average_height = (double)sum_height / SIZE;
    for (int i = 0; i < SIZE; i++) {
        if (height[i] > average_height) {
            above_average[counter] = height[i];
	    counter++;
        }
    }
    for (int i = 0; i < SIZE; i++) {
	cout << "Height of student " << i + 1 << ": ";
        cout << height[i] << endl;
    }
    cout << "Average height: " << average_height << endl;
    cout << "Above Average Heights: " << endl;
    for (int i = 0; i < counter; i++) {
	cout << above_average[i] << endl;
    }
    return 0;
}
