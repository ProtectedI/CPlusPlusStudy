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
	TestA(const TestA& other);// �������캯��
	~TestA(); // ��������

public:
	void Print();
};
