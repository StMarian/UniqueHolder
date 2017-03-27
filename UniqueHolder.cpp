#include "UniqueHolder.h"
#include "bad_type.h"

namespace ISXUniqueHolder
{

UniqueHolder::UniqueHolder() : m_data_type(Types::UNDEFINED), m_data{}
{
}

UniqueHolder::UniqueHolder(const UniqueHolder& holder)
{
	m_data_type = holder.m_data_type;
	m_data = holder.m_data;
}

UniqueHolder::UniqueHolder(UniqueHolder&& holder)
{
	this->m_data = std::move(holder.m_data);
	this->m_data_type = std::move(holder.m_data_type);
	// setting holder to unworkable
	holder.m_data_type = Types::UNDEFINED;
	// setting all pointers to dynamic memory in holder to nullptr
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
	if (this != &rhs)
	{
		UniqueHolder copy(rhs);
		Swap(copy, *this);
	}
	return *this;
}

UniqueHolder& UniqueHolder::operator=(UniqueHolder&& rhs)
{
	if (this != &rhs)
	{
		this->m_data = std::move(rhs.m_data);
		this->m_data_type = std::move(rhs.m_data_type);

		// setting holder to unworkable
		rhs.m_data_type = Types::UNDEFINED;
		// setting all pointers to dynamic memory in holder to nullptr
	}
	return *this;
}

void UniqueHolder::Swap(UniqueHolder& lhs, UniqueHolder& rhs)
{
	std::swap(lhs.m_data, rhs.m_data);
	std::swap(lhs.m_data_type, rhs.m_data_type);
}

const char* UniqueHolder::get_TypeName() const
{
	switch (m_data_type)
	{
	case Types::BOOL:
		return "bool";
	case Types::SIGNED_CHAR:
		return "signed char";
	case Types::UNSIGNED_CHAR:
		return "unsigned char";
	case Types::WCHAR_T:
		return "wchar_t";
	case Types::SHORT_INT:
		return "short int";
	case Types::UNSIGNED_SHORT_INT:
		return "unsigned short int";
	case Types::INT:
		return "int";
	case Types::UNSIGNED_INT:
		return "unsigned int";
	case Types::LONG_INT:
		return "long int";
	case Types::UNSIGNED_LONG_INT:
		return "unsigned long int";
	case Types::LONG_LONG_INT:
		return "long long int";
	case Types::UNSIGNED_LONG_LONG_INT:
		return "unsigned long long int";
	case Types::FLOAT:
		return "float";
	case Types::DOUBLE:
		return "double";
	case Types::LONG_DOUBLE:
		return "long double";
	case Types::UNDEFINED:
		return "type undefined";
	}
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
		return rhs.m_data.bool_type != lhs.m_data.bool_type;
	case Types::SIGNED_CHAR:
		return rhs.m_data.signed_char_type != lhs.m_data.signed_char_type;
	case Types::UNSIGNED_CHAR:
		return rhs.m_data.unsigned_char_type != lhs.m_data.unsigned_char_type;
	case Types::WCHAR_T:
		return rhs.m_data.wchar_t_type != lhs.m_data.wchar_t_type;
	case Types::SHORT_INT:
		return rhs.m_data.short_int_type != lhs.m_data.short_int_type;
	case Types::UNSIGNED_SHORT_INT:
		return rhs.m_data.unsigned_short_int_type != lhs.m_data.unsigned_short_int_type;
	case Types::INT:
		return rhs.m_data.int_type != lhs.m_data.int_type;
	case Types::UNSIGNED_INT:
		return rhs.m_data.unsigned_int_type != lhs.m_data.unsigned_int_type;
	case Types::LONG_INT:
		return rhs.m_data.long_int_type != lhs.m_data.long_int_type;
	case Types::UNSIGNED_LONG_INT:
		return rhs.m_data.unsigned_long_int_type != lhs.m_data.unsigned_long_int_type;
	case Types::LONG_LONG_INT:
		return rhs.m_data.long_long_int_type != lhs.m_data.long_long_int_type;
	case Types::UNSIGNED_LONG_LONG_INT:
		return rhs.m_data.unsigned_long_long_int_type != lhs.m_data.unsigned_long_long_int_type;
	case Types::FLOAT:
		// if fabs < epsilon means they are equal, otherwise - not
		return std::fabs(rhs.m_data.float_type - lhs.m_data.float_type) >= std::numeric_limits<float>::epsilon();
	case Types::DOUBLE:
		return std::fabs(rhs.m_data.double_type - lhs.m_data.double_type) >= std::numeric_limits<double>::epsilon();
	case Types::LONG_DOUBLE:
		return std::fabs(rhs.m_data.long_double_type - lhs.m_data.long_double_type) >= std::numeric_limits<long double>::epsilon();
	case Types::UNDEFINED:
		return true;
	}
}

std::ostream & operator<<(std::ostream& out, const UniqueHolder& obj)
{
	out << obj.get_TypeName() << ": ";

	switch (obj.get_Type())
	{
	case Types::BOOL:
		return out << obj.m_data.bool_type;
	case Types::SIGNED_CHAR:
		return out << obj.m_data.signed_char_type;
	case Types::UNSIGNED_CHAR:
		return out << obj.m_data.unsigned_char_type;
	case Types::WCHAR_T:
		return out << obj.m_data.wchar_t_type;
	case Types::SHORT_INT:
		return out << obj.m_data.short_int_type;
	case Types::UNSIGNED_SHORT_INT:
		return out << obj.m_data.unsigned_short_int_type;
	case Types::INT:
		return out << obj.m_data.int_type;
	case Types::UNSIGNED_INT:
		return out << obj.m_data.unsigned_int_type;
	case Types::LONG_INT:
		return out << obj.m_data.long_int_type;
	case Types::UNSIGNED_LONG_INT:
		return out << obj.m_data.unsigned_long_int_type;
	case Types::LONG_LONG_INT:
		return out << obj.m_data.long_long_int_type;
	case Types::UNSIGNED_LONG_LONG_INT:
		return out << obj.m_data.unsigned_long_long_int_type;
	case Types::FLOAT:
		return out << obj.m_data.float_type;
	case Types::DOUBLE:
		return out << obj.m_data.double_type;
	case Types::LONG_DOUBLE:
		return out << obj.m_data.long_double_type;
	case Types::UNDEFINED:
		return out << "can't represent data";
	}
}

}