// Mtask3_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class Animal
{
protected:
	int mWeight;
	int mAge;
public:
	Animal()
		: mAge(0)
		, mWeight(0)
	{
	}

	Animal(int age, int height)
		: mAge(age)
		, mWeight(height)
	{
	}

	void grow()
	{
		mAge++;
		mWeight++;
	}

	virtual ~Animal()
	{
	}
};

class Mammal : virtual public Animal
{

};

class FlyingAnimal : virtual public Animal
{
public:
	virtual void fly()
	{
		cout << "Flying" << endl;
	}

};

class WaterAnimal : virtual public Animal
{

};

class Fish : virtual public WaterAnimal
{

};

class Dolphin : virtual public WaterAnimal, virtual public Mammal
{

};

class FlyingDolphin : virtual public Dolphin, virtual public FlyingAnimal
{
public:
	virtual void fly()
	{
		cout << "My age is : " << mWeight << endl;
		if (mWeight > 3)
		{
			cout << "Too big for flying :(" << endl;
			return;
		}
		if (mAge > 1)
			FlyingAnimal::fly();
		else
			cout << "I can't fly" << endl;
	}

};

int main(int argc, char **argv)
{
	FlyingDolphin flyingDolphin;

	Animal* animal = &flyingDolphin;
	if (animal)
		cout << "Flying dolphin is an animal!" << endl;
	Dolphin *dolphin = dynamic_cast<Dolphin*>(animal);
	if (dolphin)
		cout << "Flying dolphin is a dolphin!" << endl;
	WaterAnimal *waterAnimal = dynamic_cast<WaterAnimal*>(animal);
	if (waterAnimal)
		cout << "Flying dolphin is a water animal!" << endl;
	FlyingAnimal *flyingAnimal = dynamic_cast<FlyingAnimal*>(animal);
	if (flyingAnimal)
		cout << "Flying dolphin is a flying animal!" << endl;
	Fish *fish = dynamic_cast<Fish*>(animal);
	if (!fish)
		cout << "Flying dolphin isn't a fish!" << endl;
	cout << endl;

	dolphin->grow();
	flyingDolphin.fly();
	flyingAnimal->grow();
	flyingDolphin.fly();
	waterAnimal->grow();
	flyingDolphin.fly();
	flyingDolphin.grow();
	flyingDolphin.fly();

	system("pause");
}
