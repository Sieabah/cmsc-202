#include<iostream>

#include "House.h"
#include "Apartment.h"
#include "Tent.h"

using namespace std;

int main() {
  cout << "House: ";
  House haus;
  //make a House object
  //use toString to print the values related to this house
  cout << haus << endl << endl;

  cout << "Apartment: ";
  Apartment apar(true,2);
  //make a new Apartment object on the 2nd floor that has a washer
  //use toString to print the values related to this apartment
  cout << apar << endl << endl;

  cout << "Tent: ";
  Tent tent;
  //make a new Tent object
  //use toString to print the values related to this tent
  cout << tent << endl << endl;
}

