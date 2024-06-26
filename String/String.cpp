#include <iostream>
#include <string>

int main()
{
	std::string str1;
	std::clog << "str1: " << str1 << std::endl;
	std::clog << "str1 is empty: " << (str1.empty() ? "true" : "false") << std::endl;
	str1.append("Hello, world!");
	std::clog << "str1: " << str1 << std::endl;
	std::clog << "str1 is empty: " << (str1.empty() ? "true" : "false") << std::endl;
	str1.append("Test aaa", 4);
	std::clog << "str1: " << str1 << std::endl;
	str1 += " aaa";
	std::clog << "str1: " << str1 << std::endl;
	str1.insert(str1.find("Test"), " ");
	std::clog << "str1: " << str1 << std::endl;
	str1.replace(str1.find("aaa"), 3, "bbb");
	std::clog << "str1: " << str1 << std::endl;

	// 查找 Test 在 str1 中的位置
	std::clog << "Test is at position " << str1.find("Test") << std::endl;
	// 查找 aaa 在 str1 中的位置
	std::clog << "aaa is at position:" << str1.find("aaa") << std::endl;
	std::clog << "ddd is at position:" << (str1.find("ddd") == std::string::npos ? "not found" : "found") << std::endl;
	std::cin.get();
}
