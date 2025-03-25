#include <iostream>
#include <vector>
#include "dog.hpp"
#include "cat.hpp"

using namespace std;

int main()
{
    vector<Pet*> pvec;  // Vector of Pet pointers

    pvec.push_back(new Dog("Bob",65));
    pvec.push_back(new Dog("Stan",37));
    pvec.push_back(new Cat("Tom",12));

    //Calculate and display the individual fees
    float total_fee = 0.0;
    for (int i = 0; i < pvec.size(); i++)
    {
        cout << pvec[i]->GetName() << ' ' << pvec[i]->CalculateFee() << endl;
        total_fee = total_fee + pvec[i]->CalculateFee();
    }

    //print the total licensing fee
    cout << "total licensing fee = " << total_fee << endl;

    // Free allocated memory
    for (int i = 0; i < pvec.size(); i++) 
    {
        delete pvec[i];
    }
    
    return 0;
}