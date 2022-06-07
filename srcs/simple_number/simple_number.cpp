//
// Created by illarion on 16.05.22.
//
#include "simple_number/simple_number.hpp"

bool	TestMillerRabin(const mpz_class& number, unsigned int r)
{
	mpz_class	a;
	mpz_class	x;
	bool		is_find;

	auto [s, d] = algorithms::NumberDecomposition(number);
	for (unsigned int i = 0; i < r; ++i)
	{
		is_find = false;
		a = GenerateBigNumberInterval(2, number - 1);
		x = algorithms::FastPowMod(a, d, number);
		if (x == 1 || x == number - 1)
			continue ;
		for (mpz_class j = 0; j < s - 1; ++j)
		{
			x = algorithms::FastPowMod(x, mpz_class(2), number);
			if (x == 1)
				return (false);
			if (x == number - 1)
			{
				is_find = true;
				break;
			}
		}
		if (!is_find)
			return false;
	}
	return (true);
}

static bool	FirstSimpleTest(const mpz_class&	number)
{
	return (number % 3 == 0 || number % 5 == 0
			|| number % 7 == 0 || number % 11 == 0);
}

mpz_class 	GenerateBigSimpleNumber(unsigned int	bit)
{

	mpz_class result = GenerateBigNumberFixed(bit);

	if (result % 2 == 0)
		++result;
	while (FirstSimpleTest(result) || !TestMillerRabin(result, bit))
		result += 2;

	return (result);
}
