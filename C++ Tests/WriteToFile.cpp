#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    ofstream myfile;
    myfile.open("fluffy.txt");
    if (myfile.is_open())
    {
        cout << "file opened\n";
        myfile << "Hello, line 1.\n";
        myfile << "Hello, line 2.\n";
        myfile.close();
    }
    else
        cout << "Unable to open file";
    
    return 0;
}