#pragma once
#include <exception>

namespace ISXUniqueHolder
{

class bad_type : public std::exception
{
public:	
	virtual const char* what() const throw() { return "Bad types!"; }
};

}