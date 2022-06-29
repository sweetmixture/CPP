#include <iostream>

int main()
{
	int num = strlen("apple");

	char* str = new char[strlen("apple")];

	delete[] str;

	std::cout << num << std::endl;
	return 0;
}
