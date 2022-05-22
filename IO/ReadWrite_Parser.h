#ifndef _ReadWrite_Parser
#define _ReadWrite_Parser

class BaseParser
{
	int MaxAtomNumber;
	int CurrentAtomNumber;

	std::string TargetFile;
	std::string OutputFile;

	std::vector<std::string>* atom_type_name;
	std::vector<double>* coordinate;

	public:
		BaseParser( std::string _TargetFile );

		virtual ~BaseParser();

		virtual bool Parser( const char c );

		virtual void Decomment();
};

#endif
