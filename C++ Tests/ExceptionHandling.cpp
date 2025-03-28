#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    vector<int> vec;
    vec.push_back(99);
    vec.push_back(56);
    
    //access a third element that does not exist
    try
    {
        vec.at(2);
    }
    catch(exception& e)
    {
        cout << "Exception occured!" << endl;
    }
    
    return 0;
}