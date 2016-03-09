#ifndef HOUSE_H
#define HOUSE_H

#include "Residence.h"
#include <iostream>

class House : public Residence
{
public:
	House();
	House(int,int,bool);
protected:
	// Overloaded << operator as non-member function 
	friend std::ostream& operator<< (std::ostream& out, const House& haus);
};

std::ostream& operator<< (std::ostream& out, const House& haus);

#endif