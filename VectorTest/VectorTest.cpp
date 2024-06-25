#include <iostream>
#include <vector>

int main()
{
	std::vector<int> myVector;

	myVector.push_back(10);
	myVector.push_back(20);
	myVector.push_back(30);

	for (int i = 0; i < myVector.size(); i++)
		std::clog << myVector[i] << " ";

	std::clog << std::endl;

	// 移除单个元素，这里删除第2各元素20
	myVector.erase(myVector.begin() + 1);
	//myVector.erase(myVector.end() - 1);//删除最后一个元素，法一
	myVector.pop_back();// 删除最后一个元素，法二
	for (int item : myVector)
		std::clog << item << " ";
	std::clog << std::endl;

	// 向量的长度
	std::clog << "Vector size: " << myVector.size() << std::endl;

	// 修改第一个元素的值
	myVector[0] = 100;
	for (int item : myVector)
		std::clog << item << " ";
	std::clog << std::endl;

	// 清空向量
	myVector.clear();
	std::clog << "Vector size: " << myVector.size() << std::endl;

	// 范围循环
	for (int item : { 1, 2, 3, 4, 5 })
		std::clog << item << " ";
	std::clog << std::endl;

	// clog 和 cout 的区别
	// clog 是 std::clog，是一个 std::ostream 对象，用于输出到控制台，但它是缓冲区，只有缓冲区满了才会输出到控制台。
	// cout 是 std::cout，是一个 std::ostream 对象，用于输出到控制台，但它是立即输出，即使缓冲区满了也会立即输出。

	std::cin.get();
}
