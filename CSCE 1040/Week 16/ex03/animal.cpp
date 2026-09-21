#include "animal.h"

Animal::Animal() : weight(0.0), name(""), gender('m'), color_desc("") {}

Animal::Animal(float weight, const string& name, char gender, const string& color_desc)
    : weight(weight), name(name), gender(gender), color_desc(color_desc) {}

float Animal::GetWeight() const {
    return weight;
}

void Animal::SetWeight(float weight) {
    this->weight = weight;
}

string Animal::GetName() const {
    return name;
}

void Animal::SetName(const string& name) {
    this->name = name;
}

char Animal::GetGender() const {
    return gender;
}

void Animal::SetGender(char gender) {
    this->gender = gender;
}

string Animal::GetColorDesc() const {
    return color_desc;
}

void Animal::SetColorDesc(const string& color_desc) {
    this->color_desc = color_desc;
}

void Animal::Display() const {
    cout << "Name: " << name << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Gender: " << (gender == 'm' ? "Male" : "Female") << endl;
    cout << "Color Description: " << color_desc << endl;
}