#include <iostream>
#include <cctype>

using namespace std;

int main() {
    //Declare variables
    enum Operation {MULTIPLY='M', DIFFERENCE='D', ADD='A'};
    int result, num1, num2;
    Operation my_operation;
    char choice;
    bool quit = false;

    //Get user input
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    //Mechanism to choose operation
    do {
	cout << "Enter operation (M)ultiply, (D)ifference, (A)dd: ";
        cin >> choice;
        my_operation = static_cast<Operation>(toupper(choice));
        switch (my_operation) {
            case MULTIPLY:
                result = num1 * num2;
                cout << "Product: " << result << endl;
                quit = true;
                break;
            case DIFFERENCE:
                result = num1 - num2;
                cout << "Difference: " << result << endl;
                quit = true;
                break;
            case ADD:
                result = num1 + num2;
                cout << "Sum: " << result << endl;
                quit = true;
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (!quit);

    return 0;
}
