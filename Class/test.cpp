#include <iostream>

int main()
{
	char* abc = "Apple is nice!";	// warning -> const char* abc = "~~~";	// allowed in C

	std::cout << strlen(abc) << std::endl;

	return 0;
}
