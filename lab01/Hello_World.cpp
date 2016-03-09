#include <iostream>
using namespace std;

int main()
{
  //Create variables to use
  float valOne, valTwo;
  float avg;

  //Prompt
  cout << "Enter two numbers: ";

  //Get numbers
  cin >> valOne >> valTwo;

  //Compute the average
  avg = (valOne + valTwo)/2.0;

  //Prompt the output with numbers and average
  cout << "\nThe average of " << valOne << " and " << 
    valTwo << " is " << avg << endl;

  //Return successfully
  return 0;
}
