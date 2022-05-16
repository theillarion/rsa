//
// Created by illarion on 10.04.2022.
//

#ifndef RSA_BASIC_ALGORITHMS_HPP
#define RSA_BASIC_ALGORITHMS_HPP

#include <iostream>
#include <stdexcept>
#include <tuple>
#include <stack>
#include "algorithms/basic_functions/basic_functions.hpp"
#include "random/random.hpp"

namespace algorithms
{
	template<typename T>	T					FastPowMod(T a, T b, T n);
	template<typename T>	T					EuclideanAlgorithm(T a, T b);
	template<typename T>	std::tuple<T, T, T>	EuclideanExtendedAlgorithm(T a, T b);
	//		return: (NOD, s, d) (NOTE: s and d - bezout coefficients)

	template<typename T>	std::tuple<T, T, T>	Rsa(T p, T	q);
	//		return: (e, d, n) (NOTE: e - public exponent, d - private exponent, n - module)
}

#include "basic_algorithms.inl"

#endif