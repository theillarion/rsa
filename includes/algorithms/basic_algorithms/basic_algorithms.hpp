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

namespace algorithms
{
	template<typename T>
	T	FastPowMod(T a, T b, T n);

	template<typename T>
	T	EuclideanAlgorithm(T a, T b);

	template<typename T>
	std::tuple<T, T, T>	EuclideanExtendedAlgorithm(T a, T b);
	/*
		return: (NOD, s, d)
			s and d -	bezout coefficients
	*/
}

#include "basic_algorithms.inl"

#endif