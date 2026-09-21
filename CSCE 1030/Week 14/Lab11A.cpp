#include <iostream>

using namespace std;

void getGrades(int** grades, int number_of_students, double* average) {
	int number_of_test;
	for (int i = 0; i < number_of_students; i++) {
		cout << "How many tests for student #" << i + 1 << "?";
		cin >> number_of_test;
		grades[i] = new int[number_of_test];
		int sum = 0;
		cout << "Enter test scores:" << endl;
		for (int j = 0; j < number_of_test; j++) {
			cin >> grades[i][j];
			sum += grades[i][j];
		}
		average[i] = static_cast<double>(sum) / number_of_test;
	}
}

void dispAverage(double* average, int number_of_students) {
	for (int i = 0; i < number_of_students; i++) {
		cout << "Average for student #" << i + 1 << ": " << average[i] << endl;
	}
}

int main() {
	int number_of_students;
	int** grades;
	double* average;

	cout << "How many students?";
	cin >> number_of_students;

	grades = new int*[number_of_students];
	average = new double[number_of_students];

	getGrades(grades, number_of_students, average);
	dispAverage(average, number_of_students);

	for (int i = 0; i < number_of_students; i++) {
		delete[] grades[i];
	}
	delete[] grades;
	delete[] average;
}