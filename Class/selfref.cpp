#include <iostream>

class SelfRef
{
	private:
		int num;

	public:
		SelfRef() { num = 0; };

		SelfRef( int num_ ) : num(num_) {}

	
		SelfRef& Add( int n )
		{
			num += n;
			return *this;
		}

		SelfRef& Show()
		{
	 		std::cout << "show number: " << this->num << std::endl;
			std::cout << "address    : " << this << std::endl;
			return *this;
		}
};

int main()
{
	SelfRef s;

	SelfRef s2 = s.Show();	// s2 has different address c.f. s ... since s2 itself it is lvalue?

	SelfRef& s3 = s2.Add(10);
	
	std::cout << "\nFinalise" << std::endl;
	std::cout << "show s\t";
	s.Show();
	std::cout << "show s2\t";
	s2.Show();
	std::cout << "show s3\t";
	s3.Show();
	
	return 0;
}

/* Possible Output
show number: 0
address    : 0x7ffee9f50988

Finalise
show s	show number: 0
address    : 0x7ffee9f50988
show s2	show number: 10
address    : 0x7ffee9f50980
show s3	show number: 10
address    : 0x7ffee9f50980
*/
