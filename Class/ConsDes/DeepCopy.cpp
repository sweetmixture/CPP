#include <iostream>

class Person
{
private:

	char* name;
	int age;

public:

	Person( char* name_ , int age_ ) : age(age_)
	{
		int len = strlen(name_);
		
		name = new char[len];

		strcpy(name,name_);
	}

	Person( const Person& person )
	{
		delete[] name;
		age = 0;

		int len = strlen(person.name);
		name = new char[len];
		strcpy(name,person.name);
		age = person.age;
	}

	Person& operator=( const Person& person )
	{
		int len = strlen(person.name);
		name = new char[len];
		strcpy(name,person.name);
		age = person.age;
		
		return *this;
	}	

	virtual ~Person()
	{
		std::cout << "Destructor called\n";
		std::cout << "Name : " << name << "\n";
		delete[] name;
	}

	void Show()
	{
		std::cout << "Name : " << name << std::endl;
		std::cout << "Age  : " << age  << std::endl;
		std::cout << "Addr : " << this << std::endl;
	}

};

int main()
{	
	char p1_name[] = "Apple";
	Person p1(p1_name,32);
	Person p2 = p1;
	//p1.Show();

	Person p3("Banana",18);
	p2 = p3;

	p1.Show();
	p2.Show();
	p3.Show();

	return 0;
}
