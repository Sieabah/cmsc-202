// File: Dog.cpp
//
// Implementation of Dog class.
//

#include <iostream>
#include "Dog.h"

// ------------- Constructors ----------------------

// Default constructor, does nothing
//
Dog::Dog() 
{
   // do nothing
}


// Alternate constructor
// Note the use of member initializers.
//
Dog::Dog(const string &name, unsigned int birthyear)
    : m_name(name), m_birthyear(birthyear),
    m_owner("I'm an orphan"), m_happiness(0)
{
   // do nothing
}
    

// ------------- Accessors -------------------------
//
// These do what you think.

string Dog::GetOwner() const {
    return m_owner;
}

void Dog::SetOwner(const string &owner) {
    m_owner = owner;
}

string Dog::GetName() const {
    return m_name;
}

unsigned int Dog::GetAge(unsigned int current_year) const {
    return current_year - m_birthyear;
}



// ------------- Mutators --------------------------
// See Lab 3 description for what these mean.
        
void Dog::Abuse() {
    m_happiness--;
}

void Dog::Pat() {
    m_happiness++;
}



// ------ Service/Facilitator Methods --------------
// See Lab 3 description for what these mean.

string Dog::GetHappiness() const {
    if(m_happiness > 1) {
        return "happy";
    }

    else if(m_happiness < 1) {
        return "sad";
    }
    
    else {
        return "ok";
    }
}
        
void Dog::Talk() const {
    cout << "woof" << endl;
}