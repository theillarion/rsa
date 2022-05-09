//
// Created by illarion on 09.05.22.
//
#include "random/random.hpp"

mpz_class	GenerateBigNumber(const mpz_class&	max_number)
{
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	gmp_randstate_t rstate;
	gmp_randinit_mt(rstate);
	gmp_randseed_ui(rstate, seed);
	mpz_class	result;

	mpz_urandomb(result.get_mpz_t(), rstate, algorithms::GetCountBit(max_number));
	if (result > max_number)
		return (result % max_number);
	return (result);
}

mpz_class	GenerateBigNumber(unsigned int	count_bits)
{
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	gmp_randstate_t rstate;
	gmp_randinit_mt(rstate);
	gmp_randseed_ui(rstate, seed);
	mpz_class	result;

	mpz_urandomb(result.get_mpz_t(), rstate, count_bits);
	return (result);
}

static bool	FirstSimpleTest(const mpz_class&	number)
{
	return (number % 3 == 0 || number % 5 == 0
			|| number % 7 == 0 || number % 11 == 0);
}

mpz_class 	GenerateSimpleNumber(unsigned int	count_bits_max)
{

	mpz_class result = GenerateBigNumber(count_bits_max);

	if (result % 2 == 0)
		++result;
	while (FirstSimpleTest(result) || !TestMillerRabin(result, 5))
		result += 2;

	return (result);
}
