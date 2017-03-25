#include <iostream>
#include "UniqueHolder.h"
using namespace std;
using namespace ISXUniqueHolder;

int main()
{

	UniqueHolder holder(true);

	bool test = false;

	test = holder.ToBool();

	cout << test;

	cout << holder.get_TypeName();

	holder = false;

	test = holder.ToBool();

	cout << test;

	system("pause");
	return 0;
}