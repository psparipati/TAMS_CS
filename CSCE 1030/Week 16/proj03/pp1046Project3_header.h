#ifndef PP1046PROJECT3_HEADER_H
#define PP1046PROJECT3_HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

const int TESTS = 5;

enum options {ADD = 1, REMOVE, DISPLAY, SEARCH, RESULTS, QUIT};

struct Student {
    string name;
    int id;
    int num_tests;
    int *test_scores;
    double average;
};

void addStudent();
void removeStudent(int targetID);
void display();
void search(int targetID);
void exportResults();
int findMinimum(int *array, int size);
int getNumber();
void loadStudentsFromFile(ifstream &fin, Student *students, int &index);

#endif // PP1046PROJECT3_HEADER_H