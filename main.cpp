#include <iostream>
#include "UniqueHolder.h"

using namespace ISXUniqueHolder;

int main()
{

	// boolean holder
	UniqueHolder holder(true);
	std::cout << holder << std::endl;

	holder = false;
	std::cout << holder << std::endl;

	holder = 3.1415;
	std::cout << holder << std::endl;

	try
	{
		int i = holder.ToInt();
	}
	catch (bad_type& bt)
	{
		std::cout << bt.what() << std::endl;
	}

	holder = (signed char)'o';
	std::cout << holder << std::endl;


	signed char c = holder.ToSignedChar();
	std::cout << "c: " << c << std::endl;


	try
	{
		holder.ResetData();
		bool b = holder.ToBool();
	}
	catch (bad_type& bt)
	{
		std::cout << bt.what() << std::endl;
	}

	system("pause");
	return 0;
}