#ifndef COW_H
#define COW_H

#include "animal.h"

class Cow : public Animal {
    public:
        // Accessors and mutators for all attributes
        string GetBreed() const;
        void SetBreed(const string& breed);
        bool GetIsSpayedNeutered() const;
        void SetIsSpayedNeutered(bool is_spayed_neutered);
        string GetID() const;
        void SetID(const string& id);
        string GetComments() const;
        void SetComments(const string& comments);
        // Default constructor
        Cow();
        // Parameterized constructor
        Cow(float weight, const string& name, char gender, const string& color_desc, const string& breed, bool is_spayed_neutered, const string& id, const string& comments);
        // Display method for a formatted view of the cow's attributes
        void Display() const override;
    private:
        string breed;
        bool is_spayed_neutered;
        string id;
        string comments;
};

#endif // COW_H