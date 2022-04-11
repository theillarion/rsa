//
// Created by illarion on 10.04.2022.
//

#include "../includes/algorithms.hpp"

std::tuple<long long, long long, long long> algorithms::EuclideanExtendedAlgorithm(long long a, long long b)
{
	std::stack<long long>	divs;
	long long mod;
	long long s = 0;
	long long d = 1;

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
		std::tie(s, d) = std::make_tuple(d, s - d * divs.top());
		divs.pop();
	}
	return (std::make_tuple(b, s, d));
}

