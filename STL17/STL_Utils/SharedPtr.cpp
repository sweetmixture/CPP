#include <iostream>
#include <string>
#include <memory>

class Foo 
{
private:
	std::string name;
	int age;

public:
	Foo(const char* name_, unsigned int age_) : name(name_), age(age_)
	{
		std::cout << "Foo Constructor !\n";
	}
	
	void Show() const
	{
		std::cout << "Name : " << name << std::endl;
		std::cout << "Age  : " << age  << std::endl;
	}

	void SetAge( int age_ ) { age = age_; }

	~Foo()
	{	std::cout << "Foo Destructor  ~\n";
	}
};

void testFoo( std::shared_ptr<Foo> obj )
{
	std::cout << "In testFoo - ";
	std::cout << "CurrUseCnt : " << obj.use_count() << std::endl;
	std::cout << "SetAge(1)\n";
	obj->SetAge(1);
}

void testFooRef( std::shared_ptr<Foo>& obj )			// obviously... passing ref does not increase the use_count!
{
	std::cout << "In testFooRef - ";
	std::cout << "CurrUseCnt : " << obj.use_count() << std::endl;
	std::cout << "SetAge(2)\n";
	obj->SetAge(2);
	
	//obj.reset();
}

int main()
{
	using std::shared_ptr;
	using std::make_shared;

	shared_ptr<Foo> s1 = make_shared<Foo>("Apple",32);
	s1->Show();
	std::cout << "CurUseCnt : " << s1.use_count() << std::endl;
	auto s2 = s1;
	std::cout << "CurUseCnt : " << s1.use_count() << std::endl;
	s2->SetAge(10);
	s1->Show();
	s2->Show();	// can find the ptr is shared
	
	auto s3(s2);
	std::cout << "CurUseCnt : " << s1.use_count() << std::endl;
	s3->SetAge(324);
	s1->Show();

	std::cout << "********************** pass std::shared_ptr<T> as Arg to testFoo() \n";
	testFoo(s1);
	std::cout << "********************** testFoo() end\n";
	std::cout << "CurUseCnt : " << s1.use_count() << std::endl;
	s3->Show();

	std::cout << "********************** pass std::shared_ptr<T>& as Arg to testFooRef() \n";
	testFooRef(s1);
	std::cout << "********************** testFoo() end\n";
	std::cout << "CurUseCnt : " << s1.use_count() << std::endl;
	s3->Show();

	return 0;
}
