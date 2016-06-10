#pragma once
#include "Chicken.hh"

class Chicken;

class Egg 
{
public:
	Chicken * creator;
	Chicken * getCreator();
};

