#include <iostream>
#include <string>
#include "ReadWrite_Parser.h"

int main( int argc, char* argv[] )
{
	if( argc > 1 )
	{
		BaseParser base(argv[1]);
		std::cout << argv[1] << std::endl;
		base.Parser('#');

		base.Decomment();
	}
	else
		return 0;
}
