#include <iostream>
#include <memory>
#include <vector>

class Point
{
private:
	double pos[3];

public:

	Point()
	{	pos[0] = pos[1] = pos[2] = 0.;	}

	Point( double x, double y, double z )
	{	pos[0] = x;
		pos[1] = y;
		pos[2] = z;
	}
	
	void Show() const
	{
		std::cout << pos[0] << "\t" << pos[1] << "\t" << pos[2] << std::endl;
	}

	~Point()
	{
		std::cout << "End : ";
		Point::Show();
	}
};

int main()
{
	//Point pt;
	//pt.Show();
	std::cout << "*************************************\n";
	{
		std::unique_ptr<Point> p = std::make_unique<Point>(1,2,3);
		p->Show();
	}
	std::cout << "*************************************\n";
	std::unique_ptr<Point> p = std::make_unique<Point>(1,2,3);
	p->Show();
	p.reset();	// Expire
	p = std::make_unique<Point>(3,4,5);
	auto p2 = std::move(p);			// p2 is std::unique_ptr<Point>
	p2->Show();
	//p2.reset();
	std::cout << "*************************************\n";
	auto p3 = p2.release();			// p3 is Point* ... .release() returns the pointer	// delete must be followed after the use of release()!!!
	p3->Show();
	delete p3;
	std::cout << "*************************************\n";
	



	return 0;
}
