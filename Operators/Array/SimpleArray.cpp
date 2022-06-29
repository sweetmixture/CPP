#include <iostream>

class Array
{
private:
	int* data;
	int length;
public:
	Array( size_t size ) : length(size)
	{
		data = new int[length];
	}

	int& operator[]( const int n )
	{
		if( n < 0 || n >= length )
		{	std::cout << "array idx out of range ... \n";
			exit(1);
		}
		else
		{
			return data[n];
		}
	}

	const int GetArrLen()
	{
		return this->length;
	}

	~Array()
	{
		delete[] data;
	}
};

int main()
{
	Array arr(10);

	arr[0] = 10;
	std::cout << arr[0] << std::endl;
	//arr[-1];

	for(int i=0;i<arr.GetArrLen();i++)
	{
		std::cout << arr[i] << std::endl;
	}

	return 0;
}
