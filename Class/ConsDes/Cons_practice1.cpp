#include <iostream>
#include <cmath>

class Point
{
	private:
		int x,y;

	public:

		Point( const int x_, const int y_ ) : x(x_), y(y_) {}
		int GetX() const { return this->x; }
		int GetY() const { return this->x; }
};

class Geometry
{
	private:
		int num_point;
		Point* point_array[1024];
	public:
		Geometry() { num_point = 0; }

	void AddPoint( const Point& point )
	{
		point_array[num_point] = new Point(point.GetX(),point.GetY());
		num_point++;
	}

	void PrintDistance()
	{
		for(int i=0;i<num_point;i++)
		{	for(int j=i+1;j<num_point;j++)
			{
				double dx = point_array[i]->GetX() - point_array[j]->GetX();
				double dy = point_array[i]->GetY() - point_array[j]->GetY();
				double d  = pow( dx*dx + dy*dy , 0.5 );

				std::cout << "Pair : " << i << ", " << j << " / dist : " << d << "\n";
			}
		}
	}

	~Geometry()
	{
		for(int i=num_point;i>0;i--)
		{	delete point_array[i-1];
		}
	}
};

int main()
{
	Point p1(10,5);
	Point p2(3,-15);
	Point p3(4,-1);

	Geometry geo;
	geo.AddPoint(p1);
	geo.AddPoint(p2);
	geo.AddPoint(p3);
	geo.PrintDistance();

	return 0;
}
