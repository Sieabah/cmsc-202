#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h> 
#include <sys/stat.h>
#include <fstream>
#include <cctype>
#include <sstream>

using namespace std;

string createDirectory(string num);
void createMakefile(string dir);
void createCppFile(string dir);

/*
	labc <num>
*/
int main(int argc, char* argv[])
{
	//If it exists
	if(argc > 1)
	{	
		//Convert char to string
		stringstream ss;
		string value;
		ss << argv[1];
		ss >> value;
		if(value.find_first_not_of( "0123456789" ) == string::npos)
		{
			//Find the correct directory name and create it
			string labDir = createDirectory(string(argv[1]));
			//Make barebones makefile
			createMakefile(labDir);
			//Make barebones C++ file
			createCppFile(labDir);
		} 
		else 
		{
			cout << "Use: labc <num>" << endl;
		}
	} 
	else 
	{
		cout << "Use: labc <num>" << endl;
	}

	return 0;
}

//Create directory from string
string createDirectory(const string labNum)
{
	//the resulting folder prefix
	string labDir = "proj";

	//find the number
	int labC = atoi(labNum.c_str());

	//Check to see if we're sub zero
	if(labC < 10)
		labDir += string("");

	//Append stringified number to directory
	labDir += labNum;

	struct stat sb;

	if (stat(labDir.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		cout << "Proj("<<labDir<<") already exists!" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		//Create the directory LINUX ONLY
		mkdir(labDir.c_str(), 0777);

		//Display the folder which was made
		cout << "Created directory: " << labDir << endl;

		return labDir;
	}
}

//Create makefile
void createMakefile(string dir)
{
	//Determine location and file
	string file = dir + "/Makefile";

	//Open stream
	ofstream myfile;
	myfile.open (file.c_str());
	//Write barebones makefile
	myfile << dir << ".out: " << dir << ".cpp\n\t g++ -Wall ";
	myfile << dir << ".cpp -o " << dir << ".out";
	//Close it
	myfile.close();
	cout << "Makefile created." << endl;
}

void createCppFile(string dir)
{
	//Determine location and file
	string file = dir + "/"+dir+".cpp";

	//Open stream
	ofstream myfile;
	myfile.open (file.c_str());
	//Write barebones C++ file
	myfile << "#include <iostream>\n\nusing namespace std;\n\nint main(int argc, char* argv[])\n{\n\tcout << \"" << dir << "\"<<\" Cpp File\" <<endl;\n\treturn 0;\n}";
	//Close it
	myfile.close();
	cout << "C++ file created" << endl;
}