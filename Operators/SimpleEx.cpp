#include <iostream>

class Point
{
private:
	int xpos, ypos;

public:
	Point() : xpos(0), ypos(0)
	{
		std::cout << "DefaultCons\n";
	}

	Point( const int x, const int y ) : xpos(x), ypos(y)
	{
		std::cout << "DefaultCons - Init\n";
	}

	Point( const Point& ref )
	{	xpos = ref.xpos;
		ypos = ref.ypos;
		std::cout << "CopyCons\n";
	}

	void ShowPosition() const
	{
		std::cout << '[' << xpos << ',' << ypos << ']' << std::endl;
	}

	Point& operator=( const Point& ref )
	{
		xpos = ref.xpos;
		ypos = ref.ypos;

		std::cout << "CopyAssign\n";

		return *this;
	}

	Point operator+( const Point& ref )
	{
		Point ret(xpos+ref.xpos,ypos+ref.ypos);
		return ret;
	}

	Point& operator+=( const Point& ref )
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}

	Point& operator-=( const Point& ref )
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}

	Point operator*( const int t )	const	// as const function
	{
		Point ret( t*xpos, t*ypos );
		return ret;
	}

	~Point()
	{
		std::cout << "DefaultDes\n";
	}

	friend Point operator-( const Point&, const Point& );	// 'friend' for the external function ... to access private members
	friend bool operator==( const Point& pos1, const Point& pos2 );
	friend Point& operator~( Point& pos );
	friend Point operator*( const int t, const Point& ref );
};

Point operator-( const Point& pos1, const Point& pos2 )
{
	std::cout << "using External opertor+\n";
	Point ret(pos1.xpos-pos2.xpos,pos1.ypos-pos2.ypos);
	return ret;
}

bool operator==( const Point& pos1, const Point& pos2 )
{
	if( (pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos ) )
		return true;
	else
		return false;
}

bool operator!=( const Point& pos1, const Point& pos2 )	// using 'operator==' already friend of 'Point' class ... this function doesn't neet to be a friend of Point class
{
	if ( !(pos1 == pos2) )
		return true;
	else
		return false;
}

Point& operator~( Point& pos )
{
	int tmp = pos.xpos;
	pos.xpos = pos.ypos;
	pos.ypos = tmp;

	return pos;
}

Point operator*( const int t, const Point& ref )	// without 'const' on Point& ref -> error
{
	Point ret(t*ref.xpos,t*ref.ypos);
	return ret;					// DefCons - DefDes
	//return ref*t;					// DefCons - DefDes	same cost
}

int main()
{
	Point pos1;
	Point pos2(10,5);
	Point pos3(-10,5);

	std::cout << "\nBeginTest\n";
	pos1 = pos2 + pos3;		// here 'pos1' is lvalue -> CopyAssign
	pos1.ShowPosition();
	
	std::cout << "\nBegineTest2\n";
	Point pos4 = pos2 + pos3 + pos1;	// pos2.operator+(pos3.operator+(pos1));	// why no CopyCons?
	pos4.ShowPosition();
	
	Point pos5 = pos2;

	std::cout << "\nBegineTest3\n";
	pos5 = pos4 - pos4;
	pos5.ShowPosition();

	std::cout << "\nBeginTest4\n";
	pos2.ShowPosition();
	pos3.ShowPosition();

	pos5 = (pos2+=pos3);		// CopyAssign
	pos5.ShowPosition();

	pos2.ShowPosition();
	pos3.ShowPosition();

	std::cout << "sub assignment\n";
	pos2 -= pos3;
	pos2.ShowPosition();

	std::cout << "\nBeginTest5\n";
	std::cout << true << "\t" << false << "\n";

	std::cout << (pos2 == pos3) << std::endl;
	std::cout << (pos2 != pos3) << std::endl;

	std::cout << "\nBegineTest5 - Swap\n";
	pos2.ShowPosition();
	~~pos2;				// BitOperation - xpos <-> ypos
	~(~pos2);
	//pos2~;	// Error
	~pos2;
	pos2.ShowPosition();

	std::cout << "\nBeginTest6 - Mul\n";
	pos2.ShowPosition();
	pos3 = pos2 * 4 * -1;	// defcons x2 defdes x2
	pos2.ShowPosition();
	pos3.ShowPosition();

	pos2 = -1 * pos3;
	pos2.ShowPosition();
	
	std::cout << "\nBeforeReturn\n";
	return 0;
}	
