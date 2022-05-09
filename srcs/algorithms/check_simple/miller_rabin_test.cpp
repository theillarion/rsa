//
// Created by illarion on 09.05.22.
//
#include "algorithms/check_simple/miller_rabin_test.hpp"

bool	TestMillerRabin(const mpz_class& number, unsigned int r)
{
	mpz_class a;
	mpz_class x;
	bool is_find;

	auto [s, d] = algorithms::NumberDecomposition(number);
	for (unsigned int i = 0; i < r; ++i)
	{
		is_find = false;
		a = 1 + GenerateBigNumber(number - 2);
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
