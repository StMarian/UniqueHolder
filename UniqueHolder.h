#pragma once
#include <typeinfo>
#include <ostream>
#include "bad_type.h"

namespace ISXUniqueHolder
{

const enum class Types {
	BOOL = 0, SIGNED_CHAR, UNSIGNED_CHAR, WCHAR_T, SHORT_INT, UNSIGNED_SHORT_INT, INT, UNSIGNED_INT, LONG_INT,
	UNSIGNED_LONG_INT, LONG_LONG_INT, UNSIGNED_LONG_LONG_INT, FLOAT, DOUBLE, LONG_DOUBLE, UNDEFINED
};

class UniqueHolder final
{
public:
	UniqueHolder();
	UniqueHolder(const UniqueHolder& holder);
	UniqueHolder(bool bool_type);
	UniqueHolder(signed char signed_char_type);
	UniqueHolder(unsigned char unsigned_char_type);
	UniqueHolder(wchar_t wchar_t_type);
	UniqueHolder(short int short_int_type);
	UniqueHolder(unsigned short int	unsigned_short_int_type);
	UniqueHolder(int int_type);
	UniqueHolder(unsigned int unsigned_int_type);
	UniqueHolder(long int long_int_type);
	UniqueHolder(unsigned long int unsigned_long_int_type);
	UniqueHolder(long long int long_long_int_type);
	UniqueHolder(unsigned long long int	unsigned_long_long_int_type);
	UniqueHolder(float float_type);
	UniqueHolder(double double_type);
	UniqueHolder(long double long_double_type);
	~UniqueHolder();

	UniqueHolder& operator=(const UniqueHolder& rhs);
	UniqueHolder& operator=(const bool rhs);
	UniqueHolder& operator=(const signed char rhs);
	UniqueHolder& operator=(const unsigned char rhs);
	UniqueHolder& operator=(const wchar_t rhs);
	UniqueHolder& operator=(const short int rhs);
	UniqueHolder& operator=(const unsigned short int rhs);
	UniqueHolder& operator=(const int rhs);
	UniqueHolder& operator=(const unsigned int rhs);
	UniqueHolder& operator=(const long int rhs);
	UniqueHolder& operator=(const unsigned long int rhs);
	UniqueHolder& operator=(const long long int rhs);
	UniqueHolder& operator=(const unsigned long long int rhs);
	UniqueHolder& operator=(const float rhs);
	UniqueHolder& operator=(const double rhs);
	UniqueHolder& operator=(const long double rhs);

	friend bool operator!=(const UniqueHolder& lhs, const UniqueHolder& rhs);
	friend std::ostream& operator<<(std::ostream& out, const UniqueHolder& obj);

	static void Swap(UniqueHolder& lhs, UniqueHolder& rhs);
	inline void ResetData() { this->m_data_type = Types::UNDEFINED; }

	bool ToBool() const;
	signed char ToSignedChar() const;
	unsigned char ToUnsignedChar() const;
	wchar_t	ToWchar_t() const;
	short int ToShortInt() const;
	unsigned short int ToUnsignedShortInt() const;
	int ToInt() const;
	unsigned int ToUnsignedInt() const;
	long int ToLongInt() const;
	unsigned long int ToUnsignedLongInt() const;
	long long int ToLongLongInt() const;
	unsigned long long int ToUnsignedLongLongInt() const;
	float ToFloat() const;
	double ToDouble() const;
	long double	ToLongDouble() const;

	const char* get_TypeName() const;

private:
	inline Types get_Type() const { return m_data_type; }

	// Data holder union
	union Holder
	{
		bool bool_type;

		signed char signed_char_type;
		unsigned char unsigned_char_type;
		wchar_t	wchar_t_type;

		short int short_int_type;
		unsigned short int unsigned_short_int_type;
		int	int_type;
		unsigned int unsigned_int_type;
		long int long_int_type;
		unsigned long int unsigned_long_int_type;
		long long int long_long_int_type;
		unsigned long long int unsigned_long_long_int_type;

		float float_type;
		double double_type;
		long double long_double_type;
	} m_data;

	Types m_data_type;
};

}