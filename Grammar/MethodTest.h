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

// C++�� �����󣨳���������const���ε�struct��ֻ�����γ���������const���εĺ���:void test(xx) const��
// ��������һ������
//		���������治���޸ĳ�Ա������ֻ�ܶ�ȡ
//		������ڳ��������޸ĳ�Ա�������������Ա���������ùؼ���mutable���Ρ�
// ������struct������
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
		//this->a = b; // �����������޸ķ�mutable���εĳ�Ա�������������д���ᱨ��
		this->b = b;
	}

	void Print()
	{
		clog << "path:" << this << "------> a: " << a << ", b: " << b << endl;
	}
};

// C++�� �����󣨳���������const���ε�class��ֻ�����γ���������const���εĺ���:void test(xx) const��
// ��������һ������
//		���������治���޸ĳ�Ա������ֻ�ܶ�ȡ
//		������ڳ��������޸ĳ�Ա�������������Ա���������ùؼ���mutable���Ρ�
// ������class������
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
		//this->a = b; // �����������޸ķ�mutable���εĳ�Ա�������������д���ᱨ��
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
	// �����޸���ĳ�Ա����������һ����ͨ����ֱ���ں����ڲ��޸Ķ���ĳ�Ա�����������᲻��Ӱ�쵽ԭ���Ķ���
	void ChangeUtility(ClassMethodUtility utility);
	// �����޸���ĳ�Ա����������һ����ͨ���󣬴���һ�����������շ����������Ķ��󣬿����᲻��Ӱ�쵽ԭ���Ķ���
	ClassMethodUtility ChangeUtility(ClassMethodUtility utility, int a);
	// �����޸Ľṹ��ĳ�Ա����������һ���ṹ�����ֱ���ں����ڲ��޸Ķ���ĳ�Ա�����������᲻��Ӱ�쵽ԭ���Ķ���
	void ChangeUtility(StructMethodUtility utility);
	// �����޸Ľṹ��ĳ�Ա����������һ���ṹ����󣬴���һ�����������շ����������Ķ��󣬿����᲻��Ӱ�쵽ԭ���Ķ���
	StructMethodUtility ChangeUtility(StructMethodUtility utility, int a);
public:
	void TestMethod();
	// ���Գ�����ͳ�����
	// ������ֻ�ܷ��ʳ�����
	void TestConstObjAndConstMethod();
};
