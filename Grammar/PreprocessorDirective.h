#pragma once

#include <iostream>
// Ԥ����ָ��

namespace PreprocessorDirective
{
	// #define ͨ�����ڶ�����ų������÷��ų���ͨ������Ϊ�ꡣ
	// ������ʽ��define ���� ֵ
#define PI 3.1415926
#define NAME "JOIN"
#define DEBUG "DEBUG"

// # �� ##
	// #���Ὣֵ�滻Ϊһ���ַ���
	// ##��������������, ����ֵ�滻Ϊһ���ַ���

#define LOG(msg) (std::clog <<#msg<<std::endl)
#define LOG2(msg, msg2) (std::clog <<msg##msg2<<std::endl)
#define CONCAT(a, b) a##b

// ����һ���δ��в����ĺ�
#define MAX(a,b) (a>b?a:b)

	void Print();
}
