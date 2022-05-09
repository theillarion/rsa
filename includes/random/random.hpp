//
// Created by illarion on 09.05.22.
//

#ifndef RSA_RANDOM_HPP
#define RSA_RANDOM_HPP

# include <chrono>
# include "gmpxx.h"
# include "algorithms/basic_functions/basic_functions.hpp"
# include "algorithms/check_simple/miller_rabin_test.hpp"

mpz_class	GenerateBigNumber(unsigned int	count_bits);
mpz_class	GenerateBigNumber(const mpz_class&	max_number);
mpz_class 	GenerateSimpleNumber(unsigned int	count_bits_max);

#endif //RSA_RANDOM_HPP
