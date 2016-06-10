#ifndef WORKER_H
#define WORKER_H

#include "one.hh"
#include "two.hh"

class Worker
{
    public:
	static int Part1;
	static const int Part2 = 0x22;
	static const int Part3 = 0x44;
	static bool prepared;

	int part1();
	int part2();
	int part3();
};

#endif WORKER_H
