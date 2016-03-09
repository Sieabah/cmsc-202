#ifndef APARTMENT_H
#define APARTMENT_H

#include "Residence.h"
#include <iostream>

class Apartment : public Residence
{
public:
	Apartment();
	Apartment(bool,int);
	Apartment(int,int,bool, int);
private:
	int m_story;
protected:
	// Overloaded << operator as non-member function 
	friend std::ostream& operator<< (std::ostream& out, const Apartment& apar);
	double PropertyValue() const;
	int GetStory() const;
};

std::ostream& operator<< (std::ostream& out, const Apartment& apar);

#endif
