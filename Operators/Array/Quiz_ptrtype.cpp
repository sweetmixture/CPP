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

typedef Point* POINT_PTR;

class PointArr
{
private:
	POINT_PTR* p;
	int arrlen;

public:
	PointArr( const int len ) : arrlen(len)
	{
		p = new POINT_PTR[arrlen];
	}

	POINT_PTR& operator[]( const int k )
	{
		return p[k];
	}

	POINT_PTR operator[]( const int k ) const
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

void ShowAll( const POINT_PTR& arr, const int len )
{
	for(int i=0;i<len;i++)
	{
		//std::cout << *(arr[i]) << std::endl;
	}
}

int main()
{
	//std::cout << p << std::endl;

	PointArr parr(2);
	parr[0] = new Point(5,5);
	parr[1] = new Point(3,2);
	//std::cout << parr[0] << std::endl;

	for(int k=0;k<parr.GetArrLen();k++)
	{
		std::cout << k << std::endl;
		std::cout << *(parr[k]) << std::endl;
	}
	//ShowAll(parr);

	return 0;
}
