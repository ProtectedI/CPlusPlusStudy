#define _CRT_SECURE_NO_WARNINGS
#include "UniTest.h"

void TestString()
{
	string str = PrintString("���", "���磡");
	int index = FindString(str, "��");
	TestString("Hello, World!!");
	printf("-----------------------\n");
}

void CopyConstruct()
{
	TestA testA;
	testA.age = 5;
	testA.name = "Tom";
	testA.next = new TestA;
	testA.Print();

	TestA testB(testA);
	testB.Print();
}

void Pointer()
{
	TestPointer();
}

void Friend()
{
	A a;
	a.Change_A_All();
	a.Change_A_Public();
}

void VirtualTest()
{
	ChildA a;
	ChildB b;
	Parent* obj = &a;
	obj->Test();
	obj->Test2();
	obj = &b;
	obj->Test();
	obj->Test2();
}

void TimeTest()
{
	// ��ǰ��ʱ���
	time_t now = time(0);
	clog << ctime(&now) << endl;

	// �� now ת��Ϊ tm �ṹ
	tm* gmtm = gmtime(&now);
	printf("��ʽ��ʱ�䣺%02d/%02d/%02d %02d:%02d:%02d\n", gmtm->tm_year + 1900, gmtm->tm_mon + 1, gmtm->tm_mday, gmtm->tm_hour + 8, gmtm->tm_min, gmtm->tm_sec);
}

void IOTest()
{
	/*FileMgr file("F:\\DefaultPos\\Documents\\��װǰ.txt", std::ios::in | std::ios::app);
	clog << file.ReadAll() << endl;

	clog << "--------------Write--------------" << endl;

	while (true)
	{
		string input;
		cout << "������ָ�";
		getline(cin, input);
		if (input == "exit")
			break;
		else if (input == "write")
		{
			file.AppendLine("Hello World");
			clog << "Writem success!" << endl;
		}
	}*/

	// ��д�����Ʋ���

	// ��
	FileMgr file("binary.dat", std::ios::in | std::ios::out | std::ios::binary);
	Binary_C data = file.Deserialize<Binary_C>();
	data.Print();

	// д
	/*Binary_C data2;
	file.Serialize<Binary_C>(data2);*/
}

void NewAndDeleteTest()
{
	NewAndDelete test;
	test.NewTest();
	test.DeleteTest();
	// ��������ķ�ʽ

	// ���ŷ�
	// NewAndDelete test(xx)
	// NewAndDelete test;
	// NewAndDelete test(xx);

	// ��ʾ��
	// NewAndDelete test;
	// NewAndDelete test = NewAndDelete(xx);

	// ��������
	// NewAndDelete(xx)

	// ��ʵ�δ��ݸ��β��ǻ������Ŀ������캯��
}

void MethodTestUnit()
{
	MethodTest test;
	//test.TestMethod();
	test.TestConstObjAndConstMethod();
}

void DuoTaiTest()
{
	DuoTai::Animal* anim = new DuoTai::Dog("Tim");
	DuoTai::PrintAnimal(*anim);
	delete	anim;
	anim = new DuoTai::Cat("Kitty");
	DuoTai::PrintAnimal(*anim);
	delete	anim;
}

void TemplateTest()
{
	Template::Print<int>(10);
	Template::Print<float>(10.2f);
	Template::Print<double>(10.33);
	Template::Print<char>('a');

	std::clog << "------------------------" << std::endl;

	Template::MyClass<int> cls(1);
	Template::MyClass<float> cls2(2.33333);
	Template::MyClass<double> cls3(5.55555);
	Template::MyClass<char> cls4('b');
	cls.Print();
	cls2.Print();
	cls3.Print();
	cls4.Print();
}

void PreprocessorDirectiveTest()
{
	PreprocessorDirective::Print();
}

void ThreadTest22()
{
	std::clog << "ThreadTest Start" << std::endl;
	TestThread();
	std::clog << "ThreadTest End" << std::endl;
}
