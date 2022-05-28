#include <iostream>
#include <string>
#include <vector>

#include <fstream>	// std::i/o/fstream
#include <sstream>	// stringstream istringstream ostringstream

#include "ReadWrite_Parser.h"


BaseParser::BaseParser( std::string _TargetFile ) : TargetFile(_TargetFile)
{
	this->MaxAtomNumber = 1024;
	this->CurrentAtomNumber = 0;

	OutputFile = TargetFile + ".out";
	atom_type_name = new std::vector<std::string>[MaxAtomNumber];
	coordinate     = new std::vector<double>[MaxAtomNumber];
}

BaseParser::~BaseParser()
{	delete[] atom_type_name;
	delete[] coordinate;
}

bool BaseParser::Parser( const char c )
{
	std::ifstream ReadFile;
	std::string str, tmp;
	std::stringstream ss;

	double x,y,z;
	int comment_loc;
	ReadFile.open(TargetFile);
	
	if ( ReadFile.is_open() )
	{
		for( std::string str; std::getline(ReadFile,str); )	// <string> <- std::getline()
		{
			comment_loc = str.find(c);	// locate comment
			str = str.substr(0,comment_loc);	
			if ( str.length() > 0 )
			{
				ss.clear();
				ss.str("");
				ss << str;	// get string first
				ss >> tmp;	// take the first workd, delimiter whitespace
		
				if ( tmp.compare("atom") == 0 )
				{
					atom_type_name[CurrentAtomNumber].push_back(tmp);
					ss >> x;
					coordinate[CurrentAtomNumber].push_back(x);
					ss >> y;
					coordinate[CurrentAtomNumber].push_back(y);
					ss >> z;
					coordinate[CurrentAtomNumber].push_back(z);
					ss >> tmp;
					atom_type_name[CurrentAtomNumber].push_back(tmp);

					CurrentAtomNumber++;

					// valid expression
					// ss >> x >> y >> z >> tmp;	<-> (ss >> x) >> y ....
				}
			}
		}
		//std::cout << "am I working?\n";
		//std::cout << CurrentAtomNumber << std::endl;
		ReadFile.close();
		return true;
	}
	else
	{	return false;
	}
}

void BaseParser::Decomment()
{
	std::ofstream WriteFile;
	WriteFile.open(OutputFile);

	/* simple writing ...
	std::string str = "What do you want to put?";
	WriteFile << str;
	*/

	char buf[80];	// formatted writing
	std::string s;

	for(int i=0;i<CurrentAtomNumber;i++)
	{
		snprintf(buf, sizeof(buf), "%8.8s\t%8.4lf\t%8.4lf\t%8.4lf\t%8.4s\n",
			atom_type_name[i][0].c_str(),coordinate[i][0],coordinate[i][1],coordinate[i][2],atom_type_name[i][1].c_str());

		s = buf;
		WriteFile << s;
		/* std::string -> char* */
	}
	WriteFile.close();
	return;
}
