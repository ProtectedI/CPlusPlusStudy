#pragma once

#include <iostream>
// 预处理指令

namespace PreprocessorDirective
{
	// #define 通常用于定义符号常量，该符号常量通常被称为宏。
	// 定义宏格式：define 宏名 值
#define PI 3.1415926
#define NAME "JOIN"
#define DEBUG "DEBUG"

// # 和 ##
	// #：会将值替换为一个字符串
	// ##：连接两个宏名, 并将值替换为一个字符串

#define LOG(msg) (std::clog <<#msg<<std::endl)
#define LOG2(msg, msg2) (std::clog <<msg##msg2<<std::endl)
#define CONCAT(a, b) a##b

// 定义一个参带有参数的宏
#define MAX(a,b) (a>b?a:b)

	void Print();
}
