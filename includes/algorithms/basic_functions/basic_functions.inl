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
inline T	algorithms::Pow(T	basis, T exp)
{
	if (exp == 1 || basis == 0)
		return (basis);
	else if (exp == 0 || basis == 1)
		return (1);
	else
		return (basis * Pow<T>(basis, exp - 1));
}

template<typename T>
inline T algorithms::GetCountBit(T number)
{
	T	i;
	T	count;

	count = 0;
	i = 1;
	if (number < 0)
		number = -number;
	if (number == 0)
		return (1);
	while (i <= number)
	{
		i = i << 1;
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
