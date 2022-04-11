//
// Created by illarion on 10.04.2022.
//

#ifndef RSA_BASIC_FUNCTIONS_HPP
#define RSA_BASIC_FUNCTIONS_HPP

# include <cstddef>

namespace basic_functions
{
	template<typename T>
	T 	CalcDischarge(T  number);

	template<typename T>
	T	Pow(T	basis, T exp);

	template<typename T>
	T	Mod(T number, T mod);

	template<typename T>
	T	GetCountBit(T number);
}

template<typename T>
inline T	basic_functions::CalcDischarge(T number)
{
	if (number <= 9 && number >= -9)
		return (1);
	else
		return (1 + CalcDischarge(number / 10));
}

template<typename T>
inline T	basic_functions::Pow(T	basis, T exp)
{
	if (exp == 1 || basis == 0)
		return (basis);
	else if (exp == 0 || basis == 1)
		return (1);
	else
		return (basis * Pow<T>(basis, exp - 1));
}

template<typename T>
inline T basic_functions::GetCountBit(T number)
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
inline T basic_functions::Mod(T number, T mod)
{
	if (number >= 0)
		return (number % mod);
	else
		while (number < 0)
			number += mod;
	return (number % mod);
}

#endif //RSA_BASIC_FUNCTIONS_HPP
