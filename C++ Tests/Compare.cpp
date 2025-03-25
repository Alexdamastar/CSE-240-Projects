#include <iostream>
using namespace std;

int compare(const int& a, const int& b)
{
    if (a < b) return -1;
    if (b < a) return 1;
    return 0;
}

int compare( const string& a, const string& b)
{
    if (a < b) return -1;
    if (b < a) return 1;
    return 0;
}

int main()
{
    cout << compare(10,20) << endl;
    cout << compare("before", "after") << endl;
}