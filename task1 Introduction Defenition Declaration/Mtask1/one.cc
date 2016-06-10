#include "stdafx.h"
#include "one.hh"

void prepare_one()
{
	Worker::prepared = true;
	Worker::Part1 = 0x11;
}

void work_one()
{
	start();
	Worker w;
	if ( GoodWork == ( w.part1() | w.part2() | w.part3() ) )
	{
		act( "one" );
	}
	stop();
}
