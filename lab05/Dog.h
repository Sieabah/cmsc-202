// File: Dog.h
//
// Modified class definition from Lab 3.
// Added #ifndef ...  macros, default constructor, 
// GetName accessor.

#ifndef DOG_H
#define DOG_H

#include <string>

using namespace std;

class Dog {
public:
   // Default constructor, does nothing.
   Dog() ;

   // Creates a dog. A dog must have a name and a birth year.
   Dog(const string &name, unsigned int birthyear);

   // Returns the name of the owner
   string GetOwner() const;

   // Gives the Dog a new owner
   void SetOwner(const string &owner);

   // Returns the name of the dog
   string GetName() const ;

   // Returns the age of the dog at a given year
   unsigned int GetAge(unsigned int current_year) const;

   // Abuse the dog
   void Abuse();

   // Pat the dog
   void Pat();

   // See how the dog is feeling
   string GetHappiness() const;

   // Prompt the dog to talk to you
   void Talk() const;

private:
   // Name of Dog
   string m_name;      

   unsigned int m_birthyear;

   // Name of owner
   string m_owner;

   // Happiness rating from Pat() and Abuse()
   int m_happiness;

};

#endif 