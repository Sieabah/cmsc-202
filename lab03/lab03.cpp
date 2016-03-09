#include <iostream>
#include <cstring>
#include <cctype>

// ADD #include's HERE FOR ANY OTHER LIBRARIES YOU USE

using namespace std;

// ADD ANY GLOBAL CONSTANT HERE
const int MAX_STR = 151;

//Poor form, but whatever. I wouldn't normally do this.
bool DEBUG = false;

//Prompts user for an answer
void getAnswerFromUser(char prompt[], char buffer[],int size);

//Tests whether a string is a palindrome
bool testForPalinDrome(char buffer[], int size);

//Converts text to the essential characters
int convertToCanonical(char string[], int size);

int main(int argc, char *argv[]) {

    // For following to work you must be sure to define MAX_STR above
    // as a global constant (it must be global because it is used again
    // elsewhere).

    char buffer[MAX_STR];

    /*
    	Personal DEBUG Thing
    */
    if(argc > 0)
    {
    	DEBUG = argv[1];
    }

    // First, prompt for, and get sentence to test from user, reading
    // it into buffer[]
    char prompt[] = "Write a sentence of 150 characters or less: ";
    getAnswerFromUser( prompt, buffer, MAX_STR );

    // Now, test the inpu string to see if it's an palindrome
    bool palindrome = testForPalinDrome( buffer, MAX_STR );

    // Lastly, see what testForPalindrome() returned, and use that
    // to output the proper result

    //Print the buffer
    cout << buffer;
    //Print whether the string is a palindrome or not
    if(palindrome)
    {
    	cout << " is a palindrome.";
    } else {
    	cout << " is not a palindrome";
    }
    cout << endl;
    return 0;
}

/* Gets an answer from the user
 * It takes a string for the prompt, a variable to hold the input text
 *		as well as the input size
 *	It returns the full string inluding data after the user input has
 *		ended up to the size variable
*/
void getAnswerFromUser(char prompt[], char buffer[], int size)
{

	//Prompt user
	cout << prompt;
	//Get line
	cin.getline(buffer, size);
	/* //This section prevents numbers from being entered
	bool valid;
	do{
		valid = true;
		//Prompt user
		cout << prompt;
		//Get line
		cin.getline(buffer, size);

		bool quit = false;
		for (int i = 0; i < size; ++i)
		{

			int asciiNum = (int)buffer[i];
			if(asciiNum == 0)
			{
				//I WISH I COULD USE BREAK
				quit = true;
			}
			if(!quit)
			{
				if(asciiNum >= 48 && asciiNum <= 57)
				{
					cout << "Please don't use numbers!" << endl;
					quit = true;
					valid = false;
				}
			}
		}
	} while(!valid);
	*/
}

/* Converts the text to essential string
 * Takes string variable and puts the canonical string into it.
 * This function returns the new size with removed symbols and spaces
*/
int convertToCanonical(char string[], int size)
{
	//Create the temp array to hold the new string
	char fixedString[size];
	//Variable for the corrected size
	int newSize = 0;
	//Boolean of whether we're done with the string
	bool quit = false;

	//For the entire string
	for(int i = 0; i < size; i++)
	{
		//Get the acii number of the string
		int asciiNum = (int)string[i];
		//See if we're dealing with the terminating character
		if(asciiNum == 0)
		{
			//If so, stop converting and call it quits
			quit = true;

			//Normally we would 'break' here.
		}

		//Tests whether we're in the range of letter A-z, and if we
		//	are add it to the new string.
		//Another good reason to use 'continue'
		if(((asciiNum >= 65 && asciiNum <= 122) || 
			(asciiNum >= 48 && asciiNum <= 57)) && !quit)
		{
			//Append to the new string the corrected character
			fixedString[newSize++] = tolower(string[i]);
		}
	}

	fixedString[newSize] = '\0';

	if(DEBUG)
	{
		cout << "New String: " << fixedString << endl;
	}
	//Copy the string to the input string.
	//We do this to prevent the string variable pointing to garbage
	//	after the function is gone
	strcpy(string, fixedString);
	return newSize;
}

/* Tests whether the string is a palindrome
 * Takes the input string, and the size of that string.
*/
bool testForPalinDrome(char buffer[], int size)
{
	//Copy string so we're not editing the original string
	char string[size];
	strcpy(string,buffer);

	//This variable is the real string size after it's been converted
	int stringSize;

	//Convert to testable string, and get new string size
	stringSize = convertToCanonical(string, size);

	//For the entire string
	for (int i = 0; i < stringSize; i++)
	{
		if(DEBUG)
		{
			//Print out checks.
			cout << string[i] << "("<< (int)string[i] << ")" << " =? ";
			cout << string[stringSize-(i+1)] << "(" 
				<< (int)string[stringSize-(i+1)] << ")" << endl;
		}
		
		//Check to see if the two characters are the same
		if((int)string[i] != (int)string[stringSize-(i+1)])
		{
			//If not, then we have reached the point where we have enough info
			//	to say that the string is NOT a palindrome
			return false;
		}
	}

	//If we've gone through all characters, then and we reach this part then we
	//	have a palindrome
	return true;
}