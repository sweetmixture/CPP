#include <iostream>
#include <string>

class Derived;

class Base
{
friend class Derived; // Derived can now access to privates of Base

private:
	int* base_data;
	std::string bstr;
public:
	Base()
	{	
		base_data = new int;
		bstr = "This is Base";
		std::cout << "Base Cons : " << this << "\n";
	}

	Base( const int data )
	{
		base_data = new int;
		base_data[0] = data;
		bstr = "This is Base";
		std::cout << "Base Cons : " << this << "\n";
	}

	Base( const Base& obj )
	{
		base_data = new int;
		base_data[0] = obj.base_data[0];
		bstr = obj.bstr;
		std::cout << "Base Cons : " << this << "\n";
	}

	virtual ~Base()
	{
		delete base_data;
		std::cout << "Base Des  : " << this << "\n";
	}

	virtual void Show()
	{	std::cout << "add : " << this << "\n";
		std::cout << "data: " << base_data[0] << "\n";
		std::cout << bstr << "\n";
	}
};

class Derived : Base
{
private:
	int tag;
public:

	Derived( const int tag_ ) : Base(), tag(tag_) 
	{
		std::cout << "DerivCons : " << this << "\n";
	}

	~Derived()
	{
		std::cout << "DerivDes  : " << this << "\n";
	}

	virtual void Show()
	{	std::cout << "add : " << this << "\n";
		std::cout << "data: " << base_data[0] << "\n";
		std::cout << bstr << "\n";
		std::cout << "derived tag : " << tag << "\n";
	}
};

int main()
{
	Base b(10);
	//b.Show();
	Base b1(b);


	std::cout << "\n * Derived\n";
	Derived d(111);
	d.Show();

	{
		std::cout << "\n";
		Derived d1(d);
		d1.Show();
	}
	std::cout << "\n";

	Base* bptr = new Derived;

	return 0;
}
