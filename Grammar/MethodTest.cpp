#include "MethodTest.h"

void MethodTest::ChangeUtility(ClassMethodUtility utility)
{
	utility.ChangeProperty(20, 170, "void MethodTest::ChangeUtility(ClassMethodUtility utility)");
	utility.Print();
}

ClassMethodUtility MethodTest::ChangeUtility(ClassMethodUtility utility, int a)
{
	utility.ChangeProperty(a, 180, "ClassMethodUtility MethodTest::ChangeUtility(ClassMethodUtility utility, int a)");
	utility.Print();
	return utility;
}

void MethodTest::ChangeUtility(StructMethodUtility utility)
{
	utility.ChangeProperty(40, 200, "void MethodTest::ChangeUtility(StructMethodUtility utility)");
	utility.Print();
}

StructMethodUtility MethodTest::ChangeUtility(StructMethodUtility utility, int a)
{
	utility.ChangeProperty(a, 210, "StructMethodUtility MethodTest::ChangeUtility(StructMethodUtility utility, int a)");
	utility.Print();
	return utility;
}

void MethodTest::TestMethod()
{
	// 修改结构体属性
	StructMethodUtility struct_utility;
	struct_utility.Print();
	clog << "-----------------------------------------" << endl;
	ChangeUtility(struct_utility);
	struct_utility.Print();
	clog << "-----------------------------------------" << endl;
	auto newStructUtility = ChangeUtility(struct_utility, 10);
	newStructUtility.Print();
	struct_utility.Print();
	clog << "-----------------------------------------" << endl << endl << endl;


	// 修改类属性
	ClassMethodUtility class_utility;
	class_utility.Print();
	clog << "-----------------------------------------" << endl;
	ChangeUtility(class_utility);
	class_utility.Print();
	clog << "-----------------------------------------" << endl;
	auto newClassUtility = ChangeUtility(class_utility, 20);
	newClassUtility.Print();
	class_utility.Print();
}

void MethodTest::TestConstObjAndConstMethod()
{
	A_Struct_MethodTest a_struct_method_test;
	a_struct_method_test.Print();
	a_struct_method_test.ChangeA(5);
	a_struct_method_test.Print();
	a_struct_method_test.ChangeB(10);
	a_struct_method_test.Print();

	clog << "------------------------------------" << endl;

	A_Class_MethodTest a_class_method_test;
	a_class_method_test.Print();
	a_class_method_test.ChangeA(15);
	a_class_method_test.Print();
	a_class_method_test.ChangeB(20);
	a_class_method_test.Print();
	clog << "------------------------------------" << endl << endl << endl;
	// 声明一个常对象
	const A_Struct_MethodTest& const_a_struct_method_test = a_struct_method_test;
	const_a_struct_method_test.ChangeB(33);
	a_struct_method_test.Print();
	clog << "------------------------------------" << endl;
	const A_Class_MethodTest& const_a_class_method_test = a_class_method_test;
	const_a_class_method_test.ChangeB(44);
	a_class_method_test.Print();
	// 引用的本质是指针常量，只能修改值，不能修改指向
}

void StructMethodUtility::Print()
{
	clog << "path:" << this << "------> age: " << age << ", height: " << height << ", name: " << name << endl;
}