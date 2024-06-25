#include "CopyConstruct.h"

TestA::TestA()
{
	age = 0;
	name = "";
	next = NULL;
}

TestA::TestA(const TestA& other)
{
	age = other.age;
	name = other.name;
	next = new TestA;
}

TestA::~TestA()
{
	printf("Clear");
}

void TestA::Print()
{
	printf("age:%d path:%p, name:%s path:%p, next:%p\n", age, &age, name.c_str(), &name, next);
}