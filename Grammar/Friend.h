#pragma once

#include <iostream>

class B;
class A
{
public:
	B* bf;
	A();
	void Change_A_All();
	void Change_A_Public();
};

class B
{
	friend void A::Change_A_All();
	int a;
	std::string b;
public:
	bool c;
	B(int x, std::string y) : a(x), b(y)
	{
		c = false;
	}
	void Print();
};