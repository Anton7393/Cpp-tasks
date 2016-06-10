#pragma once
#include "Egg.hh"

class Egg;

class Chicken
{
public:
	Egg * creator;
	Egg * getCreator();
};


