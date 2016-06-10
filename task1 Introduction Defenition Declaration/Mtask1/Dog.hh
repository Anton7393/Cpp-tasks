#pragma once
#include "Pet.hh"

class Dog : public Pet
{
    public:
        virtual const char * say();
        virtual bool gnaw();
        virtual int lifes();
};
