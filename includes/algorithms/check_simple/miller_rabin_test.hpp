//
// Created by illarion on 09.05.22.
//

#ifndef RSA_MILLER_RABIN_TEST_HPP
#define RSA_MILLER_RABIN_TEST_HPP

# include "gmpxx.h"
# include "algorithms/basic_algorithms/basic_algorithms.hpp"
# include "random/random.hpp"

bool	TestMillerRabin(const mpz_class& number, unsigned int r);

#endif //RSA_MILLER_RABIN_TEST_HPP
