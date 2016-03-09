#include <iostream>
#include <string>
#include "Pair.h"

using namespace std;

int main()
{
    /*
    Pair pair1(1, 2);
    Pair pair2(1, 2);
    Pair pair3(2, 1);
    Pair pair4(3, 3);
//    */
//*
    Pair<string> pair1("yes", "no");
    Pair<string> pair2("yes", "no");
    Pair<string> pair3("no", "yes");
    Pair<string> pair4("maybe", "not");
//*/


    cout << "pair1.GetFirst() returned " << pair1.GetFirst() << endl;
    cout << "should have gotten 1.\n";
    cout << "pair1.GetSecond() returned " << pair1.GetSecond() << endl;
    cout << "should have gotten 2.\n";

    if (pair1 == pair2) {
	cout << "pair1 == pair2--correct\n";
    }
    else {
	cout << "pair1 != pair2--ERROR!\n";
    }

    if (pair1 == pair3) {
	cout << "pair1 == pair3--correct\n";
    }
    else {
	cout << "pair1 != pair3--ERROR!\n";
    }

    if (pair1 == pair4) {
	cout << "pair1 == pair4--ERROR!\n";
    }
    else {
	cout << "pair1 != pair4--correct!\n";
    }
  
  return 0;
}

