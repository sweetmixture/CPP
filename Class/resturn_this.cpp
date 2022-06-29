#include <iostream>

class return_this
{
	int data;

	public:

	return_this() { this->data = 0; }

	return_this& add( int n )
	{
		this->data += n;

		return *this;
	}

	void show()
	{
		std::cout << data << std::endl;
	}

};

int main()
{
	return_this r;
	r.show();

	r.add(10);
	r.show();
	r.add(10).add(5);
	r.show();


	return_this* rp = new return_this;
	rp->show();
	rp[0].show();

	//rp->add(10)->add(25); // ... error - return type is reference not a pointer
	rp->add(10).add(25).add(45);
	rp->show();

	delete rp;

	return 0;
}
