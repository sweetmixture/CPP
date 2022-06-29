#include <iostream>

class Test
{

public:

	Test()
	{
		std::cout << "Default Cons\n\n";
	}

	explicit Test( const Test& obj )
	{
		std::cout << "Copy Cons\n\n";
	}

	Test& operator=( const Test& obj )
	{
		std::cout << "Copy Assign Cons\n\n";
		return *this;
	}

};

int main()
{
	Test t1;
	Test t2(t1);	// Test t2 = t1; -> not Allowed! (by explicit), i.e., prevent implicit conversion t2=t1; -> t2(t1);
	t2 = t1;

	return 0;
}
