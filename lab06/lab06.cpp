#include <iostream>
#include "Fraction.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
	
	//Check command line arguments for amount;
	if(argc < 3)
	{
		cout << argv[0] << " <numerator> <denomentator>" << endl;
		return 0;
	}

	//  - Take in the first fraction from the command line. 
    //    Find the reciprocal of this fraction and print it to the screen.

	Fraction frac1(atoi(argv[1]), atoi(argv[2]));

	Fraction Recip = Fraction::Reciprocal(frac1);

	Recip.Output();

	//  - The second fraction will be created with default values. You
    //    should also print this to the screen.

	Fraction frac2;

	frac2.Output();

	//  - Then you will attempt to create a fraction with a denominator
    //    of zero, which should print an error

    Fraction frac3(1,0);

	frac3.Output();

	return 0;
}