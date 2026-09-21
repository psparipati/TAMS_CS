#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Dog {
    public:
        // Null Constructor
        Dog();
        // Full Constructor
        Dog(string breed, float weight, string name, char gender, bool is_spayed, string id, string color, string comments);
        // Accessors
        string GetBreed();
        float GetWeight();
        string GetName();
        char GetGender();
        bool GetIs_Spayed();
        string GetID();
        string GetColor();
        string GetComments();
        // Mutators
        void SetBreed(string breed);
        void SetWeight(float weight);
        void SetName(string name);
        void SetGender(char gender);
        void SetIs_Spayed(bool is_spayed);
        void SetID(string id);
        void SetColor(string color);
        void SetComments(string comments);
        // Display Method
        void PrintInfo();
    private:
        string breed;
        float weight;
        string name;
        char gender;
        bool is_spayed;
        string id;
        string color;
        string comments;
};

#endif //DOG_H