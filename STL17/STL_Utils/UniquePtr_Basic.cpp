#include <iostream>
#include <memory>

class MyInt
{
private:
	int n;

public:
	MyInt() : n(0) {}
	MyInt( int n_ ) : n(n_) {}

	void Show() const
	{
		std::cout << "data : " << n << std::endl;
	}

	void Set( int n_ )
	{
		n = n_;
	}

	~MyInt()
	{
		std::cout << "Good bye from : " << n << std::endl;
	}
};

std::unique_ptr<MyInt> DoSomething( MyInt* obj )
{
	std::cout << "In Do Something\n";
	obj->Show();
	
	std::unique_ptr<MyInt> ret(obj);	// can pass SameType ptr obj
	return ret;
}

int main()
{
	std::unique_ptr<MyInt> uptr( new MyInt(111) );
	std::cout << "Resource Address : " << uptr.get() << std::endl;		// .get()
	std::cout << "ResetTest\n";
	uptr.reset(new MyInt(10000));
	std::cout <<"Resource Address : " << uptr.get() << std::endl;
	
	std::cout << "Show data\n";
	uptr->Show();
	
	auto ptr_tmp = uptr.get();
	ptr_tmp->Set(100);
	ptr_tmp->Show();
	uptr->Show();


	{
		std::cout << "\nLocal Test\n";
		std::unique_ptr<MyInt> uptr2(new MyInt(5));
		std::cout << "Local Resource Address : " << uptr2.get() << std::endl;
	}

	std::cout << "***************************\n";
	std::cout << "Resource release\n";
	MyInt* ptr;

	std::cout << "uptr address (before release)       : " << uptr.get() << std::endl;
	ptr = uptr.release();
	std::cout << " ptr address (uptr address returned): " << ptr << std::endl;	// address must be same
	std::cout << "Show data\n";
	ptr->Show();
	delete ptr;


	std::cout << "***************************\n";
	std::cout << "FunctionTest\n";
	uptr.reset(new MyInt(5000));			// Reuse 
	uptr = DoSomething( uptr.release() );

	std::unique_ptr<MyInt> tmp;
	tmp.reset(uptr.release());

	std::cout << "\n>Before Final Return\n";
	return 0;
}
