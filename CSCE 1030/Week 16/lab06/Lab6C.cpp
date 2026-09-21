#include <iostream>

using namespace std;

int main() {
    const int SIZE = 8;
    char arr[] = {'b', 'f', 'a', 'z', 'm', 'g', 'q', 't'};
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[i] < arr[j]) {
                char temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
	cout << endl;
}
