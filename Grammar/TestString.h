#pragma once

#include <iostream>
#include <string>

using namespace std;

// 合并字符串，并打印字，返回合并结果
string PrintString(string str1, string str2);

// 查找指定字符串在源字符串中出现的位置
// 返回结果：int
int FindString(string source, string find, bool isRight = false);

// 测试字符串的操作
void TestString(string source);