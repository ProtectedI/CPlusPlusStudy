#include "PreprocessorDirective.h"

// 预处理指令

namespace PreprocessorDirective
{
	void Print()
	{
		std::clog << PI << std::endl;
		std::clog << NAME << std::endl;

		// 条件编译
#ifdef DEBUG
		std::clog << "DEBUG is defined" << std::endl;
#else
		std::clog << "DEBUG is not defined" << std::endl;
#endif

		// 条件编译中：#if 0 不会编译
#if 0
		std::clog << "This line will not be compiled" << std::endl;
#endif

		std::clog << MAX(1, 2) << std::endl;
		LOG(Hello Wrold);
		LOG(Hello Wrold This is 。。);
		LOG("TEst,aaa");
		LOG2("Hello", " World");
		//int i = CONCAT(1, 2);
		std::clog << MAX(CONCAT(1, 2), 3) << std::endl;

		// 内置宏
		std::clog << __LINE__ << std::endl; // 输出当前行号
		std::clog << __FILE__ << std::endl; // 输出当前文件名
		std::clog << __DATE__ << std::endl; // 输出编译日期
		std::clog << __TIME__ << std::endl; // 输出编译时间
	}
}