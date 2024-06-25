#pragma once

#include <iostream>

namespace Template
{
	// ģ�庯�������ͺ���������
	template<typename T>
	void Print(T value);

	// ģ���ࣨ�����ࣩ����
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
		// ��ӡT���������ƺ�ֵ
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
		// ��ӡT���������ƺ�ֵ
		std::cout << typeid(T).name() << " " << m_value << std::endl;
	}
}