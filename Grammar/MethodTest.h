#pragma once

#include <iostream>

using namespace std;

struct StructMethodUtility
{
private:
	int age;
	float height;
	const char* name;

public:
	StructMethodUtility() : age(0), height(0.0), name("StructMethodUtility") {}
	void ChangeProperty(int a, float b, const char* c)
	{
		age = a;
		height = b;
		name = c;
	}

	void Print();
};

class ClassMethodUtility
{
private:
	int age;
	float height;
	const char* name;
public:
	ClassMethodUtility() : age(0), height(0.0), name("ClassMethodUtility") {}
	void ChangeProperty(int a, float b, const char* c)
	{
		age = a;
		height = b;
		name = c;
	}

	void Print()
	{
		clog << "path:" << this << "------> age: " << age << ", height: " << height << ", name: " << name << endl;
	}
};

// C++中 常对象（常量对象，用const修饰的struct）只能修饰长函数（用const修饰的函数:void test(xx) const）
// 常函数有一个规则：
//		长函数里面不能修改成员变量，只能读取
//		如果想在常函数中修改成员变量，那这个成员变量必须用关键字mutable修饰。
// 这里用struct来测试
struct A_Struct_MethodTest
{
private:
	int a;
	mutable int b;

public:
	void ChangeA(int a)
	{
		this->a = a;
		b = a + 1;
	}

	void ChangeB(int b) const
	{
		//this->a = b; // 常函数不能修改非mutable修饰的成员变量，所以这行代码会报错
		this->b = b;
	}

	void Print()
	{
		clog << "path:" << this << "------> a: " << a << ", b: " << b << endl;
	}
};

// C++中 常对象（常量对象，用const修饰的class）只能修饰长函数（用const修饰的函数:void test(xx) const）
// 常函数有一个规则：
//		长函数里面不能修改成员变量，只能读取
//		如果想在常函数中修改成员变量，那这个成员变量必须用关键字mutable修饰。
// 这里用class来测试
class A_Class_MethodTest
{
	int a;
	mutable int b;

public:
	void ChangeA(int a)
	{
		this->a = a;
		b = a + 1;
	}

	void ChangeB(int b) const
	{
		//this->a = b; // 常函数不能修改非mutable修饰的成员变量，所以这行代码会报错
		this->b = b;
	}

	void Print()
	{
		clog << "path:" << this << "------> a: " << a << ", b: " << b << endl;
	}
};

class MethodTest
{
private:
	// 测试修改类的成员变量，传入一个普通对象，直接在函数内部修改对象的成员变量，看看会不会影响到原来的对象
	void ChangeUtility(ClassMethodUtility utility);
	// 测试修改类的成员变量，传入一个普通对象，传入一个参数，最终返回这个传入的对象，看看会不会影响到原来的对象
	ClassMethodUtility ChangeUtility(ClassMethodUtility utility, int a);
	// 测试修改结构体的成员变量，传入一个结构体对象，直接在函数内部修改对象的成员变量，看看会不会影响到原来的对象
	void ChangeUtility(StructMethodUtility utility);
	// 测试修改结构体的成员变量，传入一个结构体对象，传入一个参数，最终返回这个传入的对象，看看会不会影响到原来的对象
	StructMethodUtility ChangeUtility(StructMethodUtility utility, int a);
public:
	void TestMethod();
	// 测试常对象和常函数
	// 长对象只能访问长函数
	void TestConstObjAndConstMethod();
};
