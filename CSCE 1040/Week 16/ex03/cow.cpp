#include "cow.h"

Cow::Cow() : Animal(), breed(""), is_spayed_neutered(false), id(""), comments("") {}

Cow::Cow(float weight, const string& name, char gender, const string& color_desc, const string& breed, bool is_spayed_neutered, const string& id, const string& comments) : Animal() {
    this->breed = breed;
    this->is_spayed_neutered = is_spayed_neutered;
    this->id = id;
    this->comments = comments;
}

string Cow::GetBreed() const {
    return breed;
}

void Cow::SetBreed(const string& breed) {
    this->breed = breed;
}

bool Cow::GetIsSpayedNeutered() const {
    return is_spayed_neutered;
}

string Cow::GetID() const {
    return id;
}

void Cow::SetID(const string& id) {
    this->id = id;
}

string Cow::GetComments() const {
    return comments;
}

void Cow::SetComments(const string& comments) {
    this->comments = comments;
}

void Cow::SetIsSpayedNeutered(bool is_spayed_neutered) {
    this->is_spayed_neutered = is_spayed_neutered;
}

void Cow::Display() const {
    Animal::Display();
    cout << "Breed: " << breed << endl;
    cout << "Spayed/Neutered: " << (is_spayed_neutered ? "Yes" : "No") << endl;
    cout << "ID: " << id << endl;
    cout << "Comments: " << comments << endl << endl;
}