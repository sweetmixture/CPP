#include <iostream>

class First
{

friend class Second;

private:
	char* first_data;

public:

	First( const char* data )
	{
		first_data = new char[strlen(data)];
		strcpy(first_data,data);
	
		std::cout << "Cons First : " << this << std::endl;
	}
	virtual void Show() const
	{
		std::cout << first_data << std::endl;
	}

	virtual ~First()
	{
		delete[] first_data;

		std::cout << "Dest First : " << this << std::endl;
	}
};

class Second : public First
{
private:
	char* second_data;

public:

	Second( const char* data1, const char* data2 ) : First(data1)
	{
		second_data = new char[strlen(data2)];
		strcpy(second_data,data2);
	
		std::cout << "Cons Second : " << this << std::endl;
	}

	virtual void Show() const override
	{
		First::Show();
		std::cout << second_data << std::endl;
		std::cout << first_data << "\t" << second_data << std::endl;	// due to the 'firend' in line : 6
	}

	virtual ~Second()
	{
		delete[] second_data;

		std::cout << "Dest Second : " << this << std::endl;
	}
};

int main()
{
	First* first = new Second("Apple","Pie");
	
	first->Show();

	delete first;

	return 0;
}
