#include "hwk1.h"

float average(int exam1, int exam2, int exam3) {
    return (exam1 + exam2 + exam3) / 3.0f;
}

void header() {
    cout << "+-------------------------------------------------------+\n";
    cout << "|         TAMS Computer Science and Engineering         |\n";
    cout << "|            CSCE 1040: Computer Science II             |\n";
    cout << "|    Prabhav Sai Paripati (pp1046) pp1046@my.unt.edu    |\n";
    cout << "+-------------------------------------------------------+\n";
}

void menu(Student* students, int& counter) {
    int choice;
    while (true) {
        cout << "\n";
        cout << "************************** Menu *************************\n";
        cout << "| 1. Display list of students' information              |\n";
        cout << "| 2. Add student information                            |\n";
        cout << "| 3. Update student information                         |\n";
        cout << "| 4. Compute mean of list of students exams             |\n";
        cout << "| 5. Compute minimum of the mean of students exams      |\n";
        cout << "| 6. Compute maximum of the mean of students exams      |\n";
        cout << "| 7. Exit                                               |\n";
        cout << "*********************************************************\n";
        cout << ">> "; cin >> choice;
        switch (choice) {
            case 1:
                displayStudents(students, counter);
                break;
            case 2:
                addStudent(students, counter);
                break;
            case 3:
                updateStudent(students, counter);
                break;
            case 4:
                computeMean(students, counter);
                break;
            case 5:
                computeMin(students, counter);
                break;
            case 6:
                computeMax(students, counter);
                break;
            case 7:
                cout << "Thank you for using this program. Goodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void addStudent(Student* students, int& counter) {
    if (counter >= 25) {
        cout << "Student list is full. Cannot add more students.\n";
        return;
    }
    cout << "Enter student's information\n";
    cout << "ID: "; cin >> students[counter].id;
    cout << "First Name: "; cin >> students[counter].first;
    cout << "Last Name: "; cin >> students[counter].last;
    cout << "Exam 1 Score: "; cin >> students[counter].exam1;
    cout << "Exam 2 Score: "; cin >> students[counter].exam2;
    cout << "Exam 3 Score: "; cin >> students[counter].exam3;
    students[counter].average = average(students[counter].exam1, students[counter].exam2, students[counter].exam3);
    cout << "New student with ID " << students[counter].id << " added.\n";
    counter++;
}

void displayStudents(const Student* students, int counter) {
    if (counter == 0) cout << "Empty list of students.\n";
    else {
        cout << "|************************ Students Information **************************|\n";
        cout << "|ID        First Name     Last Name      Exam1    Exam2    Exam3     Mean|\n";
        cout << "|________________________________________________________________________|\n";
        for (int i = 0; i < counter; ++i) {
            cout << "|" << left << setw(10) << students[i].id
                 << left << setw(15) << students[i].first
                 << left << setw(17) << students[i].last
                 << right << setw(3) << students[i].exam1
                 << right << setw(9) << students[i].exam2
                 << right << setw(9) << students[i].exam3
                 << right << setprecision(2) << fixed << setw(9) << students[i].average << "|\n";
        }
        cout << "|************************************************************************|\n";
    }
}

void updateStudent(Student* students, int counter) {
    if (counter == 0) {
        cout << "Empty list of students.\n";
        return;
    }
    int targetId; cout << "Please enter student ID: "; cin >> targetId;
    for (int i = 0; i < counter; ++i) {
        if (students[i].id == targetId) {
            cout << "Update student's information:\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "First Name: "; cin >> students[i].first;
            cout << "Last Name: "; cin >> students[i].last;
            cout << "Exam 1 Score: "; cin >> students[i].exam1;
            cout << "Exam 2 Score: "; cin >> students[i].exam2;
            cout << "Exam 3 Score: "; cin >> students[i].exam3;
            students[i].average = average(students[i].exam1, students[i].exam2, students[i].exam3);
            cout << "Student information with id " << students[i].id << " updated.\n";
            return;
        }
    }
    cout << "Student with ID " << targetId << " not found.\n";
}

void computeMean(const Student* students, int counter) {
    if (counter == 0) {
        cout << "Empty list of students.\n";
        return;
    }
    float total = 0.0f;
    for (int i = 0; i < counter; ++i) {
        total += students[i].average;
    }
    cout << "Mean of the exams: " << fixed << setprecision(2) << (total / counter) << "\n";
}

void computeMin(const Student* students, int counter) {
    if (counter == 0) {
        cout << "Empty list of students.\n";
        return;
    }
    float minAvg = students[0].average;
    for (int i = 1; i < counter; ++i) {
        if (students[i].average < minAvg) {
            minAvg = students[i].average;
        }
    }
    cout << "Minimum of the mean of the exams: " << fixed << setprecision(2) << minAvg << "\n";
}

void computeMax(const Student* students, int counter) {
    if (counter == 0) {
        cout << "Empty list of students.\n";
        return;
    }
    float maxAvg = students[0].average;
    for (int i = 1; i < counter; ++i) {
        if (students[i].average > maxAvg) {
            maxAvg = students[i].average;
        }
    }
    cout << "Maximum of the mean of the exams: " << fixed << setprecision(2) << maxAvg << "\n";
}