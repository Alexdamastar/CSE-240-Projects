#ifndef DOG_HPP
#define DOG_HPP

#include "pet.hpp"

class Dog : public Pet{
    private: 
        static float licensingrate; //made a static rate per pound

    public:
        Dog(string name, float weight) : Pet(name, weight) {}

        ~Dog() {}

        float CalculateFee() const override{return GetWeight() * licensingrate;}
};

float Dog::licensingrate = 2.0;

#endif