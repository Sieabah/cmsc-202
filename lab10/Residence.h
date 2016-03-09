#ifndef RESIDENCE_H
#define RESIDENCE_H

#include <iostream>

class Residence
{
public:
	Residence();
	Residence(int, int, bool);
protected:
	bool HasWasher() const;
	double PropertyValue() const;
	int NumWindows() const;
	int NumWalls() const;
	int NumRooms() const;
	// Overloaded << operator as non-member function 
	friend std::ostream& operator<< (std::ostream& out, const Residence& number);
 private:
	int m_rooms;
	int m_walls;
	bool m_washer;
};

std::ostream& operator<< (std::ostream& out, const Residence& number);

#endif
