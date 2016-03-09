#include "Apartment.h"

Apartment::Apartment()
  : Residence(4,4,true), m_story(1)
{
}

Apartment::Apartment(bool washer, int story)
  : Residence(4,4,washer), m_story(story)
{
}

Apartment::Apartment(int rooms, int walls, bool washer, int story)
  : Residence(rooms,walls,washer), m_story(story)
{
}

double Apartment::PropertyValue() const
{
	int val = HasWasher() ? 100 : 0;
	return Residence::PropertyValue() + val;
}

int Apartment::GetStory() const
{
	return m_story;
}

std::ostream& operator<< (std::ostream& out, const Apartment& res)
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
		<< "\nProperty Value: " << res.PropertyValue()
		<< "\nStory: " << res.GetStory();
	return out;
}
