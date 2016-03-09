#include "Residence.h"
#include <iostream>

using namespace std;

Residence::Residence()
{
}

Residence::Residence(int rooms, int walls, bool washer)
  : m_rooms(rooms), m_walls(walls), m_washer(washer)
{
}

bool Residence::HasWasher() const
{
	return m_washer;
}

int Residence::NumWindows() const
{
	return m_walls * 2;
}

int Residence::NumWalls() const
{
	return m_walls;
}

int Residence::NumRooms() const
{
	return m_rooms;
}

double Residence::PropertyValue() const
{
	return 10000 * NumRooms();
}


ostream& operator<< (ostream& out, const Residence& res)
{
	out << "Number of Rooms: " <<  res.NumRooms()
		<< "\nNumber of Walls: " << res.NumWalls()
		<< "\nWasher: ";
	if(res.HasWasher())
	{
		out << "true";	
	}
	else 
	{
		out << "false";
	}
	out	<< "\nNumber of Windows: " << res.NumWindows()
		<< "\nProperty Value: " << res.PropertyValue();
	return out;
}
