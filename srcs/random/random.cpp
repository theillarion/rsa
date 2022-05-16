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

mpz_class	GenerateBigNumberInterval(const mpz_class&	min_number, const mpz_class&	max_number)
{
	return (min_number + GenerateBigNumber(max_number - min_number + 1));
}

mpz_class	GenerateBigNumberInterval(unsigned int	max_bit)
{
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	gmp_randstate_t rstate;
	gmp_randinit_mt(rstate);
	gmp_randseed_ui(rstate, seed);
	mpz_class	result;

	mpz_urandomb(result.get_mpz_t(), rstate, max_bit);
	return (result);
}


mpz_class	GenerateBigNumberFixed(unsigned int	bit)
{
	return ((GenerateBigNumberInterval(bit) | (mpz_class)algorithms::Pow(2, bit)));
}
