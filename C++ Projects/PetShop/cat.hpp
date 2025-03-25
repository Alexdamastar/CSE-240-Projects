#ifndef CAT_HPP
#define CAT_HPP

#include "pet.hpp"

class Cat: public Pet{
    private:
        static float licensingrate; //made a static rate per pound

    public:
        Cat(string name, float weight) : Pet(name,weight) {}

        ~Cat() {}

        float CalculateFee() const override{return GetWeight() * licensingrate;}
};

float Cat::licensingrate = 1.5;

#endif