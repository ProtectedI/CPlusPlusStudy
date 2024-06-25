#include <iostream>

class A
{
private:
	int a;
protected:
	int b;
public:
	int c;
	A();
	A(int a);
	void Test()
	{
		std::clog << "Test A" << std::endl;
	}
	~A();
};

class C
{
public:
	int d;
};

class B :public A, private C
{
public:
	int c;
	int getAllSum()
	{
		return this->b + this->c + this->d;
	}

	void Test()
	{
		std::clog << "Test B" << std::endl;
	}

	// 函数重载
	void add(int i)
	{
		this->d += i;
	}
	void add(float i)
	{
		this->d += i;
	}
	void add(short i)
	{
		this->d += i;
	}
};

// 运算符重载
struct Pos
{
	float x, y, z;
	Pos(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Print()
	{
		printf("(x:%f,y:%f,z:%f)\n", x, y, z);
	}

	Pos operator+ (Pos& pos)
	{
		Pos result(0, 0, 0);
		result.x = this->x + pos.x;
		result.y = this->y + pos.y;
		result.z = this->z + pos.z;
		return result;
	}

	Pos operator- (Pos& pos)
	{
		Pos result(0, 0, 0);
		result.x = this->x - pos.x;
		result.y = this->y - pos.y;
		result.z = this->z - pos.z;
		return result;
	}

	Pos& operator++()
	{
		++x;
		++y;
		++z;
		return *this;
	}

	Pos operator++(int)
	{
		Pos temp(*this);
		x++;
		y++;
		z++;
		return temp;
	}
};


A::A()
{
	a = 0;
	b = 0;
	c = 0;
	std::clog << "Create A\n" << std::endl;
}

A::A(int value) :b(5), c(6)
{
	this->a = value;
	printf("a:%d b:%d c:%d\n", value, b, c);
}

A::~A()
{
	printf("Destroy A\n");
}

std::ostream& operator<<(std::ostream& os, const Pos& pos)
{
	os << "(" << pos.x << "," << pos.y << "," << pos.z << ")";
	return os;
}

int main()
{
	/*A a;
	A a2(3);*/

	/*B b;
	printf("%d", b.getAllSum());*/

	//Pos p1(1, 2, 3);
	//std::clog << p1 << std::endl;
	//Pos p2(4, 5, 6);
	//std::clog << p2 << std::endl;
	//Pos p3 = p1 + p2;
	//std::clog << p3 << std::endl;
	//std::clog << ++(++p1) << std::endl;
	/*std::clog << (p2++)++ << std::endl;
	std::clog << p2++ << std::endl;
	std::clog << p2 << std::endl;*/

	B b;
	b.Test();

	std::cin.get();
}