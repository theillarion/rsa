#include "basic_functions.hpp"

template<typename T>
inline T	algorithms::CalcDischarge(T number)
{
	if (number <= 9 && number >= -9)
		return (1);
	else
		return (1 + CalcDischarge(number / 10));
}

template<typename T>
inline T	algorithms::Pow(T basis, unsigned int exp)
{
	T result = 1;

	if (basis == 0)
		return (0);
	else if (basis == 1 || exp == 0)
		return (1);
	while (exp != 0)
	{
		result *= basis;
		--exp;
	}
	return (result);
}

template<typename T>
inline unsigned int algorithms::GetCountBit(T number)
{
	unsigned int	count;

	count = 0;
	if (number < 0)
		number = -number;
	if (number == 0)
		return (1);
	while (number)
	{
		number >>= 1;
		++count;
	}
	return (count);
}

template<typename T>
inline T algorithms::Mod(T number, T mod)
{
	if (number >= 0)
		return (number % mod);
	else
		while (number < 0)
			number += mod;
	return (number % mod);
}

template <typename T>
inline std::tuple<T, T>	algorithms::NumberDecomposition(T	n)
{
	T	d = n - 1;
	T	s = 0;

	if (n < 2)
		throw std::invalid_argument("argument mast be less than 2");
	if (n % 2 == 0)
		throw std::invalid_argument("argument must not be an even number");

	while (d % 2 == 0)
	{
		d /= 2;
		++s;
	}
	return std::make_tuple(s, d);
}
