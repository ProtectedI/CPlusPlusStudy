#include "PreprocessorDirective.h"

// Ԥ����ָ��

namespace PreprocessorDirective
{
	void Print()
	{
		std::clog << PI << std::endl;
		std::clog << NAME << std::endl;

		// ��������
#ifdef DEBUG
		std::clog << "DEBUG is defined" << std::endl;
#else
		std::clog << "DEBUG is not defined" << std::endl;
#endif

		// ���������У�#if 0 �������
#if 0
		std::clog << "This line will not be compiled" << std::endl;
#endif

		std::clog << MAX(1, 2) << std::endl;
		LOG(Hello Wrold);
		LOG(Hello Wrold This is ����);
		LOG("TEst,aaa");
		LOG2("Hello", " World");
		//int i = CONCAT(1, 2);
		std::clog << MAX(CONCAT(1, 2), 3) << std::endl;

		// ���ú�
		std::clog << __LINE__ << std::endl; // �����ǰ�к�
		std::clog << __FILE__ << std::endl; // �����ǰ�ļ���
		std::clog << __DATE__ << std::endl; // �����������
		std::clog << __TIME__ << std::endl; // �������ʱ��
	}
}