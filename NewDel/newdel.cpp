#include <iostream>
#include <sstream>

int main()
{
	std::string* s_arr = new std::string[10];

	std::stringstream ss;
	std::string s;

	ss << "Apple is nice!";

	

	ss >> s_arr[0];
	ss >> s_arr[1];
	ss >> s_arr[2];
	ss >> s_arr[3];
	ss >> s_arr[4];
	ss >> s_arr[5];
	std::cout << s_arr[4].size() << std::endl;
	std::cout << s_arr[5].size() << std::endl;

	for(int i=0;i<10;i++)
	{
		if( s_arr[i].size() > 0 )
		{	std::cout << s_arr[i] << std::endl;
			bool b = s_arr[i].compare("Apple");	// if same return '0' as true
			std::cout << b << std::endl;
		}
		else
			break;
	}


	delete[] s_arr;

	return 0;
}
