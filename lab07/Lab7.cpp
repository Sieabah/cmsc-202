#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    // Create IntArray objects and call methods here...

	IntArray one(-1,0); //1
	IntArray two(0,0); //Edge 1

	IntArray errorBillion(1000000001, 0);
	IntArray error(50, 0);
	error.~IntArray(); //Destructors
	error.~IntArray(); //Destructors

	IntArray three;
	IntArray threeTwo;
	IntArray four(5,0);


	one == two; //3
	three == threeTwo; //Edge 3
	one != two; //4
	three != threeTwo; //Edge 4
	one += three; //Edge 5
	three + threeTwo; //Edge 6 & Edge 7
	four[-1]; //5

	one.Get(-1); //6
	one.Get(50); //7

	one.SetItem(-1,0); //8
	one.SetItem(50,0); //9

	three.Insert(0,50); //10
	one.Insert(-1,50); //11
	one.Insert(50,50); //12

	three.Del(0); //13
	one.Del(-1); //14
	one.Del(50); //15

	three.Remove(0); //16
	one.Remove(-1); //17

	three.Clear(); //Edge 8

	three.Contains(-1); //18

	three.Contains(0,0); //19
	three.Contains(0,1); //20
	//Look at #31 for third error

	three.IndexOf(0); //21
	one.IndexOf(-1); //22

	three.AddToAll(0); //23

	three.Scale(0); //24

	two.Sum(one); //25
	one.Sum(three); //26
	one.Sum(four); //27

	three.Product(one); //28
	one.Product(three); //29
	one.Product(four); //30

	one.Contains(0,50); //31

	//Extra Credit
	IntArray extraOne(5,3);
	IntArray extraTwo(extraOne);

	cout << "EC 1: " << extraOne.Get(2) << endl;
	cout << "EC 2: " << extraTwo.Get(2) << " (copied constructor)" << endl;
	cout << "Changed EC 2" << endl;
	extraTwo.SetItem(2,80);
	cout << "EC 1: " << extraOne.Get(2) << endl;
	cout << "EC 2: " << extraTwo.Get(2) << " (changed)" << endl;

	extraOne = extraTwo;
	cout << "EC 1: " << extraOne.Get(2) << " (copied assignment)" <<  endl;
	cout << "EC 2: " << extraTwo.Get(2) << endl;
	extraOne.SetItem(2,45);
	cout << "Changed EC 1" << endl;
	cout << "EC 1: " << extraOne.Get(2) << " (changed)" << endl;
	cout << "EC 2: " << extraTwo.Get(2) << endl;
	
    
    // Print out the number of errors/edge cases found
    cout << endl << endl << IntArray::GetProgress() << endl;
    
    return 0;
}

/*

CMSC 411: Younis
CMSC 421: Park / Kalpakis
CMSC 426: 
CMSC 433: (try to take)
CMSC 435: Olano
CMSC 441: Chang
CMSC 442: Lomonaco
CMSC 447: Gartner (poor class to take) 
CMSC 451: 
CMSC 461: 
CMSC 471: Max (AI course)
CMSC 478: Oates (Math skill)
CMSC 481: Sidhu (terrible)
CMSC 487: Joshi
CMSC 491: Yelena Yesha
CMSC 495: 
CMSC 499: Chen

Dejardin (AI)
Finin (AI)

 */
