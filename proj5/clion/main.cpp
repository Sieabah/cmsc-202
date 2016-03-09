#include <iostream>
#include "Vector3D.h"

#include <string>
#include <fstream>
#include <sys/stat.h>

using namespace std;

/**
 * Checks for file existance
 */
inline bool file_exits(const string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char *argv[]) {
    if(argc == 0)
    {
        cout << "Please specify the file to display: <program> <filepath>" << endl;
        return 1;
    }
    else if(!file_exits(argv[1]))
    {
        cout << "Please give a valid file" << endl;
        return 1;
    }

    string line;
    ifstream file(argv[1]);

    if(file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }


    return 0;
}