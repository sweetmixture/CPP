#include <iostream>

class Point
{
private:
	int xpos,ypos;

public:
	Point( int x=0, int y=0 ) : xpos(x), ypos(y) {}

	Point& operator=( const Point& ref )
	{	
		//std::cout << "Point = operator\n";
		xpos = ref.xpos;
		ypos = ref.ypos;
		return *this;
	}

	friend std::ostream& operator<<( std::ostream& os, const Point& ref );
};

std::ostream& operator<<( std::ostream& os, const Point& ref )
{
	os << '[' << ref.xpos << ',' << ref.ypos << ']';
	return os;
}


class PointArr
{
private:
	Point* p;
	int arrlen;

public:
	PointArr( const int len ) : arrlen(len)
	{
		p = new Point[arrlen];
	}

	Point& operator[]( const int k )
	{
		return p[k];
	}

	Point operator[]( const int k ) const
	{
		return p[k];
	}

	int GetArrLen() const
	{
		return this->arrlen;
	}
	
	~PointArr()
	{
		delete[] p;
	}
};

void ShowAll( const PointArr& arr )
{
	for(int i=0;i<arr.GetArrLen();i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

int main()
{
	Point p(1,2);
	//std::cout << p << std::endl;

	PointArr parr(5);
	parr[0] = p;
	//std::cout << parr[0] << std::endl;

	ShowAll(parr);

	return 0;
}
