#pragma once

#include <iostream>
#include <string>

using namespace std;

class TestA
{
public:
	int age;
	string name;
	TestA* next;

public:
	TestA();
	TestA(const TestA& other);// 拷贝构造函数
	~TestA(); // 析构函数

public:
	void Print();
};
