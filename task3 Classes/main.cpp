#include "String.hpp"

int main(int argc, char * argv[])
{
	String s1, s2("Hello!");
	s1.print();
	s2.print();
	s1 = s2;
	s1.print();
	String s4 = "Bye!";
	s1 = s4;
	s4.print();
	s1.print();
}
