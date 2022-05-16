//
// Created by illarion on 09.05.22.
//

#ifndef RSA_RANDOM_HPP
#define RSA_RANDOM_HPP

# include <chrono>
# include "gmpxx.h"
# include "algorithms/basic_functions/basic_functions.hpp"

mpz_class	GenerateBigNumber(const mpz_class&	max_number);
//		return: random number [0, max_number - 1]

mpz_class	GenerateBigNumberInterval(const mpz_class&	min_number, const mpz_class&	max_number);
//		return: random number [min_number, max_number]

mpz_class	GenerateBigNumberInterval(unsigned int	max_bit);
//		return: random number [0, 2^max_bit - 1]

mpz_class	GenerateBigNumberFixed(unsigned int	bit);
//		return: random number [2^bit, 2^(bit + 1) - 1]

#endif //RSA_RANDOM_HPP
