#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 10;

int minArray(const int array[]) {
    int min = array[0];
    for (int i = 1; i < SIZE; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int main() {
    int array[SIZE];
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 51 + 50;
        cout << "Random #" << i + 1 << ": " << array[i] << endl;
    }
    cout << "Minimum: " << minArray(array) << endl;
    return 0;
}