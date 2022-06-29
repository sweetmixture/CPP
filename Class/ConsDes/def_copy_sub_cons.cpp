#include <iostream>

class Test
{
public:
	Test()
	{	std::cout << "Default Cons\n";
		std::cout << "Object Address : " << this << "\n\n";
	}

	Test( const Test& obj )
	{
		std::cout << "Copy Cons\n";
		std::cout << "Object Address : " << this << "\n\n";
	}

	Test& operator=( const Test& obj )
	{
		std::cout << "Copy Assign Cons\n";
		std::cout << "Object Address : " << this << "\n\n";
		return *this;
	}
};

int main()
{
	Test t1;
	Test t2(t1);
	Test t3 = t1;

	Test t4;
	t4 = t1;
	
	return 0;
}
