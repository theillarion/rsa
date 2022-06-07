#include "basic_algorithms.hpp"

template <typename T>
T algorithms::FastPowMod(T a, T b, T n)
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
T	algorithms::EuclideanAlgorithm(T a, T b)
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
std::tuple<T, T, T> algorithms::EuclideanExtendedAlgorithm(T a, T b)
{
	std::stack<T>	divs;
	T				s_old	= 0;
	T				mod		= 0;
	T				s		= 0;
	T				d		= 1;

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
		divs.pop();
	}
	return (std::make_tuple(b, s, d));
}

template<typename T>
std::tuple<T, T, T> algorithms::Rsa(T p, T	q)
{
	T	n = p * q;
	T	phi = (p - 1) * (q - 1);
	T	e;
	T	d;

	e = GenerateBigNumberInterval(16);
	if (e % 2 == 0)
		++e;
	while (e < phi)
	{
		if (algorithms::EuclideanAlgorithm<T>(e, phi) == 1)
			break;
		e += 2;
	}
	std::tie(std::ignore, std::ignore, d) = algorithms::EuclideanExtendedAlgorithm<T>(phi, e);
	if (d < 0)
		d = algorithms::Mod(d, phi);
	return (std::make_tuple(e, d, n));
}
