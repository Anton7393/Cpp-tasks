#include "stdafx.h"
#include "Egg.hh"

Chicken * Egg::getCreator()
{
	if (!creator) exit(1);
	return creator;
}
