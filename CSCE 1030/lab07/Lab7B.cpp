#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[101], str2[101];
    strcpy(str1, "We are completing Lab7 today.");
    cout << "Enter a string: "; cin.getline(str2, 101);
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 == len2) {
        cout << "The C-strings are the same length." << endl;
    }
    else {
        cout << "The C-strings are not the same length and must be different words." << endl;
        return 0;
    }
    if (strcmp(str1, str2) == 0) {
        cout << "The two C-strings are the same." << endl;
    }
    else {
        cout << "The two C-strings are NOT the same." << endl;
    }
}
