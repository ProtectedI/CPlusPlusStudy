#pragma once

#include <fstream>
#include <iostream>
#include <string>

class FileMgr
{
private:
	std::fstream fs;
public:
	FileMgr(std::string filePath, std::ios_base::openmode mode);
	~FileMgr();

	// ��ȡ��������
	std::string ReadAll();

	// ���ļ�β��׷��һ������
	void AppendLine(const std::string& content);

	// ���л���
	template<typename T>
	void Serialize(T& obj)
	{
		fs.write((char*)&obj, sizeof(T));
	}

	// �����л���
	template<typename T>
	T Deserialize()
	{
		char* data = new char[sizeof(T)];
		fs.read(data, sizeof(T));
		T obj = *(T*)(data);
		return obj;
	}
};

class Binary_C
{
public:
	int a;
	float b;
	char c;
	Binary_C() : a(rand() % 1000), b(rand() / 1000), c('y')
	{
		Print();
	}
	void Print()
	{
		std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	}
};

class Binary_D
{
public:
	int a;
	float b;
	std::string c;
	Binary_D() : a(rand() % 1000), b(rand() / 1000), c("Hello World!") {}
	void Print()
	{
		std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	}
};