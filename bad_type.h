#pragma once
#include <exception>

namespace ISXUniqueHolder
{

class bad_type : public std::exception
{
public:
	bad_type();
	~bad_type();
	
	inline virtual const char* what() const throw()
	{
		return "Bad types!";
	}
};

}