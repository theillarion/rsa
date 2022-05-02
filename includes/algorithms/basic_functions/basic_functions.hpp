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
	T	Pow(T	basis, T exp);

	template<typename T>
	T	Mod(T number, T mod);

	template<typename T>
	T	GetCountBit(T number);
}

# include "basic_functions.inl"

#endif //RSA_BASIC_FUNCTIONS_HPP
