#include <iostream>
#include "Dog.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Variables
	unsigned int currentYear = 2014;
	int abuseAmount = 7;

	//Create two dogs with names and ages
	cout << "Creating dogs..." << endl;
	Dog one = Dog("grep", 1982);
	Dog two = Dog("Dr. Pepper", 1953);

	//Print out some information about the dogs
	cout << "Dog1's name is: " << one.GetName() << endl;
	cout << "Dog2's name is: " << two.GetName() << endl;
	cout << "Dog1's age is: " << one.GetAge(currentYear) << endl;

	//Change the owner of one dog
	cout << "Setting Dog2's owner to Red Bull" << endl;
	two.SetOwner("Red Bull");

	//Print the new owner
	cout << "Dog2's owner is " << two.GetOwner() << endl;

	//Abuse the dog :(
	for (int i = 0; i < abuseAmount; i++)
	{
		cout << "Abusing Dog2..." <<endl;
		two.Abuse();
	}

	//Print the hapiness of the abused dog
	cout << "Dog2 is " << two.GetHappiness() << endl;

	//Print what the other dog says
	cout << "Dog1 says ";
	one.Talk();

}