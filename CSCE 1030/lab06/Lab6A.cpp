#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int new_chars[5];
    for (int i = 0; i < 5; i++) {
        new_chars[i] = rand() % 26 + 65;
    }
    for (int i = 0; i < 5; i++) {
        cout << static_cast<char>(new_chars[i]);
    }
    cout << endl;
    return 0;
}