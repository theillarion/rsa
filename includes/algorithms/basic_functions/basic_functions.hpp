//
// Created by illarion on 10.04.2022.
//

#ifndef RSA_BASIC_FUNCTIONS_HPP
#define RSA_BASIC_FUNCTIONS_HPP

# include <cstddef>

namespace algorithms
{
	template<typename T>
	T 	CalcDischarge(T  number);

	template<typename T>
	T	Pow(T basis, unsigned int exp);

	template<typename T>
	T	Mod(T number, T mod);

	template<typename T>
	unsigned int GetCountBit(T number);

	template <typename T>
	std::tuple<T, T>	NumberDecomposition(T	n);
}

# include "basic_functions.inl"

#endif //RSA_BASIC_FUNCTIONS_HPP
