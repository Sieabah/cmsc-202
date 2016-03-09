#include "House.h"

House::House()
  : Residence(4,4,true)
{
}

House::House(int rooms, int walls, bool washer)
: Residence(rooms,walls,washer)
{
}

std::ostream& operator<< (std::ostream& out, const House& res)
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
