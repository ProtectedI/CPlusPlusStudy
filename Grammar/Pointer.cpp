#include "Pointer.h"
#include<iostream>
using namespace std;

// ����һ��ֵ
void setValue(int* ptr, int value);

// ��ȡ�Զ���ָ��
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

	// ָ�����ͱ������洢���ǵ�ַ
	// ʹ��&�����ȡ��ַ
	// ʹ��*���������ָ��ָ��ĵ�ַ�е�ֵ������ָ���󣬿����޸ĵ�ַ�е�ֵ���߻�ȡ��ַ�е�ֵ��
	//int* aPtr = &a;   // ȡ��ַ
	//printf("a = %d\n", *aPtr);  // ���ʵ�ַ�е�ֵ
	//*aPtr = 10;   // �޸ĵ�ַ�е�ֵ
	//printf("aPtrValue = %d��a = %d\n", *aPtr, a);

	// ��ָ��
	int* nullPtr = NULL;
	//printf("ptr = %d\n", *ptr); // ��ָ����ʻᵼ�³������
	printf("ptr = %p\n", nullPtr);

	// �ж��Ƿ�Ϊ��ָ��
	// %b ��ʽ���������ֵ
	printf("ptr == NULL�� %s\n", nullPtr ? "��" : "��");
	printf("-----------------------------------------\n");

	// ָ��Ӧ�ã�����

	int arr[5] = {}; // �������ƴ���������Ԫ�صĵ�ַ
	int* ptr = arr;

	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d] value = %d��arr[%d] address = %p��arrPtr = %p\n", i, arr[i], i, &arr[i], ptr);
		*ptr = i * 2;

		if (ptr < &arr[4])
			ptr++;
	}

	printf("----------\n");
	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d] value = %d��arr[%d] address = %p\n", i, arr[i], i, &arr[i]);
	}

	// �����������ƾʹ��������һ��Ԫ�صĵ�ַ���������һ��Ԫ�ص�ָ��
	// ��������Ĳ����� ��ȡ���޸������һ��Ԫ�ص�ֵ
	*arr = 3;
	printf("arr[0] = %d\n", arr[0]);

	// ��ȡ���޸����������Ԫ�ص�ֵ
	*(arr + 2) = 5;
	printf("arr[2] = %d\n", arr[2]);

	printf("-----------------------------------------\n");

	// ָ������
	int* arrPtr[5] = {};
	for (int i = 0; i < 5; i++)
	{
		arrPtr[i] = &arr[i];
	}

	// ����ָ�������ֵ
	for (int i = 0; i < 5; i++)
	{
		printf("arrPtr[%d] value = %d\n", i, *arrPtr[i]);
	}

	printf("-----------------------------------------\n");

	// ָ���ָ�룬ȡ��ַ����һ��һ��ȡ��������ʹ��&&���﷨��ȡ
	// ������type** name;
	// ȡֵ��**name
	int ppValue = 5;
	int* pPpValue = &ppValue;
	int** ppPpValue = &pPpValue;
	printf("v1 = %d\n", ppValue);
	printf("v2 = %d\n", *pPpValue);
	printf("v3 = %d\n", **ppPpValue);

	// �����д���ָ�����
	setValue(pPpValue, 20);
	printf("v1 = %d\n", ppValue);

	int* customPtr = getCustomPtr(5);
	*customPtr = 110;
	printf("customPtr value = %d\n", *customPtr);

	printf("-----------------------------------------\n");
	// ����
	int& ref1 = getRef(22);
	printf("ref1 value:%d\n", ref1);
	ref1 = 15;
	printf("ref1 value:%d\n", ref1);

	setValue2(ref1, 33);
	printf("ref1 value:%d\n", ref1);

	auto addResult = add(ref1, 5);
	printf("ref1 value:%d addResult:%d\n", ref1, addResult);

	printf("-----------------------------------------\n");
	// ����ָ�룺�����޸�ָ��ָ�򣬵������޸�ָ���Ӧ��ֵ
	int constPtrValue = 5;
	const int* cosntPtr = &constPtrValue;
	//*cosntPtr = 15;		// ������Ϊ
	cosntPtr = customPtr;	// ��ȷ

	// ָ�볣���������޸�ָ���Ӧ��ֵ�����ǲ����޸�ָ���ָ��
	int* const ptrConst = &constPtrValue;
	*ptrConst = 15;			// ��ȷ
	//ptrConst = customPtr;	// ����
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