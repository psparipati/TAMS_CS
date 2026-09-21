#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void mySort(double arr[], const int SIZE) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            if (arr[i] > arr[j]) {
                double temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main() {
    ifstream unsorted("unsorted.dat");
	if (!unsorted.is_open()) {
		cerr << "Failed to open unsorted.dat" << endl;
		exit(1);
	}
	ofstream sorted("sorted.dat");
	if (!sorted.is_open()) {
		cerr << "Failed to open sorted.dat" << endl;
		exit(1);
	}
	double arr[30];
	int count = 0;
	while (unsorted >> arr[count]) {
		++count;
	}
	mySort(arr, count);
	for (int i = 0; i < count; ++i) {
		sorted << arr[i] << endl;
	}
    return 0;
}