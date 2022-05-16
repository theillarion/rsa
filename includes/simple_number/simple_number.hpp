//
// Created by illarion on 16.05.22.
//

#ifndef RSA_SIMPLE_NUMBER_HPP
#define RSA_SIMPLE_NUMBER_HPP

#include "gmpxx.h"
#include "algorithms/basic_algorithms/basic_algorithms.hpp"
#include "algorithms/basic_functions/basic_functions.hpp"
#include "random/random.hpp"

bool		TestMillerRabin(const mpz_class& number, unsigned int r);
//		return: true - simple number, false - composite number

mpz_class 	GenerateBigSimpleNumber(unsigned int	bit);
//		return: random simple number [2^bit, +∞]

#endif //RSA_SIMPLE_NUMBER_HPP
