#include <iostream>

class AAA
{
	private:
		int tag;

	public:
		AAA() : tag(0)
		{	
			std::cout << "default tag : " << tag << std::endl;
		}

		AAA& CreateAAA( const int tag_ )
		{
			AAA* ptr = new AAA;
			ptr->tag = tag_;
			return *ptr;
		}

		void ShowContents()
		{
			std::cout << tag << std::endl;
		}

		~AAA()	{ std::cout << "Des tag" << tag << std::endl; }

};

int main()
{
	AAA a1;
	a1.ShowContents();

	AAA& a2 = a1.CreateAAA( 10 );
	a2.ShowContents();

	{	
		AAA a3;
	}
	return 0;
}
