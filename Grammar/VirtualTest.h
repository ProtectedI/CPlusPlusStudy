#pragma once

#include <iostream>

class Parent
{
public:
	// 虚函数
	virtual void Test()
	{
		std::clog << "Parent::Test()" << std::endl;
	}

	// 纯虚函数，相当于C#中用abstract修饰的方法
	virtual void Test2() = 0;
};

class ChildA :public Parent
{
public:
	void Test() override
	{
		std::clog << "ChildA::Test()" << std::endl;
	}

	void Test2() override;
};

class ChildB :public Parent
{
public:
	void Test() override
	{
		std::clog << "ChildB::Test()" << std::endl;
	}

	void Test2() override;
};