#include<iostream>

class First
{
private:
	int* data;
public:
	First()
	{
		data = new int[2];
		data[0] = data[1] = 0;
		std::cout << "First DefCons - 1 \n";
	}

	First( const int n1, const int n2 )
	{
		data = new int[2];
		data[0] = n1;
		data[1] = n2;
		std::cout << "First DefCons - 2 (init) \n";
	}

	virtual First& operator=( First& ref )
	{
		delete[] data;
		data = new int[2];

		data[0] = ref.data[0];
		data[1] = ref.data[1];

		std::cout << "First CopyAss \n";
		
		return *this;
	}

	virtual void ShowData() const
	{
		std::cout << "First ShowData - ";
		std::cout << data[0] << " , " << data[1] << "\n";
	}

	virtual ~First()
	{
		delete[] data;
		std::cout << "FirstDes\n";
	}
};

class Second : public First
{
private:
	int* data2;

public:
	Second() : First()
	{
		data2 = new int[2];
		data2[0] = data2[1] = 0;
		std::cout << "Secon DefCons - 1 \n";
	}

	Second( int n1, int n2, int n3, int n4 ) : First(n1,n2)
	{
		data2 = new int[2];
		data2[0] = n3;
		data2[1] = n4;
		std::cout << "Secon DefCons - 2 (init) \n";
	}

	virtual Second& operator=( Second& ref )
	{
		First::operator=(ref);	/* Very Important - Specification is required !! */
		// Type Second& is Derived of the First ...
		// First::operator=( First& ref ) ... argument 'ref' can take Second& ref;

		delete data2;
		data2 = new int[2];
		data2[0] = ref.data2[0];
		data2[1] = ref.data2[1];

		std::cout << "Secon CopyAss\n";

		return *this;
	}

	virtual void ShowData() const override
	{
		First::ShowData();
		std::cout << "Secon ShowData - ";
		std::cout << data2[0] << " , " << data2[1] << "\n";
	}

	virtual ~Second()
	{
		delete[] data2;
		std::cout << "SecondDes\n";
	}
};

int main()
{
	{
		First f1(10,10);
		First f2;
		f2 = f1;
		f2.ShowData();
	}
	std::cout << "Test 1 End\n\n";

	{
		Second* f2 = new Second;
		f2->ShowData();
		delete f2;
	}
	std::cout << "Test 1 End\n\n";

	{
		First* f2 = new Second;
		f2->ShowData();

		Second f2_2(1,2,3,4);
		Second f2_3(3,3,5,5);
		f2_2 = f2_3;
		f2_2.ShowData();

		*(static_cast<Second*>(f2)) = f2_2;
		// *f2 = f2_2; // only calls FirstCopyAss
		f2->ShowData();

//decltype(f2) fd = new Second;
auto fd = new Second;
fd->ShowData();
delete fd;
std::cout << "aaaa!\n";

		Second f2_4(1,2,3,4);
		f2_4 = *(static_cast<Second*>(f2));
		//f2_4 = *f2;
		f2_4.ShowData();

		delete f2;
	}
	

	return 0;
}
