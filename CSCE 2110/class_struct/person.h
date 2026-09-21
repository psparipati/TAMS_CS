#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

typedef struct {
    int day;
    int month;
    int year;
} date;

class Person {
    public:
        // Constructor
        Person(string name, int age, int height, string address, char gender, date dateOfBirth);
        // Destructor
        ~Person();
        // Getters for every attribute
        string get_name() const;
        int get_age() const;
        int get_height() const;
        string get_address() const;
        char get_gender() const;
        date get_dateOfBirth() const;
        // Setters for every attribute
        void set_name(const string& name);
        void set_age(int age);
        void set_height(int height);
        void set_address(const string& address);
        void set_gender(char gender);
        void set_dateOfBirth(const date& dateOfBirth);
        // Display for every attribute
        void display_name() const;
        void display_age() const;
        void display_height() const;
        void display_address() const;
        void display_gender() const;
        void display_dateOfBirth() const;
    private:
        string name = "";
        int age = 0;
        int height = 0; // recorded in inches
        string address = "";
        char gender = ' '; // 'M' for male, 'F' for female
        date dateOfBirth = {0,0,0}; // Custom date struct for date of birth
};

#endif // PERSON_H