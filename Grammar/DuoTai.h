#pragma once

#include <iostream>

namespace DuoTai
{
	class Animal
	{
	public:
		const char* name;
		Animal()
		{
			name = "Default";
			std::cout << "Animal created." << std::endl;
		}
		virtual ~Animal();
		virtual void Spack() = 0;
	};

	class Dog : virtual public Animal
	{
	public:
		Dog(const char* name)
		{
			this->name = name;
		}
		~Dog()
		{
			std::cout << "Dog destroyed." << std::endl;
		}
		void Spack() override;
	};

	class Cat : virtual public Animal
	{
	public:
		Cat(const char* name)
		{
			this->name = name;
		}
		~Cat()
		{
			std::cout << "Cat destroyed." << std::endl;
		}
		void Spack() override;
	};

	void PrintAnimal(Animal& animal);
}
