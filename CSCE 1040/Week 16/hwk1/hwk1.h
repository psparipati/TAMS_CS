#ifndef HWK1_H
#define HWK1_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Student
{
    int id;
    string first;
    string last;
    int exam1;
    int exam2;
    int exam3;
    float average;
};

float average(int exam1, int exam2, int exam3);
void header();
void menu(Student* students, int& counter);
void displayStudents(const Student* students, int counter);
void addStudent(Student* students, int& counter);
void updateStudent(Student* students, int counter);
void computeMean(const Student* students, int counter);
void computeMin(const Student* students, int counter);
void computeMax(const Student* students, int counter);

#endif // HWK1_H