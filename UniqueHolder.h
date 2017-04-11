#pragma once
#include <ostream>

namespace UHolder
{

class bad_type;

const enum class Types {
	UNDEFINED = -1,
	BOOL = 0, 
	SIGNED_CHAR = 1, 
	UNSIGNED_CHAR = 2,
	WCHAR_T = 3, 
	SHORT_INT = 4, 
	UNSIGNED_SHORT_INT = 5, 
	INT = 6,
	UNSIGNED_INT = 7,
	LONG_INT = 8,
	UNSIGNED_LONG_INT = 9,
	LONG_LONG_INT = 10,
	UNSIGNED_LONG_LONG_INT = 11,
	FLOAT = 12,
	DOUBLE = 13, 
	LONG_DOUBLE = 14,
};

class UniqueHolder final
{
public:
	UniqueHolder();
	UniqueHolder(const UniqueHolder& holder);
	UniqueHolder(UniqueHolder&& holder);
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
	~UniqueHolder() = default;

	UniqueHolder& operator=(const UniqueHolder& rhs);
	UniqueHolder& operator=(UniqueHolder&& rhs);

	friend bool operator!=(const UniqueHolder& lhs, const UniqueHolder& rhs);
	friend std::ostream& operator<<(std::ostream& out, const UniqueHolder& obj);

	static void Swap(UniqueHolder& lhs, UniqueHolder& rhs);
	void ResetData() { this->m_data_type = Types::UNDEFINED; }

	int ConvertToInt();

	const char* get_TypeName() const;
	bool get_Bool() const;
	signed char get_SignedChar() const;
	unsigned char get_UnsignedChar() const;
	wchar_t	get_Wchar_t() const;
	short int get_ShortInt() const;
	unsigned short int get_UnsignedShortInt() const;
	int get_Int() const;
	unsigned int get_UnsignedInt() const;
	long int get_LongInt() const;
	unsigned long int get_UnsignedLongInt() const;
	long long int get_LongLongInt() const;
	unsigned long long int get_UnsignedLongLongInt() const;
	float get_Float() const;
	double get_Double() const;
	long double get_LongDouble() const;
	
private:
	Types m_data_type;
	Types get_Type() const { return m_data_type; }

	// Data holder union
	union Holder
	{
		bool bool_type;

		signed char signed_char_type;
		unsigned char unsigned_char_type;
		wchar_t	wchar_t_type;

		short int short_int_type;
		unsigned short int unsigned_short_int_type;
		int int_type;
		unsigned int unsigned_int_type;
		long int long_int_type;
		unsigned long int unsigned_long_int_type;
		long long int long_long_int_type;
		unsigned long long int unsigned_long_long_int_type;

		float float_type;
		double double_type;
		long double long_double_type;
	} m_data;
};

}