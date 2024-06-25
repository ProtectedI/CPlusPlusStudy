#include "IOTest.h"

FileMgr::FileMgr(std::string filePath, std::ios_base::openmode mode)
{
	fs.open(filePath.c_str(), mode);
	if (!fs.is_open())
		std::cerr << "Failed to open file: " << filePath << std::endl;
	std::clog << "FileMgr created, file:" << filePath << std::endl;
}

FileMgr::~FileMgr()
{
	fs.close();
	std::clog << "FileMgr destroyed" << std::endl;
}

std::string FileMgr::ReadAll()
{
	// ��1
	// fs��λ���ļ���ͷ����ͷ����β
	/*fs.seekg(0, std::ios::beg);
	std::string result((std::istreambuf_iterator<char>(fs)), std::istreambuf_iterator<char>());*/

	// ��2�����ֶ�ȡ
	/*std::string result2;
	char c;
	while (fs.get(c))
		result2 += c;
	return result2;*/

	// ��3�����ж�ȡ
	std::string result3;
	std::string line;
	while (std::getline(fs, line))
		result3 += line + "\n";
	return result3;
}

void FileMgr::AppendLine(const std::string& content)
{
	fs << content << std::endl;
}
