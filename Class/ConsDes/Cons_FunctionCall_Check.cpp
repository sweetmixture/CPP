#include <iostream>

class Test
{

	int data;

public:

	Test( int data_ ) : data(data_)
	{
		std::cout << "default cons called\n";
	}

	Test( const Test& obj )
	{
		data = obj.data;
		std::cout << "copy cons called : " << this << "\n";
	}

	Test& operator=( const Test& obj )
	{
		data = obj.data;
		std::cout << "copy assign called : " << this << "\n";
		return *this;
	}

	~Test()
	{	std::cout << "des called : " << this << std::endl;
	}
};

void foo( const Test t )	// Call-by-Value
{
	std::cout << "foo called\n";
}

void bar( const Test& t )	// Call-by-Reference
{
	std::cout << "bar called\n";
}

Test tee( Test t )
{
	std::cout << "arg address: " << &t << std::endl;

	return t;
}

int main()
{
	Test t1(10);
	Test t2(5);
	t2 = t1;
	Test t3 = t2;

	std::cout << "\n";
	std::cout << "testing foo\n";
	foo(t2);			// Copy Constructor used here! ( Call-by-Value )

	std::cout << "\n";
	std::cout << "testing bar\n";
	bar(t2);			// Passing obj by reference .. Copy does not occur 

	std::cout << "\n";
	std::cout << "test tee\n";
	std::cout << "input address: " << &t1 << std::endl;
	t2 = tee(t1);
	std::cout << "return obj   : " << &t2 << std::endl;


	std::cout << "\n";
	std::cout << "finalise\n";
	return 0;
}

/*

default cons called
default cons called
copy assign called : 0x7ffee8693960
copy cons called : 0x7ffee8693950

testing foo
copy cons called : 0x7ffee8693948
foo called
des called : 0x7ffee8693948

testing bar
bar called

test tee
input address: 0x7ffee8693968		// show address 't1'
copy cons called : 0x7ffee8693938	// CopyCons ... Test tee( Test t ) : in line 43
arg address: 0x7ffee8693938		// Show Arg 't' Address : in line 45
copy cons called : 0x7ffee8693940	// Return Object Allocated : in line 47 'return t;'
copy assign called : 0x7ffee8693960	// Operator= : in line 68 't2 = tee(t1);'
des called : 0x7ffee8693940		// Temporal obj 't' destroyed
des called : 0x7ffee8693938		// Temporal return object destroyed
return obj   : 0x7ffee8693960		// Address of final return result : saved in 't2' : in line 69

finalise
des called : 0x7ffee8693950
des called : 0x7ffee8693960
des called : 0x7ffee8693968

*/
