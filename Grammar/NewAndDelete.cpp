#include "NewAndDelete.h"

void NewAndDelete::NewTest()
{
	// �ڶ��Ϸ����ڴ�
	int* p = new int(10);

	clog << "Address of p: " << p << endl;
	clog << "Value of p: " << *p << endl;

	// ����
	int& r = *p;
	clog << "Value of r: " << r << endl;
	r = 20;

	clog << "Value of r: " << r << endl;
	clog << "Value of p: " << *p << endl;

	int i1 = 0;
	const int& cr = i1; // ��������,�����޸�i1��ֵ
	//cr = 20;
	int& const cr2 = i1; // ���ó����������޸�i1��ֵ
	cr2 = 20;

	// �ͷ��ڴ�
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
	// ��ӡr���ֶε�ֵ
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
	// ���õı�����ָ�볣���������޸�ֵ���������޸�ָ����˿�����delete�ͷ�����
	int i = 5;
	int& r = i;

	// �������ã���Ҫ�������κ��������������޸Ĳ�����ֵ����ֹ�������


	//delete& r; // �ͷ����õ��ڴ棬������ָ����ڴ�

	TestStruct ts(10, 20);
	Test(ts); // ���ú���������Ϊ���ã��������޸����õ�ֵ������Ӱ��ԭ������ֵ

	Test2(10);

	char str[] = "Hello";
	Test3(str);
	clog << "str: " << str << endl; // ԭ������ֵҲ��ı�
}