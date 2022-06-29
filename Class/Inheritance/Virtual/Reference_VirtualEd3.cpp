#include <iostream>

class First
{
public:
	void first_foo()
	{
		std::cout << "first_foo()\n";
	}
	
	virtual void simple_foo() const
	{
		std::cout << "first simple foo\n";
	}
};

class Second : public First
{
public:
	void second_foo()
	{
		std::cout << "second_foo()\n";
	}

	virtual void simple_foo() const override
	{
		std::cout << "second simple foo\n";
	}
};

class Third : public Second
{
public:
	void third_foo()
	{
		std::cout << "thrid_foo()\n";
	}
	
	virtual void simple_foo() const override
	{
		std::cout << "third simple foo\n";
	}
};

void call_foo( const First& obj )
{
	obj.simple_foo();
	return;
}

int main()
{
	Third third;
	Second& second = third;
	First& first = second;

	third.simple_foo();
	second.simple_foo();
	first.simple_foo();

	std::cout << "\nTest\n";
	third.first_foo();	
	third.second_foo();
	third.first_foo();

	std::cout << "\nFunctionTest\n";
	call_foo(third);
	call_foo(second);
	call_foo(first);

	return 0;
}
