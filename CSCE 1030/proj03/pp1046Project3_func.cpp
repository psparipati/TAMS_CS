#include "pp1046Project3_header.h"

void addStudent() {
    Student student;
    string lname, fname;
    int id, num_tests;
    cout << "Enter last name of the student:";
    cin >> lname;
    cout << "Enter first name of the student:";
    cin >> fname;
    cout << "Enter student ID:";
    cin >> id;
    cout << "How many tests did the student take?";
    cin >> num_tests;
    student.test_scores = new int[num_tests];
    for (int i = 0; i < num_tests; ++i) {
        cout << "Enter score #" << (i + 1) << ":";
        cin >> student.test_scores[i];
    }
    student.name = lname + "," + fname;
    student.id = id;
    student.num_tests = num_tests;
    ofstream fout("student.dat", ios::app);
    if (!fout.is_open()) {
        cout << "File error." << endl;
        delete[] student.test_scores;
        return;
    }
    fout << student.name << "," << student.id << "," << student.num_tests;
    for (int i = 0; i < num_tests; ++i) {
        fout << "," << student.test_scores[i];
    }
	fout << ",\n";
    delete[] student.test_scores;
    fout.close();
}

void removeStudent(int targetID) {
    int numStudents = getNumber();
    Student *students = new Student[numStudents];
    ifstream fin("student.dat");
    if (!fin.is_open()) {
        cout << "File error." << endl;
        delete[] students;
        return;
    }
    int index = 0;
    loadStudentsFromFile(fin, students, index);
    fin.close();
    bool found = false;
    ofstream fout("student.dat", ios::trunc);
    if (!fout.is_open()) {
        cout << "File error." << endl;
        for (int i = 0; i < index; ++i) delete[] students[i].test_scores;
        delete[] students;
        return;
    }
    for (int i = 0; i < index; ++i) {
        if (students[i].id != targetID) {
            fout << students[i].name << "," << students[i].id << "," << students[i].num_tests;
            for (int j = 0; j < students[i].num_tests; ++j) fout << "," << students[i].test_scores[j];
            fout << ",\n";
        }
		else found = true;
        delete[] students[i].test_scores;
    }
    delete[] students;
    fout.close();
    if (!found) {
        cout << "Student does not exist." << endl;
    }
}

void display() {
    ifstream fin;
    fin.open("student.dat");
    if (!fin.is_open()) {
        cout << "File error." << endl;
        return;
    }
    Student *students = new Student[getNumber()];
    int index = 0;
    loadStudentsFromFile(fin, students, index);
    fin.close();
	cout.setf(ios::right);
    for (int i = 0; i < index; ++i) {
        cout << setw(30) << students[i].name << setw(15) << students[i].id;
        for (int j = 0; j < students[i].num_tests; ++j) cout << setw(5) << students[i].test_scores[j];
        cout << endl;
    }
	cout.unsetf(ios::right);
    for (int i = 0; i < index; ++i) delete[] students[i].test_scores;
    delete[] students;
    cout << endl;
}

void search(int targetID) {
    ifstream fin;
    fin.open("student.dat");
    if (!fin.is_open()) {
        cout << "File error." << endl;
        return;
    }
    Student *students = new Student[getNumber()];
    int index = 0;
    loadStudentsFromFile(fin, students, index);
    fin.close();
    bool found = false;
    cout.setf(ios::left);
    for (int i = 0; i < index; ++i) {
        if (students[i].id == targetID) {
            cout << endl;
            cout << setw(30) << students[i].name << setw(15) << students[i].id;
            for (int j = 0; j < students[i].num_tests; ++j) cout << setw(5) << students[i].test_scores[j];
            cout << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Student does not exist." << endl;
    for (int i = 0; i < index; ++i) delete[] students[i].test_scores;
    delete[] students;
}

void exportResults() {
    ifstream fin;
    fin.open("student.dat");
    if (!fin.is_open()) {
        cout << "File error." << endl;
        return;
    }
    Student *students = new Student[getNumber()];
    int index = 0;
    loadStudentsFromFile(fin, students, index);
    fin.close();
    ofstream fout;
    fout.open("averages.dat", ios::trunc);
    if (!fout.is_open()) {
        cout << "File error." << endl;
        return;
    }
    fout.setf(ios::left);
    for (int i = 0; i < index; ++i) {
        int sum = 0;
        for (int j = 0; j < students[i].num_tests; ++j) sum += students[i].test_scores[j];
        sum -= findMinimum(students[i].test_scores, students[i].num_tests);
        students[i].average = static_cast<double>(sum) / ((students[i].num_tests < 5) ? students[i].num_tests : (students[i].num_tests - 1));
        fout << setw(15) << students[i].id << fixed << setprecision(1) << students[i].average << endl;
    }
    fout.close();
	for (int i = 0; i < index; ++i) delete[] students[i].test_scores;
    delete[] students;
}

int findMinimum(int *array, int size) {
    if (size < 5) return 0;
    int min = array[0];
    for (int i = 1; i < size; ++i) if (array[i] < min) min = array[i];
    return min;
}

void loadStudentsFromFile(ifstream &fin, Student *students, int &index) {
    string line;
    index = 0;
    while (getline(fin, line)) {
        if (line.empty() || line == "\n") continue;
        stringstream ss(line);
        string lname, fname, id, num_tests, score;
        if (!getline(ss, lname, ',')) continue;
        if (!getline(ss, fname, ',')) continue;
        if (!getline(ss, id, ',')) continue;
        if (!getline(ss, num_tests, ',')) continue;
        if (lname.empty() || fname.empty() || id.empty() || num_tests.empty()) continue;
        students[index].name = lname + "," + fname;
        students[index].id = stoi(id);
        students[index].num_tests = stoi(num_tests);
        students[index].test_scores = new int[students[index].num_tests];
        for (int i = 0; i < students[index].num_tests; ++i) {
            if (getline(ss, score, ',')) students[index].test_scores[i] = stoi(score);
            else students[index].test_scores[i] = 0;
        }
        index++;
    }
}