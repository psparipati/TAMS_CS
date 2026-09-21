#include "person.h"

class Student : public Person {
    public:
        // Constructor
        Student(string name, int age, int height, string address, char gender, date dateOfBirth, float gpa, int studentID);
        // Getters for Student attributes
        float get_gpa() const {return gpa;};
        int get_studentID() const {return studentID;};
        // Setters for Student attributes
        void set_gpa(float gpa) {this->gpa = gpa;};
        void set_studentID(int studentID) {this->studentID = studentID;};
        // Display for Student attributes
        void display_gpa() const {
            cout << "GPA: " << gpa << endl;
        };
        void display_studentID() const {
            cout << "Student ID: " << studentID << endl;
        };
    private:
        float gpa = 0.0;
        int studentID = 0;
};