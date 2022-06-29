#include <iostream>
#include <memory>

class Foo
{
private:
	static int count;
	int val;
	int data;
public:
	Foo() : val(count)
	{
		std::cout << "Foo Construct ! : " << val << std::endl;
		data = 0;
		Foo::count++;
	}

	void Show() const
	{
		std::cout << " val / data : " << val << " / " << data << std::endl;
	}

	~Foo()
	{
		std::cout << "Foo Destruct  ~ : " << val << std::endl;
	}
};

int Foo::count = 0;


int main()
{
	std::unique_ptr<int[]> uptr = std::make_unique<int[]>(10);
	for(int i=0;i<10;i++)
	{	uptr[i] = i+1;
		std::cout << uptr[i] << std::endl;
	}
	std::cout << "***********************************\n";
	std::cout << "Class Obj Test\n";
	{
		std::unique_ptr<Foo[]> up = std::make_unique<Foo[]>(5);

		for(int i=0;i<5;i++)
		{
			up[i].Show();
		}

		//auto a = up.get_deleter();
		//up.reset();
		up = nullptr;
		std::cout << "Reset before being out of the scope\n";
		
	}
	std::cout << "***********************************\n";



	return 0;
}
