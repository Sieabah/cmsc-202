#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int number, total = 0;
	long factorial = 1;
	char name[180];

	cout << "Enter a number: ";
	cin >> number;
	//Get rid of the goddamn \n
	cin.getline(name, sizeof(name));

	cout << "Enter your name: ";
	cin.getline(name, sizeof(name));
	/*
	do{
		cin.getline(name, sizeof(name));
		cout << endl << "name: " << name << endl;
	} while(strcmp(name, "\n") == 0);
	*/
	for(int i = 1; i < number+1; i++)
	{
		total += i;

		factorial *= i;
	}

	cout << "Hi " << name << " your numbers have these results." << endl;
	cout << "Sum of all the numbers up to your number: " << total << endl;
	cout << "Factorial of your number: " << factorial << endl;


	return 0;
}