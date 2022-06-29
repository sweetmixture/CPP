#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool CompLess( int a, int b )
{
	return (a<b);
}

int main()
{
	std::string first = "first";
	std::string second= "second";

	int tarr[] = {1,2,3};		// seems simple C array?

	auto arr = {1,2,3,4,5,6,-3,15};	// type? list? all no // std::initilaizer_list 

	//std::cout << "front() : " << arr.front() << std::endl;	// arr is not a list, cannot bind .front() and .end();
	//std::cout << "end()   : " << arr.end()   << std::endl;

	auto min = std::min(arr);
	auto max = std::max(arr);
	std::cout << "arr min : " << min << std::endl;
	std::cout << "arr max : " << max << std::endl;





	std::cout << std::endl;
	std::cout << "STL VECTOR ... std::pair std:minmax_element(v.begin(),v.end(),COMPFOO); test \n";
	std::vector<int> v = {1,2,3,4,5,6,-3,15};
	//auto minmax = std::minmax_element(v.begin(),v.end(),CompLess);
	std::pair minmax = std::minmax_element(v.begin(),v.end(),CompLess);
	std::cout << "MIN: " << *minmax.first  << std::endl;
	std::cout << "MAX: " << *minmax.second << std::endl;


	return 0;
}
