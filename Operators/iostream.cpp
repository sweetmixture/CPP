#include <iostream>
#include <string>

class Point
{
private:
	int xpos,ypos;

public:
	Point() : xpos(0), ypos(0) {}
	Point( int x, int y ) : xpos(x), ypos(y) {}

	void ShowPosition() const
	{
		char buffer[1024];
		sprintf(buffer,"%s%d%s%d%s","[",xpos," , ",ypos,"]");

		std::cout << buffer << std::endl;
	}

	friend std::ostream& operator<<( std::ostream& os, const Point& ref );
};
std::ostream& operator<<( std::ostream& os, const Point& ref )
{
	char buffer[1024];
	sprintf(buffer,"%s%d%s%d%s","[",ref.xpos," , ",ref.ypos,"]");
	os << buffer;

	return os;
}

int main()
{
	Point pos1(10,20);
	pos1.ShowPosition();

	//std::cout << pos1 << std::endl;
	std::string str = "ABC";
	std::cout << str << std::endl;
	str = str + " adfadf";
	std::cout << str << std::endl;
	std::cout << pos1 << std::endl;

	std::cout << "\nTest\n";
	std::cout << str << std::endl;

	return 0;
}
