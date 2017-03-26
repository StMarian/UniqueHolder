#include "UniqueHolder.h"

namespace ISXUniqueHolder
{

UniqueHolder::UniqueHolder() : m_data_type(Types::UNDEFINED)
{
}

UniqueHolder::UniqueHolder(const UniqueHolder& holder)
{
	m_data_type = holder.get_Type();

	switch (m_data_type)
	{
	case Types::BOOL:
		m_data.bool_type = holder.ToBool();
		break;
	case Types::SIGNED_CHAR:
		m_data.signed_char_type = holder.ToSignedChar();
		break;
	case Types::UNSIGNED_CHAR:
		m_data.unsigned_char_type = holder.ToUnsignedChar();
		break;
	case Types::WCHAR_T:
		m_data.wchar_t_type = holder.ToWchar_t();
		break;
	case Types::SHORT_INT:
		m_data.short_int_type = holder.ToShortInt();
		break;
	case Types::UNSIGNED_SHORT_INT:
		m_data.unsigned_short_int_type = holder.ToUnsignedShortInt();
		break;
	case Types::INT:
		m_data.int_type = holder.ToInt();
		break;
	case Types::UNSIGNED_INT:
		m_data.unsigned_int_type = holder.ToUnsignedInt();
		break;
	case Types::LONG_INT:
		m_data.long_int_type = holder.ToLongInt();
		break;
	case Types::UNSIGNED_LONG_INT:
		m_data.unsigned_long_int_type = holder.ToUnsignedLongInt();
		break;
	case Types::LONG_LONG_INT:
		m_data.long_long_int_type = holder.ToLongLongInt();
		break;
	case Types::UNSIGNED_LONG_LONG_INT:
		m_data.unsigned_long_long_int_type = holder.ToUnsignedLongLongInt();
		break;
	case Types::FLOAT:
		m_data.float_type = holder.ToFloat();
		break;
	case Types::DOUBLE:
		m_data.double_type = holder.ToDouble();
		break;
	case Types::LONG_DOUBLE:
		m_data.long_double_type = holder.ToLongDouble();
		break;
	case Types::UNDEFINED:
		break;
	}

}

UniqueHolder::UniqueHolder(bool bool_type) : m_data_type(Types::BOOL)
{
	m_data.bool_type = bool_type;
}

UniqueHolder::UniqueHolder(signed char signed_char_type) : m_data_type(Types::SIGNED_CHAR)
{
	m_data.signed_char_type = signed_char_type;
}

UniqueHolder::UniqueHolder(unsigned char unsigned_char_type) : m_data_type(Types::UNSIGNED_CHAR)
{
	m_data.unsigned_char_type = unsigned_char_type;
}

UniqueHolder::UniqueHolder(wchar_t wchar_t_type) : m_data_type(Types::WCHAR_T)
{
	m_data.wchar_t_type = wchar_t_type;
}

UniqueHolder::UniqueHolder(short int short_int_type) : m_data_type(Types::SHORT_INT)
{
	m_data.short_int_type = short_int_type;
}

UniqueHolder::UniqueHolder(unsigned short int unsigned_short_int_type) : m_data_type(Types::UNSIGNED_SHORT_INT)
{
	m_data.unsigned_short_int_type = unsigned_short_int_type;
}

UniqueHolder::UniqueHolder(int int_type) : m_data_type(Types::INT)
{
	m_data.int_type = int_type;
}

UniqueHolder::UniqueHolder(unsigned int unsigned_int_type) : m_data_type(Types::UNSIGNED_INT)
{
	m_data.unsigned_int_type = unsigned_int_type;
}

UniqueHolder::UniqueHolder(long int long_int_type) : m_data_type(Types::LONG_INT)
{
	m_data.long_int_type = long_int_type;
}

UniqueHolder::UniqueHolder(unsigned long int unsigned_long_int_type) : m_data_type(Types::UNSIGNED_LONG_INT)
{
	m_data.unsigned_long_int_type = unsigned_long_int_type;
}

UniqueHolder::UniqueHolder(long long int long_long_int_type) : m_data_type(Types::LONG_LONG_INT)
{
	m_data.long_long_int_type = long_long_int_type;
}

UniqueHolder::UniqueHolder(unsigned long long int unsigned_long_long_int_type) : m_data_type(Types::UNSIGNED_LONG_LONG_INT)
{
	m_data.unsigned_long_long_int_type = unsigned_long_long_int_type;
}

UniqueHolder::UniqueHolder(float float_type) : m_data_type(Types::FLOAT)
{
	m_data.float_type = float_type;
}

UniqueHolder::UniqueHolder(double double_type) : m_data_type(Types::DOUBLE)
{
	m_data.double_type = double_type;
}

UniqueHolder::UniqueHolder(long double long_double_type) : m_data_type(Types::LONG_DOUBLE)
{
	m_data.long_double_type = long_double_type;
}

UniqueHolder::~UniqueHolder()
{
}

UniqueHolder& UniqueHolder::operator=(const UniqueHolder& rhs)
{
	if (*this != rhs)
	{
		this->m_data_type = rhs.m_data_type;
		this->m_data = rhs.m_data;
	}

	return *this;
}

UniqueHolder& UniqueHolder::operator=(const bool rhs)
{
	this->m_data.bool_type = rhs;
	this->m_data_type = Types::BOOL;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const signed char rhs)
{
	this->m_data.signed_char_type = rhs;
	this->m_data_type = Types::SIGNED_CHAR;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const unsigned char rhs)
{
	this->m_data.unsigned_char_type = rhs;
	this->m_data_type = Types::UNSIGNED_CHAR;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const wchar_t rhs)
{
	this->m_data.wchar_t_type = rhs;
	this->m_data_type = Types::WCHAR_T;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const short int rhs)
{
	this->m_data.short_int_type = rhs;
	this->m_data_type = Types::SHORT_INT;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const unsigned short int rhs)
{
	this->m_data.unsigned_short_int_type = rhs;
	this->m_data_type = Types::UNSIGNED_SHORT_INT;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const int rhs)
{
	this->m_data.int_type = rhs;
	this->m_data_type = Types::INT;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const unsigned int rhs)
{
	this->m_data.unsigned_int_type = rhs;
	this->m_data_type = Types::UNSIGNED_INT;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const long int rhs)
{
	this->m_data.long_int_type = rhs;
	this->m_data_type = Types::LONG_INT;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const unsigned long int rhs)
{
	this->m_data.unsigned_long_int_type = rhs;
	this->m_data_type = Types::UNSIGNED_LONG_INT;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const long long int rhs)
{
	this->m_data.long_long_int_type = rhs;
	this->m_data_type = Types::LONG_LONG_INT;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const unsigned long long int rhs)
{
	this->m_data.unsigned_long_long_int_type = rhs;
	this->m_data_type = Types::UNSIGNED_LONG_LONG_INT;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const float rhs)
{
	this->m_data.float_type = rhs;
	this->m_data_type = Types::FLOAT;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const double rhs)
{
	this->m_data.double_type = rhs;
	this->m_data_type = Types::DOUBLE;
	return *this;
}

UniqueHolder& UniqueHolder::operator=(const long double rhs)
{
	this->m_data.long_double_type = rhs;
	this->m_data_type = Types::LONG_DOUBLE;
	return *this;
}

void UniqueHolder::Swap(UniqueHolder& lhs, UniqueHolder& rhs)
{
	UniqueHolder temp(lhs);
	lhs = rhs;
	rhs = temp;
}

const char* UniqueHolder::get_TypeName() const
{
	char* type;

	switch (m_data_type)
	{
	case Types::BOOL:
		type = "bool";
		break;
	case Types::SIGNED_CHAR:
		type = "signed char";
		break;
	case Types::UNSIGNED_CHAR:
		type = "unsigned char";
		break;
	case Types::WCHAR_T:
		type = "wchar_t";
		break;
	case Types::SHORT_INT:
		type = "short int";
		break;
	case Types::UNSIGNED_SHORT_INT:
		type = "unsigned short int";
		break;
	case Types::INT:
		type = "int";
		break;
	case Types::UNSIGNED_INT:
		type = "unsigned int";
		break;
	case Types::LONG_INT:
		type = "long int";
		break;
	case Types::UNSIGNED_LONG_INT:
		type = "unsigned long int";
		break;
	case Types::LONG_LONG_INT:
		type = "long long int";
		break;
	case Types::UNSIGNED_LONG_LONG_INT:
		type = "unsigned long long int";
		break;
	case Types::FLOAT:
		type = "float";
		break;
	case Types::DOUBLE:
		type = "double";
		break;
	case Types::LONG_DOUBLE:
		type = "long double";
		break;
	case Types::UNDEFINED:
		type = "type undefined";
		break;
	}

	return type;
}

bool UniqueHolder::ToBool() const noexcept(false)
{
	if (m_data_type != Types::BOOL)
	{
		throw bad_type();
	}
	else
	{
		return m_data.bool_type;
	}
}

signed char UniqueHolder::ToSignedChar() const noexcept(false)
{
	if (m_data_type != Types::SIGNED_CHAR)
	{
		throw bad_type();
	}
	else
	{
		return m_data.signed_char_type;
	}
}

unsigned char UniqueHolder::ToUnsignedChar() const noexcept(false)
{
	if (m_data_type != Types::UNSIGNED_CHAR)
	{
		throw bad_type();
	}
	else
	{
		return m_data.unsigned_char_type;
	}
}

wchar_t UniqueHolder::ToWchar_t() const noexcept(false)
{
	if (m_data_type != Types::WCHAR_T)
	{
		throw bad_type();
	}
	else
	{
		return m_data.wchar_t_type;
	}
}

short int UniqueHolder::ToShortInt() const noexcept(false)
{
	if (m_data_type != Types::SHORT_INT)
	{
		throw bad_type();
	}
	else
	{
		return m_data.short_int_type;
	}
}

unsigned short int UniqueHolder::ToUnsignedShortInt() const noexcept(false)
{
	if (m_data_type != Types::UNSIGNED_SHORT_INT)
	{
		throw bad_type();
	}
	else
	{
		return m_data.unsigned_short_int_type;
	}
}

int UniqueHolder::ToInt() const noexcept(false)
{
	if (m_data_type != Types::INT)
	{
		throw bad_type();
	}
	else
	{
		return m_data.int_type;
	}
}

unsigned int UniqueHolder::ToUnsignedInt() const noexcept(false)
{
	if (m_data_type != Types::UNSIGNED_INT)
	{
		throw bad_type();
	}
	else
	{
		return m_data.unsigned_int_type;
	}
}
 
long int UniqueHolder::ToLongInt() const noexcept(false)
{
	if (m_data_type != Types::LONG_INT)
	{
		throw bad_type();
	}
	else
	{
		return m_data.long_int_type;
	}
}

unsigned long int UniqueHolder::ToUnsignedLongInt() const noexcept(false)
{
	if (m_data_type != Types::UNSIGNED_LONG_INT)
	{
		throw bad_type();
	}
	else
	{
		return m_data.unsigned_long_int_type;
	}
}

long long int UniqueHolder::ToLongLongInt() const noexcept(false)
{
	if (m_data_type != Types::LONG_LONG_INT)
	{
		throw bad_type();
	}
	else
	{
		return m_data.long_long_int_type;
	}
}

unsigned long long int UniqueHolder::ToUnsignedLongLongInt() const noexcept(false)
{
	if (m_data_type != Types::UNSIGNED_LONG_LONG_INT)
	{
		throw bad_type();
	}
	else
	{
		return m_data.unsigned_long_long_int_type;
	}
}

float UniqueHolder::ToFloat() const noexcept(false)
{
	if (m_data_type != Types::FLOAT)
	{
		throw bad_type();
	}
	else
	{
		return m_data.float_type;
	}
}

double UniqueHolder::ToDouble() const noexcept(false)
{
	if (m_data_type != Types::DOUBLE)
	{
		throw bad_type();
	}
	else
	{
		return m_data.double_type;
	}
}

long double UniqueHolder::ToLongDouble() const noexcept(false)
{
	if (m_data_type != Types::LONG_DOUBLE)
	{
		throw bad_type();
	}
	else
	{
		return m_data.long_double_type;
	}
}

bool operator!=(const UniqueHolder& lhs, const UniqueHolder& rhs)
{
	if (lhs.get_Type() != rhs.get_Type())
		return true;

	switch (rhs.get_Type())
	{
	case Types::BOOL:
		if (rhs.m_data.bool_type != lhs.m_data.bool_type) return true;
	case Types::SIGNED_CHAR:
		if (rhs.m_data.signed_char_type != lhs.m_data.signed_char_type) return true;
	case Types::UNSIGNED_CHAR:
		if (rhs.m_data.unsigned_char_type != lhs.m_data.unsigned_char_type) return true;
	case Types::WCHAR_T:
		if (rhs.m_data.wchar_t_type != lhs.m_data.wchar_t_type) return true;
	case Types::SHORT_INT:
		if (rhs.m_data.short_int_type != lhs.m_data.short_int_type) return true;
	case Types::UNSIGNED_SHORT_INT:
		if (rhs.m_data.unsigned_short_int_type != lhs.m_data.unsigned_short_int_type) return true;
	case Types::INT:
		if (rhs.m_data.int_type != lhs.m_data.int_type) return true;
	case Types::UNSIGNED_INT:
		if (rhs.m_data.unsigned_int_type != lhs.m_data.unsigned_int_type) return true;
	case Types::LONG_INT:
		if (rhs.m_data.long_int_type != lhs.m_data.long_int_type) return true;
	case Types::UNSIGNED_LONG_INT:
		if (rhs.m_data.unsigned_long_int_type != lhs.m_data.unsigned_long_int_type) return true;
	case Types::LONG_LONG_INT:
		if (rhs.m_data.long_long_int_type != lhs.m_data.long_long_int_type) return true;
	case Types::UNSIGNED_LONG_LONG_INT:
		if (rhs.m_data.unsigned_long_long_int_type != lhs.m_data.unsigned_long_long_int_type) return true;
	case Types::FLOAT:
		if (rhs.m_data.float_type != lhs.m_data.float_type) return true;
	case Types::DOUBLE:
		if (rhs.m_data.double_type != lhs.m_data.double_type) return true;
	case Types::LONG_DOUBLE:
		if (rhs.m_data.long_double_type != lhs.m_data.long_double_type) return true;
	case Types::UNDEFINED:
		return true;
	}

	return false;
}

std::ostream & operator<<(std::ostream& out, const UniqueHolder& obj)
{
	switch (obj.get_Type())
	{
	case Types::BOOL:
		out << "bool ";
		out << obj.m_data.bool_type;
		break;
	case Types::SIGNED_CHAR:
		out << "signed char ";
		out << obj.m_data.signed_char_type;
		break;
	case Types::UNSIGNED_CHAR:
		out << "unsigned char ";
		out << obj.m_data.unsigned_char_type;
		break;
	case Types::WCHAR_T:
		out << "wchar_t ";
		out << obj.m_data.wchar_t_type;
		break;
	case Types::SHORT_INT:
		out << "short int ";
		out << obj.m_data.short_int_type;
		break;
	case Types::UNSIGNED_SHORT_INT:
		out << "unsigned short int" ;
		out << obj.m_data.unsigned_short_int_type;
		break;
	case Types::INT:
		out << "int ";
		out << obj.m_data.int_type;
		break;
	case Types::UNSIGNED_INT:
		out << "unsigned int ";
		out << obj.m_data.unsigned_int_type;
		break;
	case Types::LONG_INT:
		out << "long int ";
		out << obj.m_data.long_int_type;
		break;
	case Types::UNSIGNED_LONG_INT:
		out << "unsigned long int ";
		out << obj.m_data.unsigned_long_int_type;
		break;
	case Types::LONG_LONG_INT:
		out << "long long int ";
		out << obj.m_data.long_long_int_type;
		break;
	case Types::UNSIGNED_LONG_LONG_INT:
		out << "unsigned long long int ";
		out << obj.m_data.unsigned_long_long_int_type;
		break;
	case Types::FLOAT:
		out << "float ";
		out << obj.m_data.float_type;
		break;
	case Types::DOUBLE:
		out << "double ";
		out << obj.m_data.double_type;
		break;
	case Types::LONG_DOUBLE:
		out << "long double ";
		out << obj.m_data.long_double_type;
		break;
	case Types::UNDEFINED:
		out << "type undefined ";
		break;
	}
	return out;
}

}