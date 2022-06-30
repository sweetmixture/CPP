#include <iostream>
#include <Eigen>
#include <omp.h>

int main()
{
	Eigen::MatrixXd m(2,2);
	m(0,0) = -1;
	m(1,1) = -1;

	Eigen::MatrixXd n(2,2);
	n(0,0) = -3.1;
	n(0,1) = +2.4;
	n(1,0) = -10.1;
	n(1,1) = -9.6;

	Eigen::MatrixXd mn(2,2);

	mn = m*n;

	std::cout << "Here is the matrix m  :\n" << m  << std::endl;
	std::cout << "Here is the matrix n  :\n" << n  << std::endl;
	std::cout << "Here is the matrix mn :\n" << mn << std::endl;
	
	return 0;
}
