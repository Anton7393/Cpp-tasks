#include "stdafx.h"
#include "Worker.hh"
#include "Zoo.hh"


int GoodWork;

enum Type {
	person,
	animal
};

struct Animal;
struct Person
{
	const char * name;
	const int age;
};

void hard_work();
void chicken_and_egg();
void pets();

int main(int argc)
{
	Type type = argc ? person : animal;
	if (person == type)
	{
		Person fry = { "Fry", 26 };
	}

	hard_work();
	chicken_and_egg();
	pets();

	system("pause");
	return 0;
}

void hard_work()
{
	GoodWork = 0x77;
	prepare_one();
	work_one();
	GoodWork = 0xEE;
	prepare_two();
	work_two();
}

void chicken_and_egg()
{
	//using Zoo::Chicken;
	//typedef Zoo::Egg Egg;
	Chicken chicken;
	Egg egg;
	chicken.creator = &egg;
	egg.creator = &chicken;
	Egg* e = chicken.getCreator();
	Chicken* c = egg.getCreator();
	if (chicken.creator == c->creator
		&& egg.creator == e->creator)
	{
		using namespace std;
		cout << "the `Chicken and Egg' dilemma is solved!" << endl;
	}
}

void pets()
{
	using namespace Zoo;
	Cat cat;
	Dog dog;
	Pet * myCat = &cat;
	Pet * myDog = &dog;
	printf("myCat says `%s', gnows %sthing and has %d lifes\n",
		myCat->say(), myCat->gnaw() ? "every" : "no", myCat->lifes());
		printf("myDog says `%s', gnows %sthing and has %d lifes\n",
			myDog->say(), myDog->gnaw() ? "every" : "no", myDog->lifes());
}
