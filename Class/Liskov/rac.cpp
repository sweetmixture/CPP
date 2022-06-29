#include <iostream>

class Rectangle
{
	public:

	int width, heigth;

	Rectangle( const int width, const int heigth ) : width(width), heigth(heigth) {}

	int get_width() const { return width; }

	virtual void set_width( const int width ) { this->width = width; }

	int get_heigth() const { return heigth; }

	virtual void set_heigth( const int heigth ) { this->heigth = heigth; }

	int area() const { return this->width*this->heigth; }

};

class Square : public Rectangle
{
	public:

	Square( int size ) : Rectangle(size,size) {}

	void set_width( const int width ) override
	{
		this->width = width;
		this->heigth = width;
	}

	void set_heigth( const int heigth ) override
	{
		this->width = heigth;
		this->heigth = heigth;
	}
};

void process( Rectangle& r )
{
	int area = r.area();
	std::cout << "area: " << area << std::endl;
}

int main()
{
	Rectangle rect(10,5);
	process(rect);
	
	Square sqr(7);
	process(sqr);

	return 0;
}
