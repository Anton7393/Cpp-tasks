#include "stdafx.h"
#include "two.hh"

void prepare_two()
{
	Worker::prepared = true;
	Worker::Part1 = 0x88;
}

void work_two()
{
	start();
	Worker w;
	if ( GoodWork == ( w.part1() | w.part2() | w.part3() ) )
	{
		act( "two" );
	}
	stop();
}
