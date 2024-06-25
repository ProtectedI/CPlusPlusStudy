#include "DuoTai.h"

DuoTai::Animal::~Animal()
{
	name = NULL;
	std::clog << "Animal destructor called." << std::endl;
}

void DuoTai::Dog::Spack()
{
	std::clog << name << " Dog is spacking." << std::endl;
}

void DuoTai::Cat::Spack()
{
	std::clog << name << " Cat is spacking." << std::endl;
}

void DuoTai::PrintAnimal(Animal& animal)
{
	animal.Spack();
}