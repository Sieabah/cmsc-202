#include <iostream>
using namespace std;

bool test(int var)
{
	if(var > 5)
		return true;
	else
		return false;
}

int main()
{
cout << test(4) << endl;
cout << test(10) << endl;
return 0;
}
