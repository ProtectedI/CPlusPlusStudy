#include "Pointer.h"
#include<iostream>
using namespace std;

// 设置一个值
void setValue(int* ptr, int value);

// 获取自定义指针
int* getCustomPtr(int value);

void setValue2(int& ref, int value);
int& getRef(int value);

int add(int add1, int add2)
{
	return add1 + add2;
}

void TestPointer()
{
	//int a = 5;
	//printf("a = %d\n", a);

	// 指针类型变量，存储的是地址
	// 使用&运算符取地址
	// 使用*运算符访问指针指向的地址中的值（即所指对象，可以修改地址中的值或者获取地址中的值）
	//int* aPtr = &a;   // 取地址
	//printf("a = %d\n", *aPtr);  // 访问地址中的值
	//*aPtr = 10;   // 修改地址中的值
	//printf("aPtrValue = %d，a = %d\n", *aPtr, a);

	// 空指针
	int* nullPtr = NULL;
	//printf("ptr = %d\n", *ptr); // 空指针访问会导致程序崩溃
	printf("ptr = %p\n", nullPtr);

	// 判断是否为空指针
	// %b 格式化输出布尔值
	printf("ptr == NULL？ %s\n", nullPtr ? "否" : "是");
	printf("-----------------------------------------\n");

	// 指针应用，数组

	int arr[5] = {}; // 数组名称代表数组首元素的地址
	int* ptr = arr;

	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d] value = %d，arr[%d] address = %p，arrPtr = %p\n", i, arr[i], i, &arr[i], ptr);
		*ptr = i * 2;

		if (ptr < &arr[4])
			ptr++;
	}

	printf("----------\n");
	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d] value = %d，arr[%d] address = %p\n", i, arr[i], i, &arr[i]);
	}

	// 由于数组名称就代表数组第一个元素的地址，即数组第一个元素的指针
	// 所以下面的操作是 获取并修改数组第一个元素的值
	*arr = 3;
	printf("arr[0] = %d\n", arr[0]);

	// 获取并修改数组第三个元素的值
	*(arr + 2) = 5;
	printf("arr[2] = %d\n", arr[2]);

	printf("-----------------------------------------\n");

	// 指针数组
	int* arrPtr[5] = {};
	for (int i = 0; i < 5; i++)
	{
		arrPtr[i] = &arr[i];
	}

	// 数组指针数组的值
	for (int i = 0; i < 5; i++)
	{
		printf("arrPtr[%d] value = %d\n", i, *arrPtr[i]);
	}

	printf("-----------------------------------------\n");

	// 指针的指针，取地址必须一个一个取，即不能使用&&的语法来取
	// 声明：type** name;
	// 取值：**name
	int ppValue = 5;
	int* pPpValue = &ppValue;
	int** ppPpValue = &pPpValue;
	printf("v1 = %d\n", ppValue);
	printf("v2 = %d\n", *pPpValue);
	printf("v3 = %d\n", **ppPpValue);

	// 函数中传入指针参数
	setValue(pPpValue, 20);
	printf("v1 = %d\n", ppValue);

	int* customPtr = getCustomPtr(5);
	*customPtr = 110;
	printf("customPtr value = %d\n", *customPtr);

	printf("-----------------------------------------\n");
	// 引用
	int& ref1 = getRef(22);
	printf("ref1 value:%d\n", ref1);
	ref1 = 15;
	printf("ref1 value:%d\n", ref1);

	setValue2(ref1, 33);
	printf("ref1 value:%d\n", ref1);

	auto addResult = add(ref1, 5);
	printf("ref1 value:%d addResult:%d\n", ref1, addResult);

	printf("-----------------------------------------\n");
	// 常量指针：可以修改指针指向，但不能修改指针对应的值
	int constPtrValue = 5;
	const int* cosntPtr = &constPtrValue;
	//*cosntPtr = 15;		// 错误行为
	cosntPtr = customPtr;	// 正确

	// 指针常量：可以修改指针对应的值，但是不能修改指针的指向
	int* const ptrConst = &constPtrValue;
	*ptrConst = 15;			// 正确
	//ptrConst = customPtr;	// 错误
}

void setValue(int* ptr, int value)
{
	*ptr = value;
}

int* getCustomPtr(int value)
{
	printf("value:%d\n", value);
	value++;
	printf("value:%d\n", value);
	return &value;
}

void setValue2(int& ref, int value)
{
	ref += value;
}

int& getRef(int value)
{
	return value;
}