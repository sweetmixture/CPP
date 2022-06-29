#include <iostream>

class MyClass
{
private:

	int* data;
	int  tag;

public:
	MyClass()
	{
		tag = 0;
		data = new int[10];
	}

	MyClass( const int tag ) : tag(tag)
	{	data = new int[10];

		for(int i=0;i<10;i++)
		{	data[i] = i;
		}
	}

	MyClass( const MyClass& obj )
	{
		this->tag = obj.tag + 1;
		this->data = new int[10];

		for(int i=0;i<10;i++)
		{	this->data[i] = obj.data[i] + 1;
		}
	}
	
	MyClass& operator=( const MyClass& obj )
	{
		tag = obj.tag;
		for(int i=0;i<10;i++)
		{	data[i] = obj.data[i];
		}

		return *this;
	}

	void Show()
	{
		std::cout << "tag : " << tag << std::endl;	
		for(int i=0;i<10;i++)
		{	std::cout << data[i] << std::endl;
		}
	}

	virtual ~MyClass()
	{
		delete[] data;
		std::cout << "data address  : " << this->data << std::endl;
		std::cout << "tag / address : " << tag << " /" << this << " destroyed" << std::endl; 
	}
};

int main()
{
	MyClass A(10);
	MyClass B(A);	// Copy Cons;
	MyClass C = B;	// Copy Cons;
	
	MyClass D;
	//D = C;		// without operator= ... shallow copy;
	D = C;			// Copy Assignment operator called !


	std::cout << "\n##!A\n";
	A.Show();
	std::cout << "\n##!B\n";
	B.Show();
	std::cout << "\n##!C\n";
	C.Show();
	std::cout << "\n##!D\n";
	D.Show();
	

	return 0;
}
