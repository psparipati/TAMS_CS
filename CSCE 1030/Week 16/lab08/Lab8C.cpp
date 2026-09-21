#include <iostream>
using namespace std;

const int ROWS = 10, COLS = 6;

void computeMaximum(int array2D[][COLS], int rows, int maximums[]) {
    for (int i = 0; i < rows; i++) {
        int max = array2D[i][0];
        for (int j = 1; j < COLS; j++) {
            if (array2D[i][j] > max) {
                max = array2D[i][j];
            }
        }
        maximums[i] = max;
    }
}

void showArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array2D[ROWS][COLS], maximums[ROWS], numStudents;
    cout << "How many students in the class? "; cin >> numStudents;
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "Enter QUIZ #" << j + 1 <<" for STUDENT #" << i + 1 << ": ";
            cin >> array2D[i][j];
        }
    }
	cout << endl;
    computeMaximum(array2D, numStudents, maximums);
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }
	cout << endl;
	cout << "The maximum grades: " << endl;
    showArray(maximums, numStudents);
}