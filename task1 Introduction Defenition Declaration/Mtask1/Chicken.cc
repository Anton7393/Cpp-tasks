#include "stdafx.h"
#include "Chicken.hh"

Egg * Chicken::getCreator()
{
	if (!creator) exit(1);
	return creator;
}
