#include <iostream>
#include <vector>


void ShowV( std::vector<int>& v )
{
	for(auto k=v.begin();k<v.end();k++)
	{
		std::cout << *k << std::endl;
	}
}

int main()
{
	std::vector<int> v = {1,2,3,4,5};

	for( auto elem : v )
		std::cout << elem << std::endl;


	std::cout << "*************************\n";
	for(auto k = v.begin();k<v.end();k++)
	{
		*k = *k+1;
		std::cout << *k << std::endl;
	}

	std::cout << "*************************\n";
	v.insert(v.begin(),{-1,-2,-5,-1});
	ShowV(v);
	std::cout << "*************************\n";
	v.insert(v.begin()+1,{3});
	v.insert(v.begin()+1,5);
	ShowV(v);
	

	std::cout << "*************************\n";
	for( auto elem : v )
	{	
		ShowV(v);
		std::cout << "Popingout ... ### \n";
		v.pop_back();
	}
	std::cout << "is_empty() : " << v.empty() << std::endl;
	std::cout << "size : "       << v.size()  << std::endl;



	return 0;
}
