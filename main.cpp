#include <iostream>
#include "UniqueHolder.h"

using namespace ISXUniqueHolder;

int main()
{
	UniqueHolder holder1(true);
	std::cout << "Holder 1: " << holder1 << std::endl;

	holder1 = false;
	std::cout << "Holder 1: " << holder1 << std::endl;

	holder1 = 3.1415;
	std::cout << "Holder 1: " << holder1 << std::endl;

	try
	{
		int i = holder1.ToInt();
	}
	catch (bad_type& bt)
	{
		std::cout << bt.what() << std::endl;
	}

	holder1 = (signed char)'o';
	std::cout << "Holder 1: " << holder1 << std::endl;


	signed char c = holder1.ToSignedChar();
	std::cout << "c: " << c << std::endl;

	try
	{
		holder1.ResetData();
		bool b = holder1.ToBool();
	}
	catch (bad_type& bt)
	{
		std::cout << bt.what() << std::endl;
	}

	holder1 = (char)'r';
	UniqueHolder holder2(90.1f);

	std::cout << "Holder 1: " << holder1 << std::endl;
	std::cout << "Holder 2: " << holder2 << std::endl;

	UniqueHolder::Swap(holder1, holder2);

	std::cout << "Holder 1: " << holder1 << std::endl;
	std::cout << "Holder 2: " << holder2 << std::endl;

	system("pause");
	return 0;
}