#include <iostream>
#include <utility>
#include <vector>

//#include <chrono>

int main()
{
	std::vector<int> BigOne(10000,2011);
	std::cout << BigOne[0] << std::endl;
	std::vector<int> EmptyOne;

	EmptyOne = std::move(BigOne);
	EmptyOne[0] = -1;

	std::cout << "EmptyOne size: " << EmptyOne.size() << std::endl;
	std::cout << "EmptyOne[0]  : " << EmptyOne[0] << std::endl;
	//std::cout << "BigOne[0]    : " << BigOne[0] << std::endl;	// BigOne is moved ... Must not be accessed

	return 0;
}
