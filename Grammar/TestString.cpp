#include "TestString.h"

string PrintString(string str1, string str2)
{
	string result(str1);
	result.append(",");
	result.append(str2);
	clog << result << endl;
	return result;
}

int FindString(string source, string find, bool isRight)
{
	printf("source:%s find:%s isRight:%s\n", source.c_str(), find.c_str(), isRight ? "true" : "false");
	auto result = isRight ? source.rfind(find) : source.find(find);
	printf("result:%d\n", result);
	return result;
}

void TestString(string source)
{
	if (source.empty()) return;

	// 输出字符串
	cout << source << endl;
	// 输出字符串长度
	cout << source.length() << endl;
	// 输出字符串的第2个字符
	cout << source[1] << endl;
	// 输出字符串的第2到第5个字符
	cout << source.substr(1, 4) << endl;
	// 输出字符串的第2到最后一个字符
	cout << source.substr(1) << endl;
	// 输出字符串的最后一个字符
	cout << source.back() << endl;
	// 输出字符串的第一个字符
	cout << source.front() << endl;
	// 输出字符串的第2个字符的ASCII码
	cout << (int)source[1] << endl;
	// 插入字符串
	source.insert(1, "W");
	// 输出插入后的字符串
	cout << source << endl;
	// 删除字符串
	source.erase(1, 2);
	// 输出删除后的字符串
	cout << source << endl;
}
