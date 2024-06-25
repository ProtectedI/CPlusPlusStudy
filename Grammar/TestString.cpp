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

	// ����ַ���
	cout << source << endl;
	// ����ַ�������
	cout << source.length() << endl;
	// ����ַ����ĵ�2���ַ�
	cout << source[1] << endl;
	// ����ַ����ĵ�2����5���ַ�
	cout << source.substr(1, 4) << endl;
	// ����ַ����ĵ�2�����һ���ַ�
	cout << source.substr(1) << endl;
	// ����ַ��������һ���ַ�
	cout << source.back() << endl;
	// ����ַ����ĵ�һ���ַ�
	cout << source.front() << endl;
	// ����ַ����ĵ�2���ַ���ASCII��
	cout << (int)source[1] << endl;
	// �����ַ���
	source.insert(1, "W");
	// ����������ַ���
	cout << source << endl;
	// ɾ���ַ���
	source.erase(1, 2);
	// ���ɾ������ַ���
	cout << source << endl;
}
