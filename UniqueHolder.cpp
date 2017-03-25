#include "UniqueHolder.h"

const char* const UniqueHolder::s_bad_type_exception_msg = "Bad Type";

UniqueHolder::UniqueHolder(): m_data_type(TYPE_UNDEFINED)
{
}

UniqueHolder::UniqueHolder(const UniqueHolder& holder)
{
	m_data_type = holder.get_Type();


	switch (m_data_type)
	{
	case TYPE_BOOL:
		m_data.bool_type = holder.ToBool();
		return;
	case TYPE_SIGNED_CHAR:
		m_data.signed_char_type = holder.ToSignedChar();
		return;
	case TYPE_UNSIGNED_CHAR:
		m_data.unsigned_char_type = holder.ToUnsignedChar();
		return;
	case TYPE_WCHAR_T:
		m_data.wchar_t_type = holder.ToWchar_t();
		return;
	case TYPE_SHORT_INT:
		m_data.short_int_type = holder.ToShortInt();
		return;
	case TYPE_UNSIGNED_SHORT_INT:
		m_data.unsigned_short_int_type = holder.ToUnsignedShortInt();
		return;
	case TYPE_INT:
		m_data.int_type = holder.ToInt();
		return;
	case TYPE_UNSIGNED_INT:
		m_data.unsigned_int_type = holder.ToUnsignedInt();
		return;
	case TYPE_LONG_INT:
		m_data.long_int_type = holder.ToLongInt();
		return;
	case TYPE_UNSIGNED_LONG_INT:
		m_data.unsigned_long_int_type = holder.ToUnsignedLongInt();
		return;
	case TYPE_LONG_LONG_INT:
		m_data.long_long_int_type = holder.ToLongLongInt();
		return;
	case TYPE_UNSIGNED_LONG_LONG_INT:
		m_data.unsigned_long_long_int_type = holder.ToUnsignedLongLongInt();
		return;
	case TYPE_FLOAT:
		m_data.float_type = holder.ToFloat();
		return;
	case TYPE_DOUBLE:
		m_data.double_type = holder.ToDouble();
		return;
	case TYPE_LONG_DOUBLE:
		m_data.long_double_type = holder.ToLongDouble();
		return;
	case TYPE_UNDEFINED:
		return;
	}
	
}

UniqueHolder::UniqueHolder(bool bool_type): m_data_type(TYPE_BOOL)
{
	m_data.bool_type = bool_type;
}

UniqueHolder::UniqueHolder(signed char signed_char_type): m_data_type(TYPE_SIGNED_CHAR)
{
	m_data.signed_char_type = signed_char_type;
}

UniqueHolder::UniqueHolder(unsigned char unsigned_char_type): m_data_type(TYPE_UNSIGNED_CHAR)
{
	m_data.unsigned_char_type = unsigned_char_type;
}

UniqueHolder::UniqueHolder(wchar_t wchar_t_type): m_data_type(TYPE_WCHAR_T)
{
	m_data.wchar_t_type = wchar_t_type;
}

UniqueHolder::UniqueHolder(short int short_int_type): m_data_type(TYPE_SHORT_INT)
{
	m_data.short_int_type = short_int_type;
}

UniqueHolder::UniqueHolder(unsigned short int unsigned_short_int_type): m_data_type(TYPE_UNSIGNED_SHORT_INT)
{
	m_data.unsigned_short_int_type = unsigned_short_int_type;
}

UniqueHolder::UniqueHolder(int int_type): m_data_type(TYPE_INT)
{
	m_data.int_type = int_type;
}

UniqueHolder::UniqueHolder(unsigned int unsigned_int_type): m_data_type(TYPE_UNSIGNED_INT)
{
	m_data.unsigned_int_type = unsigned_int_type;
}

UniqueHolder::UniqueHolder(long int long_int_type): m_data_type(TYPE_LONG_INT)
{
	m_data.long_int_type = long_int_type;
}

UniqueHolder::UniqueHolder(unsigned long int unsigned_long_int_type): m_data_type(TYPE_UNSIGNED_LONG_INT)
{
	m_data.unsigned_long_int_type = unsigned_long_int_type;
}

UniqueHolder::UniqueHolder(long long int long_long_int_type): m_data_type(TYPE_LONG_LONG_INT)
{
	m_data.long_long_int_type = long_long_int_type;
}

UniqueHolder::UniqueHolder(unsigned long long int unsigned_long_long_int_type): m_data_type(TYPE_UNSIGNED_LONG_LONG_INT)
{
	m_data.unsigned_long_long_int_type = unsigned_long_long_int_type;
}

UniqueHolder::UniqueHolder(float float_type): m_data_type(TYPE_FLOAT)
{
	m_data.float_type = float_type;
}

UniqueHolder::UniqueHolder(double double_type): m_data_type(TYPE_DOUBLE)
{
	m_data.double_type = double_type;
}

UniqueHolder::UniqueHolder(long double long_double_type): m_data_type(TYPE_LONG_DOUBLE)
{
	m_data.long_double_type = long_double_type;
}

UniqueHolder::~UniqueHolder()
{
}

UniqueHolder & UniqueHolder::operator=(const UniqueHolder& rhs)
{
	if (*this != rhs)
	{
		*this = UniqueHolder(rhs);
	}

	return *this;
}

