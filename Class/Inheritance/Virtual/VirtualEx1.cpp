#include <iostream>

class First
{
public:
	virtual void Foo()
	{	std::cout << "First\n";
	}
};

class Second : public First
{
public:
	virtual void Foo() override
	{	std::cout << "Second\n";
	}
};

class Third : public Second
{
public:
	virtual void Foo() override
	{	std::cout << "Third\n";
	}
};

int main()
{
	Third* tptr = new Third;
	Second* sptr = tptr;
	First* fptr = sptr;

	tptr->Foo();
	sptr->Foo();
	fptr->Foo();

	delete tptr;

	std::cout << "\nTest\n";
	First* ptr = new Third;
	ptr->Foo();
	delete ptr;

	ptr = new Second;
	ptr->Foo();
	delete ptr;	// 
	

	return 0;
}
