#include <iostream>
#include <vector>
#include <chrono>

int main()
{

//namespace sysClock = std::chrono::system_clock;
//using std::chrono;
using std::vector;

	std::cout << "**************************** Test 1\n";
	{
		vector<double> BigVec1(10000000,2022);
		vector<double> BigVec2;

		std::cout << "BigVec1 size : " << BigVec1.size() << std::endl;
		std::cout << "BigVec2 size : " << BigVec2.size() << std::endl;

		auto sta = std::chrono::system_clock::now();
		BigVec2 = BigVec1;
		auto end = std::chrono::system_clock::now();

		auto elapsed_time = (end - sta);
		auto et = std::chrono::duration<double>(elapsed_time).count();	
		std::cout << "Vector CopyAss ET : " << et << "(s)\n";
		std::cout << "BigVec1 size : " << BigVec1.size() << std::endl;
		std::cout << "BigVec2 size : " << BigVec2.size() << std::endl;
	}

	std::cout << "**************************** Test 2 :: std::move() \n";
	{
		vector<double> BigVec1(10000000,2022);
		vector<double> BigVec2;

		std::cout << "BigVec1 size : " << BigVec1.size() << std::endl;
		std::cout << "BigVec2 size : " << BigVec2.size() << std::endl;
		
		auto sta = std::chrono::system_clock::now();
		BigVec2 = std::move(BigVec1);
		auto end = std::chrono::system_clock::now();
	
		auto et = std::chrono::duration<double>(end-sta).count();
		std::cout << "Vector std::move() ET : " << et << "(s)\n";
		std::cout << "BigVec1 size : " << BigVec1.size() << std::endl;
		std::cout << "BigVec2 size : " << BigVec2.size() << std::endl;
	}
		

	return 0;
}
