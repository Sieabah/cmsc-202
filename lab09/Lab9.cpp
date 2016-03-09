

#include <iostream>
#include "List.h"

int main() {

   List List1;
   List List2;



   cout << "Testing Insert..." << endl;
   for(int i = -5; i < 10; i+=2) {
      List1.insert(i);
   }

   for(int i = 6; i > -11; i -= 5) {
      List1.insert(i);
   }

   for(int i = -7; i < 11; i+= 3) {
      List1.insert(i);
   }

   for(int i = 2; i > -2; i--) {
      List1.insert(i);
   }

   cout << "Should Print: -9 -7 -5 -4 -4 -3 -1 -1 -1 0 1 1 1 2 2 3 5 5 6 7 8 9" << endl;
   cout << "Actual Print: ";
   List1.Print();
   cout << endl << endl;





   cout << "Testing Assignment..." << endl;
   List2 = List1;

   cout << "Should Print: -9 -7 -5 -4 -4 -3 -1 -1 -1 0 1 1 1 2 2 3 5 5 6 7 8 9" << endl;
   cout << "Actual Print: ";
   List2.Print();
   cout << endl << endl;


   cout << "Testing Clear..." << endl;
   List2.clear();
   List2.insert(3);

   cout << "Should Print: 3" << endl;
   cout << "Actual Print: ";
   List2.Print();
   cout << endl << endl;



   cout << "Testing Remove..." << endl;
   List2.remove(3);
   List2.insert(4);
   List2.insert(5);
   List2.remove(-75);
   List2.remove(5);
   List2.remove(4);
   List2.remove(-99);
   List2.insert(9);

   List1.remove(-7);
   List1.remove(5);
   List1.remove(0);
   List1.remove(9);
   List1.remove(-9);
   List1.remove(-5);
   List1.remove(8);
   List1.remove(-1);
   List1.remove(1);

   cout << "Should Print: 9" << endl;
   cout << "Actual Print: ";
   List2.Print();
   cout << endl << endl;

   cout << "Should Print: -4 -4 -3 -1 -1 1 1 2 2 3 5 6 7" << endl;
   cout << "Actual Print: ";
   List1.Print();
   cout << endl << endl;



   cout << "Testing Size..." << endl;
   cout << "Should Print: 1" << endl;
   cout << "Actual Print: " << List2.size() << endl << endl;

   cout << "Should Print: 13" << endl;
   cout << "Actual Print: " << List1.size() << endl << endl;



   cout << "Testing Extra Credit..." << endl;
   cout << "Should Print: 7 6 5 3 2 2 1 1 -1 -1 -3 -4 -4" << endl;
   cout << "Actual Print: ";
   List1.ReversePrint();
   cout << endl << endl;



   return 0;

}
