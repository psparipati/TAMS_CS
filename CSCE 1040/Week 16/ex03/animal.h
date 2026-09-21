#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal {
    public:
        // Accessors and mutators for all attributes
        float GetWeight() const;
        void SetWeight(float weight);
        string GetName() const;
        void SetName(const string& name);
        char GetGender() const;
        void SetGender(char gender);
        string GetColorDesc() const;
        void SetColorDesc(const string& color_desc);
        // Default constructor
        Animal();
        // Parameterized constructor
        Animal(float weight, const string& name, char gender, const string& color_desc);
        // Display method for a formatted view of the animal's attributes
        virtual void Display() const;
    private:
        float weight;
        string name;
        char gender; // 'm' for male, 'f' for female
        string color_desc; // can be more than one word
};

#endif // ANIMAL_H