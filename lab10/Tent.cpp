#include "Tent.h"
#include <iostream>

Tent::Tent()
  : Residence(1,2,false)
{
}

Tent::Tent(int rooms, int walls, bool washer)
  : Residence(rooms,walls,washer)
{
}

double Tent::PropertyValue() const
{
	return 0.0;
}

int Tent::NumWindows() const
{
	return 0;
}

std::ostream& operator<< (std::ostream& out, const Tent& res)
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
