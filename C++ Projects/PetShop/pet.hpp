#ifndef PET_HPP
#define PET_HPP
#include <string>

using namespace std;

class Pet{
    private:
        string name;
        float weight;
    public:
        Pet(string name, float weight) : name(name), weight(weight) {}

        ~Pet() {} //Made a deconstructor in case we need to remove the pet reference from memory
        
        string GetName() const{return name;}
        float GetWeight() const{return weight;}

        virtual float CalculateFee() const = 0;
};

#endif