UniqueHolder& UniqueHolder::operator=(const bool rhs)
{
	this->m_data.bool_type = rhs;
	this->m_data_type = TYPE_BOOL;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const signed char rhs)
{
	this->m_data.signed_char_type = rhs;
	this->m_data_type = TYPE_SIGNED_CHAR;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const unsigned char rhs)
{
	this->m_data.unsigned_char_type = rhs;
	this->m_data_type = TYPE_UNSIGNED_CHAR;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const wchar_t rhs)
{
	this->m_data.wchar_t_type = rhs;
	this->m_data_type = TYPE_WCHAR_T;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const short int rhs)
{
	this->m_data.short_int_type = rhs;
	this->m_data_type = TYPE_SHORT_INT;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const unsigned short int rhs)
{
	this->m_data.unsigned_short_int_type = rhs;
	this->m_data_type = TYPE_UNSIGNED_SHORT_INT;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const int rhs)
{
	this->m_data.int_type = rhs;
	this->m_data_type = TYPE_INT;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const unsigned int rhs)
{
	this->m_data.unsigned_int_type = rhs;
	this->m_data_type = TYPE_UNSIGNED_INT;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const long int rhs)
{
	this->m_data.long_int_type = rhs;
	this->m_data_type = TYPE_LONG_INT;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const unsigned long int rhs)
{
	this->m_data.unsigned_long_int_type = rhs;
	this->m_data_type = TYPE_UNSIGNED_LONG_INT;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const long long int rhs)
{
	this->m_data.long_long_int_type = rhs;
	this->m_data_type = TYPE_LONG_LONG_INT;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const unsigned long long int rhs)
{
	this->m_data.unsigned_long_long_int_type = rhs;
	this->m_data_type = TYPE_UNSIGNED_LONG_LONG_INT;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const float rhs)
{
	this->m_data.float_type = rhs;
	this->m_data_type = TYPE_FLOAT;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const double rhs)
{
	this->m_data.double_type = rhs;
	this->m_data_type = TYPE_DOUBLE;
	return *this;
}

UniqueHolder & UniqueHolder::operator=(const long double rhs)
{
	this->m_data.long_double_type = rhs;
	this->m_data_type = TYPE_LONG_DOUBLE;
	return *this;
}

void UniqueHolder::Swap(UniqueHolder& lhs, UniqueHolder& rhs)
{
	UniqueHolder temp(lhs);
	lhs = rhs; 
	rhs = temp;
}

bool UniqueHolder::ToBool() const
{
	if(m_data_type != TYPE_BOOL)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.bool_type;
	}
}

signed char UniqueHolder::ToSignedChar() const
{
	if (m_data_type != TYPE_SIGNED_CHAR)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.signed_char_type;
	}
}

unsigned char UniqueHolder::ToUnsignedChar() const
{
	if (m_data_type != TYPE_UNSIGNED_CHAR)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.unsigned_char_type;
	}
}

wchar_t UniqueHolder::ToWchar_t() const
{
	if (m_data_type != TYPE_WCHAR_T)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.wchar_t_type;
	}
}

short int UniqueHolder::ToShortInt() const
{
	if (m_data_type != TYPE_SHORT_INT)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.short_int_type;
	}
}

unsigned short int UniqueHolder::ToUnsignedShortInt() const
{
	if (m_data_type != TYPE_UNSIGNED_SHORT_INT)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.unsigned_short_int_type;
	}
}

int UniqueHolder::ToInt() const
{
	if (m_data_type != TYPE_INT)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.int_type;
	}
}

unsigned int UniqueHolder::ToUnsignedInt() const
{
	if (m_data_type != TYPE_UNSIGNED_INT)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.unsigned_int_type;
	}
}

long int UniqueHolder::ToLongInt() const
{
	if (m_data_type != TYPE_LONG_INT)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.long_int_type;
	}
}

unsigned long int UniqueHolder::ToUnsignedLongInt() const
{
	if (m_data_type != TYPE_UNSIGNED_LONG_INT)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.unsigned_long_int_type;
	}
}

long long int UniqueHolder::ToLongLongInt() const
{
	if(m_data_type != TYPE_LONG_LONG_INT)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.long_long_int_type;
	}
}

unsigned long long int UniqueHolder::ToUnsignedLongLongInt() const
{
	if (m_data_type != TYPE_UNSIGNED_LONG_LONG_INT)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.unsigned_long_long_int_type;
	}
}

float UniqueHolder::ToFloat() const
{
	if (m_data_type != TYPE_FLOAT)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.float_type;
	}
}

double UniqueHolder::ToDouble() const
{
	if (m_data_type != TYPE_DOUBLE)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.double_type;
	}
}

long double UniqueHolder::ToLongDouble() const
{
	if (m_data_type != TYPE_LONG_DOUBLE)
	{
		throw s_bad_type_exception_msg;
	}
	else
	{
		return m_data.long_double_type;
	}
}

bool operator!=(const UniqueHolder & lhs, const UniqueHolder & rhs)
{
	if (lhs.get_Type() != rhs.get_Type())
		return true;
	// TODO: data comparation
	else
		return false;
}
