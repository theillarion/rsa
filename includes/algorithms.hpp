//
// Created by illarion on 10.04.2022.
//

#ifndef RSA_ALGORITHMS_HPP
#define RSA_ALGORITHMS_HPP

#include <iostream>
#include <stdexcept>
#include <tuple>
#include <stack>
#include "basic_functions.hpp"

using namespace basic_functions;

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

	template<typename T>
	inline std::tuple<T, T, T> Rsa(T p, T	q);
}

template <typename T>
inline T algorithms::FastPowMod(T a, T b, T n)
{
	T	c = a;
	T	i;

	if (a == 1 || b == 0)
		return (1);
	i = Pow<T>(2, GetCountBit<T>(b) - 1) / 2;
	while (i > 0)
	{
		if ((b & i) != 0)
			c = (c * c * a) % n;
		else
			c = (c * c) % n;
		i /= 2;
	}
	return (c);
}

template <typename T>
inline T	algorithms::EuclideanAlgorithm(T a, T b)
{
	if (a < 1 || b < 1)
		throw std::invalid_argument("a or b incorrect");
	if (a < b)
		std::tie(b, a) = std::make_tuple(a, b);
	if (a == 1 || b == 1)
		return (1);
	else if (a % b != 0)
		return (EuclideanAlgorithm<T>(b, a % b));
	else
		return (b);
}

template<typename T>
inline std::tuple<T, T, T> algorithms::EuclideanExtendedAlgorithm(T a, T b)
{
	std::stack<T>	divs;
	T s_old	= 0;
	T mod	= 0;
	T s 	= 0;
	T d		= 1;

	if (a < 1 || b < 1)
		throw std::invalid_argument("a or b incorrect");
	if (a == 0)
		return std::make_tuple(b, 0, 1);
	if (a < b)
		std::tie(b, a) = std::make_tuple(a, b);
	divs.push(a / b);
	mod = a % b;
	while (mod)
	{
		a = b;
		b = mod;
		divs.push(a / b);
		mod = a % b;
	}
	divs.pop();
	while (!divs.empty())
	{
		s_old = s;
		s = d;
		d = s_old - d * divs.top();
		//std::tie(s, d) = std::make_tuple(d, s - d * divs.top());
		divs.pop();
	}
	return (std::make_tuple(b, s, d));
}

template<typename T>
inline std::tuple<T, T, T> algorithms::Rsa(T p, T	q)
{
	T	n = p * q;
	T	phi = (p - 1) * (q - 1);
	T	e = 2;
	T	d;

	while (e < phi)
	{
		if (algorithms::EuclideanAlgorithm<T>(e, phi) == 1)
			break;
		++e;
	}
	std::tie(std::ignore, std::ignore, d) = algorithms::EuclideanExtendedAlgorithm<T>(phi, e);
	if (d < 0)
		d = basic_functions::Mod(d, phi);
	return (std::make_tuple(e, d, n));
}

#endif