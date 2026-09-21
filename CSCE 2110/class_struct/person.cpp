#include "person.h"

Person::Person(string name, int age, int height, string address, char gender, date dateOfBirth) {
    this->name = name;
    this->age = age;
    this->height = height;
    this->address = address;
    this->gender = gender;
    this->dateOfBirth = dateOfBirth;
    cout << "Person " << name << " created." << endl;
}

Person::~Person() {
    cout << "Person " << name << " destroyed." << endl;
}

string Person::get_name() const {
    return name;
}

int Person::get_age() const {
    return age;
}

int Person::get_height() const {
    return height;
}

string Person::get_address() const {
    return address;
}

char Person::get_gender() const {
    return gender;
}

date Person::get_dateOfBirth() const {
    return dateOfBirth;
}

void Person::set_name(const string& name) {
    this->name = name;
}

void Person::set_age(int age) {
    this->age = age;
}

void Person::set_height(int height) {
    this->height = height;
}

void Person::set_address(const string& address) {
    this->address = address;
}

void Person::set_gender(char gender) {
    this->gender = gender;
}

void Person::set_dateOfBirth(const date& dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

void Person::display_name() const {
    cout << "Name: " << name << endl;
}

void Person::display_age() const {
    cout << "Age: " << age << endl;
}

void Person::display_height() const {
    cout << "Height: " << height << " inches" << endl;
}

void Person::display_address() const {
    cout << "Address: " << address << endl;
}

void Person::display_gender() const {
    cout << "Gender: " << gender << endl;
}

void Person::display_dateOfBirth() const {
    cout << "Date of Birth: " << dateOfBirth.month << "/" << dateOfBirth.day << "/" << dateOfBirth.year << endl;
}