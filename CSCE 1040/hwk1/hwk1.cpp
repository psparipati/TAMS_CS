#include "hwk1.h"

int main() {
    header();
    int counter = 0;
    Student* students = new Student[25];
    menu(students, counter);
    delete[] students; // Free memory
    return 0;
}