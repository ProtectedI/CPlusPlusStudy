#pragma once

#include <iostream>

namespace Template
{
	// 模板函数（泛型函数）定义
	template<typename T>
	void Print(T value);

	// 模板类（泛型类）定义
	template<class T>
	class MyClass
	{
	public:
		MyClass(T value);
		void Print();
	private:
		T m_value;
	};

	template<typename T>
	void Print(T value)
	{
		// 打印T的类型名称和值
		std::cout << typeid(T).name() << " " << value << std::endl;
	}

	template<class T>
	MyClass<T>::MyClass(T value)
	{
		this->m_value = value;
	}

	template<class T>
	void MyClass<T>::Print()
	{
		// 打印T的类型名称和值
		std::cout << typeid(T).name() << " " << m_value << std::endl;
	}
}