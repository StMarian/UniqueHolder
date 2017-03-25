#include <iostream>
#include "UniqueHolder.h"
using namespace std;

int main()
{

	UniqueHolder holder(true);

	bool test = false;

	test = holder.ToBool();

	cout << test;

	cout << holder.get_Type();

	holder = false;

	test = holder.ToBool();

	cout << test;

	system("pause");
	return 0;
}