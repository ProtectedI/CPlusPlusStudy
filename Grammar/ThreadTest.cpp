#include "ThreadTest.h"
#include <windows.h>

void ThreadHandle()
{
	int i = 0;
	while (true)
	{
		std::cout << "Thread is running...��i = " << ++i << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));

		// ������¼����ϵ�ESC�������˳��߳�
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
	}
}

void TestThread()
{
	std::thread t(ThreadHandle);
	t.join();
}
