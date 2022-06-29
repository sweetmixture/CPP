#include <iostream>

class First
{
private:
	char* first_name;
	
public:

	First() {	first_name = new char[10];	}

	First( const char* str )
	{
		first_name = new char[ strlen(str) ];
		strcpy(first_name,str);
	}

	First( const First& ref )
	{	
		std::cout << "First Copy\n";
		delete[] first_name;
		first_name = new char[ strlen(ref.first_name) ];
		strcpy(first_name,ref.first_name);
	}

	First& operator=( const First& ref )
	{
		std::cout << "First Copy Ass\n";
		delete[] first_name;
		first_name = new char[ strlen(ref.first_name) ];
		strcpy(first_name,ref.first_name);
		
		return *this;
	}

	virtual void ShowInfo() const
	{	std::cout << "FirstShow\n";
		std::cout << first_name << std::endl;
	}


	virtual ~First()
	{	
		std::cout << "FirstDes\n";
		delete[] first_name;
	}
};

class Second : public First
{
private:
	char* second_name;
public:
	Second() {	second_name = new char[10];	}
	Second( const char* str1, const char* str2 ) : First(str1)
	{
		second_name = new char[ strlen(str2) ];
		strcpy(second_name,str2);
	}

	Second( const Second& ref )
	{
		std::cout << "Second Copy\n";
		delete[] second_name;
		second_name = new char[strlen(ref.second_name)];
		strcpy(second_name,ref.second_name);
	}
	
	Second& operator=( const Second& ref )
	{
		std::cout << "Second Copy Ass\n";
		First::operator=(ref);
		delete[] second_name;
		second_name = new char[strlen(ref.second_name)];
		strcpy(second_name,ref.second_name);

		return *this;
	}

	virtual void ShowInfo() const
	{
		First::ShowInfo();
		std::cout << second_name << std::endl;
	}

	virtual ~Second()
	{
		std::cout << "SecondDes\n";
		delete[] second_name;
	}
};

int main()
{
	{	std::cout << "Initial Test\n";
		First f1("Apple");
		f1.ShowInfo();
		First f2;
		f2 = f1;
		f2.ShowInfo();
	}	std::cout << "Initial Test End\n\n";

	
	Second f1("Apple","Samsung");
	f1.ShowInfo();
	decltype(f1) f2;
	f2.ShowInfo();
	f2 = f1;
	f2.ShowInfo();
	
	First* ms = new Second;
	
	f2 = *(static_cast<Second*>(ms));
	f2.ShowInfo();
	delete ms;

	auto f3 = *ms;
	f3.ShowInfo();

	return 0;
}
