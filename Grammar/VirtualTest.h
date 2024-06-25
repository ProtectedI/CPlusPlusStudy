#pragma once

#include <iostream>

class Parent
{
public:
	// �麯��
	virtual void Test()
	{
		std::clog << "Parent::Test()" << std::endl;
	}

	// ���麯�����൱��C#����abstract���εķ���
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