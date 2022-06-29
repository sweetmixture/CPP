#include<iostream>

class MyFriendInfo
{
private:
	char* name;
	int   age;

public:
	MyFriendInfo( const char* name_, const int age_ )
	{	
		name = new char[strlen(name_)];
		strcpy(name,name_);
		age = age_;

		std::cout << "Con Base: " << this << "\n";
	}

	~MyFriendInfo()
	{	
		delete[] name;
		std::cout << "Des Base : " << this << "\n";
	}

	void ShowMyFriendInfo()
	{
		std::cout << "name : " << name << "\n";
		std::cout << "age  : " << age  << "\n";
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;

public:

	MyFriendDetailInfo( const char* name_, const int age_, const char* addr_, const char* phone_ ) : MyFriendInfo(name_,age_)
	{
		addr = new char[strlen(addr_)];
		phone= new char[strlen(phone_)];
		strcpy(addr,addr_);
		strcpy(phone,phone_);
		std::cout << "Con Deri : " << this << "\n";
	}

	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
		std::cout << "Des Deri : " << this << "\n";
	}

	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		std::cout << "addr : " << addr  << "\n";
		std::cout << "phone: " << phone << "\n";
	}
};

int main()
{
	MyFriendInfo f1("Apple",23);
	f1.ShowMyFriendInfo();

	std::cout << "\nDeri\n";
	MyFriendDetailInfo f2("Apple",23,"UK","12321515");
	f2.ShowMyFriendDetailInfo();
	return 0;
}
