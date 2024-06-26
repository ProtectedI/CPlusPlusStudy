#include <iostream>
#include <vector>

int main()
{
	std::vector<int> myVector(10, 5);
	myVector.reserve(100000); // 预分配空间

	std::clog << "size:" << myVector.size() << " capacity:" << myVector.capacity() << std::endl;

	// 巧用swap缩小容量，这是一种优化方式，利用匿名对象，将原向量的容量交换到新向量上，这样就不需要重新分配内存了
	std::vector<int>(myVector).swap(myVector);
	std::clog << "size:" << myVector.size() << " capacity:" << myVector.capacity() << std::endl;


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
	std::clog << "size: " << myVector.size() << std::endl;



	std::cin.get();
}
