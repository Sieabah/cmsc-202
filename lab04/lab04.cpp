#include <iostream>
#include <cstring>
#include <stdlib.h>   // This defines the library for atoi()
//NEEDED TO ADD .h

// ADD #include's HERE FOR ANY OTHER LIBRARIES YOU USE

using namespace std;

// ADD ANY GLOBAL CONSTANTS HERE

struct Record 
{
	char *m_firstName;
	char *m_lastName;
	int m_age;
};

//Munge Record via Pass-By-Value
void MungeRecord(Record rec);
//Munge Record via Pass-By-Reference
void MungeRecordForReal(Record &rec);
//Munge Record via constant Pass-By_Reference
void MungeRecordFail(const Record &rec);
//Print the record neatly
void printRecord(Record rec);

int main(int argc, char *argv[]) {

	if(argc > 3)
	{
		//Setup Record myRec from arguments
		Record myRec;
		myRec.m_firstName = argv[1];
		myRec.m_lastName = argv[2];
		myRec.m_age = atoi(argv[3]);

		//Munge data using Pass-by-value
		cout << "Munge" << endl;
		MungeRecord(myRec);
		cout << endl << "main()" << endl;
		printRecord(myRec);

		//Munge data using Pass-by-reference
		cout << endl << "Real Munge" << endl;
		MungeRecordForReal(myRec);
		cout << endl << "main()" << endl;
		printRecord(myRec);

		/*
		  cout << endl <<"Munge Fail" << endl;
		MungeRecordFail(myRec);
		printRecord(myRec);
		*/
	} else {
		cout << "Use this as follows, lab04.cpp <firstname> <lastname> <age>"<<endl;
	}

    // STEP 5: WRITE THE FUNCTION MungeRecordFail() DOWN BELOW, AFTER main().
    // ADD CALL TO MungeRecordFail() HERE, PASSING IN myRec AS ARGUMENT

    // AFTER IT RETURNS, PRINT OUT THE CONTENTS OF myRec
    // (Again, can just cut-and-paste from Step 3 above, then
    //  edit it slightly)

    return 0;
}

/*
Munges record using Pass-By-Value
Takes record struct
*/
void MungeRecord(Record rec)
{
	//Create temporary value
	char *temp = rec.m_lastName;
	//Change Values
	rec.m_lastName = rec.m_firstName;
	rec.m_firstName = temp;
	rec.m_age = -1;
	cout << "MungeRecord()" << endl;
	printRecord(rec);
}

/*
Munges record using Pass-By-Reference
Takes record struct and changes data
*/
void MungeRecordForReal(Record &rec)
{
	//Create temp value
	char *temp = rec.m_lastName;
	//Change values
	rec.m_lastName = rec.m_firstName;
	rec.m_firstName = temp;
	rec.m_age = -1;
	cout << "MungeRecordForReal()" << endl;
	printRecord(rec);
}

/*
Munges record using Pass-By-Reference
Takes record struct and changes data

*CREATES THIS ERROR WHEN UNCOMMENTED

lab04.cpp: In function ‘void MungeRecordFail(const Record&)’:
lab04.cpp:99: error: assignment of data-member ‘Record::m_lastName’ in read-only structure
lab04.cpp:100: error: assignment of data-member ‘Record::m_firstName’ in read-only structure
lab04.cpp:101: error: assignment of data-member ‘Record::m_age’ in read-only structure
make: *** [lab04.out] Error 1

*/
void MungeRecordFail(const Record &rec)
{
	/*
	//Create temp value
	char *temp = rec.m_lastName;
	//Change values
	rec.m_lastName = rec.m_firstName;
	rec.m_firstName = temp;
	rec.m_age = -1;
	//*/
}

/*
Prints records from Record struct
*/
void printRecord(Record rec)
{
	cout << "Record:" << endl;
	cout << "First Name: " << rec.m_firstName << endl;
	cout << "Last Name: " << rec.m_lastName << endl;
	cout << "Age: " << rec.m_age << endl;
}
