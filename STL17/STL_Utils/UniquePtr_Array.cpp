#include <iostream>
#include <memory>
#include <iomanip>

class MyClass
{
private:
	static int cnt;
	int val;

public:
	MyClass() : val(cnt)
	{	char buf[80];
		sprintf(buf,"Hello : %.12p / \t%d\n",this,val);
		std::cout << buf;
		MyClass::cnt++;
	}
	void Show() const
	{
		std::cout << "Show val : " << val << std::endl;
	}

	~MyClass()
	{	char buf[80];
		sprintf(buf,"Bye   : %.12p / \t%d\n",this,val);
		std::cout << buf;
	}

};

int MyClass::cnt = 0;

int main()
{
	std::cout << "***********************";
	std::cout << " Array Specialisation : unique_ptr\n";
	{
		std::unique_ptr<MyClass[]> uptr(new MyClass[5]);
	}


	std::cout << "***********************";
	std::cout << " Array Specialisation : unique_ptr - 2\n";
	{
		std::unique_ptr<MyClass[]> uptr(new MyClass[2]);	// uptr is a 'pointer'	... i.e., decltype(uptr) = MyClass* 

		uptr[0].Show();
		(&uptr[0])->Show();	// in fact ... 'uptr' is not a pointer but the operators '.' and '->' are overloaded, therefore it behaves like a pointer

		MyClass* ptr = uptr.release();				// How to pass the ownership


		ptr[0].Show();
		ptr[1].Show();

		delete[] ptr;	// delete[] must follow
	}

	std::unique_ptr<int[]> uptr(new int[10]);
	for(int i=0;i<10;i++)
		std::cout << uptr[i] << std::endl;

	int* int_arr = uptr.release();
	delete[] int_arr;

	std::unique_ptr<int> up = std::make_unique<int>(2000);
	std::cout << *up << std::endl;

	return 0;
}
