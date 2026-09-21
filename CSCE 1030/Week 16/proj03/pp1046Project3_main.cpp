#include "pp1046Project3_header.h"

/*
    For compilation, use this command: clear && cd /nfs/home/STUDENTS/pp1046/CSCE1030/proj03 && g++ pp1046Project3_main.cpp pp1046Project3_func.cpp getNumber.cpp -o student_management.exe
*/

int main() {
    int choice;
    do {
        cout << "1. Add\n2. Remove\n3. Display\n4. Search\n5. Results\n6. Quit\nEnter choice:";
        cin >> choice;

        switch (static_cast<options>(choice)) {
            case ADD:
                addStudent();
                break;
            case REMOVE: {
                int idToRemove;
                cout << "Enter ID of student to remove:";
                cin >> idToRemove;
                removeStudent(idToRemove);
                break;
            }
            case DISPLAY:
                display();
                break;
            case SEARCH: {
                int idToSearch;
                cout << "Enter ID of student to search for:";
                cin >> idToSearch;
                search(idToSearch);
                break;
            }
            case RESULTS:
                exportResults();
                cout << "Results exported to file.\n";
                break;
            case QUIT:
                cout << "Bye!!!" << endl;
                break;
            default:
                cout << "Incorrect choice. Please enter again.\n";
                cin.clear();
                cin.ignore(100, '\n');
        }
        cout << endl;
    } while (static_cast<options>(choice) != QUIT);
    return 0;
}