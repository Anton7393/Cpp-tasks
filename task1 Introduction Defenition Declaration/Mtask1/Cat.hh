#pragma once
#include "Pet.hh"

class Cat : public Pet
{
    public:
        virtual const char * say();
        virtual bool gnaw();
        virtual int lifes();
};

