#include <iostream>

class Rectangle
{
private:

	double length_a;
	double length_b;

public:
	Rectangle( const double length_a_, const double length_b_ ) :
		length_a(length_a_), length_b(length_b_)
	{
		std::cout << "Cons Rec : " << this << std::endl;
	}

	Rectangle( const Rectangle& rec )
	{
		length_a = rec.length_a;
		length_b = rec.length_b;

		std::cout << "Copy Rec : " << this << std::endl;
	}

	Rectangle& operator=( const Rectangle& rec )
	{
		length_a = rec.length_a;
		length_b = rec.length_b;
	
		std::cout << "AsCp rec : " << this << std::endl;
		
		return *this;
	}

	~Rectangle()
	{
		std::cout << "Dest rec : " << this << std::endl;
	}


	virtual void ShowArea() const
	{
		std::cout << "Area is  : " << length_a*length_b << " Addr : " << this << std::endl;
	}
};

class Square : public Rectangle
{

public:
	Square( const double length_ ) : Rectangle(length_,length_) // Explicit Invocation of Base constructor ... as long as there is no default, specified in the Base class
	{
		//Rectangle(length_,length_);	//  must explicitly initialize the base class 'Rectangle' which does not have a default constructor ... Error!
		std::cout << "Const Sqr : " << this << std::endl;
	}
	
	~Square()
	{
		std::cout << "Dest sqr : " << this << std::endl;
	}
};

int main()
{
	{
		Rectangle r1(10,5);
		Rectangle r2(5,5);
		r2 = r1;

		r2.ShowArea();
	}
	std::cout << "\n*Testing derived Sqr\n";


	Square sq1(6);
	Rectangle* r_ptr = &sq1;
	sq1.ShowArea();
	r_ptr->ShowArea();

	//Rectangle sq2(10);

	return 0;
}
