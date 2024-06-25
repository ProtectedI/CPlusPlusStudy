#include "NewAndDelete.h"

void NewAndDelete::NewTest()
{
	// 在堆上分配内存
	int* p = new int(10);

	clog << "Address of p: " << p << endl;
	clog << "Value of p: " << *p << endl;

	// 引用
	int& r = *p;
	clog << "Value of r: " << r << endl;
	r = 20;

	clog << "Value of r: " << r << endl;
	clog << "Value of p: " << *p << endl;

	int i1 = 0;
	const int& cr = i1; // 常量引用,不能修改i1的值
	//cr = 20;
	int& const cr2 = i1; // 引用常量，可以修改i1的值
	cr2 = 20;

	// 释放内存
	delete p;
}

class TestStruct
{
public:
	TestStruct(int a, int b) : a(a), b(b) {}
	int a;
	int b;
};

void Test(const TestStruct& r)
{
	// 打印r的字段的值
	clog << "a: " << r.a << endl;
	clog << "b: " << r.b << endl;
}

void Test2(int a, int b = 20, int c = 30) {}

void Test3(const char* str)
{
	clog << "str: " << str << endl;
	str = "NI";
}

void NewAndDelete::DeleteTest()
{
	// 引用的本质是指针常量，可以修改值，但不能修改指向，因此可以用delete释放引用
	int i = 5;
	int& r = i;

	// 常量引用，主要用来修饰函数参数，不能修改参数的值（防止误操作）


	//delete& r; // 释放引用的内存，而不是指针的内存

	TestStruct ts(10, 20);
	Test(ts); // 调用函数，参数为引用，函数内修改引用的值，不会影响原变量的值

	Test2(10);

	char str[] = "Hello";
	Test3(str);
	clog << "str: " << str << endl; // 原变量的值也会改变
}