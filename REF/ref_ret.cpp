#include <iostream>

int ret_int( int& a )	// return type - RValue (temporal) ... cannot bind to ref
{
	a++;
	return a;
}

int& ret_int_ref( int& a )	// return type - LValue (temporal) ... cannot bind to ref
{
	a++;
	return a;
}

int main()
{
	int n1 = 10;
	//int& n2 = ret_int(n1);	// error
	int n2 = ret_int(n1);
	std::cout << "n1: " << n1 << "\n" << "n2: " << n2 << "\n";
	std::cout << "n1: " << &n1 << "\n" << "n2: " << &n2 << "\n\n";

	int n3 = 10;
	int& n4 = ret_int_ref(n3);	// int& n4 = n3;
	std::cout << "n3: " << n3 << "\n" << "n4: " << n4 << "\n";
	std::cout << "n3: " << &n3 << "\n" << "n4: " << &n4 << "\n\n";

	n3++;
	std::cout << "n3: " << n3 << "\n" << "n4: " << n4 << "\n";
	n4++;
	std::cout << "n3: " << n3 << "\n" << "n4: " << n4 << "\n";

	return 0;
}
/* Possible Output

n1: 11
n2: 11
n1: 0x7ffeedb40988
n2: 0x7ffeedb40984

n3: 11
n4: 11
n3: 0x7ffeedb40980
n4: 0x7ffeedb40980

n3: 12
n4: 12
n3: 13
n4: 13

*/
