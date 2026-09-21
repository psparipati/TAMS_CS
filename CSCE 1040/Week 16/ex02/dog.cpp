#include "dog.h"

// Default Constructor
Dog::Dog() {
    breed = "";
    weight = 0.0f;
    name = "";
    gender = ' ';
    is_spayed = false;
    id = "";
    color = "";
    comments = "";
}

// Full Constructor
Dog::Dog(string breed, float weight, string name, char gender, bool is_spayed, string id, string color, string comments) {
    this->breed = breed;
    this->weight = weight;
    this->name = name;
    this->gender = gender;
    this->is_spayed = is_spayed;
    this->id = id;
    this->color = color;
    this->comments = comments;
}

// Accessors
string Dog::GetBreed() {
    return breed;
}

float Dog::GetWeight() {
    return weight;
}

string Dog::GetName() {
    return name;
}

char Dog::GetGender() {
    return gender;
}

bool Dog::GetIs_Spayed() {
    return is_spayed;
}

string Dog::GetID() {
    return id;
}

string Dog::GetColor() {
    return color;
}

string Dog::GetComments() {
    return comments;
}

// Mutators
void Dog::SetBreed(string breed) {
    this->breed = breed;
}

void Dog::SetWeight(float weight) {
    this->weight = weight;
}

void Dog::SetName(string name) {
    this->name = name;
}

void Dog::SetGender(char gender) {
    this->gender = gender;
}

void Dog::SetIs_Spayed(bool is_spayed) {
    this->is_spayed = is_spayed;
}

void Dog::SetID(string id) {
    this->id = id;
}

void Dog::SetColor(string color) {
    this->color = color;
}

void Dog::SetComments(string comments) {
    this->comments = comments;
}

// Display Function
void Dog::PrintInfo() {
    cout << "\tID: " << id << endl;
    cout << "\tName: " << name << endl;
    cout << "\tBreed: " << breed << endl;
    cout << "\tColor: " << color << endl;
    cout << "\tWeight: " << weight << endl;
    cout << "\tGender: " << (gender == 'M' ? "Male" : (gender == 'F' ? "Female" : "Unknown")) << endl;
    cout << "\tSpayed/Neutered: " << (is_spayed ? "Yes" : "No") << endl;
    cout << "\tComments: " << comments << endl;
}