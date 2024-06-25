#include "Friend.h"

A::A()
{
	bf = new B(10, "Hello");
	bf->Print();
}

void B::Print()
{
	std::clog << "a:" << a << " b:" << b << " c:" << (c ? "true" : "false") << std::endl;
}

void A::Change_A_All()
{
	bf->a = 20;
	bf->b = "World";
	bf->c = true;
	bf->Print();
}

void A::Change_A_Public()
{
	bf->c = false;
	bf->Print();
}
