#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    string inputFileName, outputFileName;
    cout << "Enter the input file name: ";
    cin >> inputFileName;
    ifstream inFile(inputFileName.c_str());
    if (!inFile) {
        cerr << "Error opening input file." << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Enter the output file name: ";
    cin >> outputFileName;
    ofstream outFile(outputFileName.c_str());
    if (!outFile) {
        cerr << "Error opening output file." << endl;
        exit(EXIT_FAILURE);
    }
    char c;
    while (inFile.get(c)) outFile.put(c);
    inFile.close();
    outFile.close();
    return 0;
}
