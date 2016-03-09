#ifndef TENT_H
#define TENT_H

#include "Residence.h"
#include <iostream>

class Tent : public Residence
{
public:
	Tent();
	Tent(int,int,bool);
protected:
	double PropertyValue() const;
	int NumWindows() const;

	// Overloaded << operator as non-member function 
	friend std::ostream& operator<< (std::ostream& out, const Tent& tent);
};

std::ostream& operator<< (std::ostream& out, const Tent& tent);

#endif