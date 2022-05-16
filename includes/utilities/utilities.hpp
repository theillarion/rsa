//
// Created by illarion on 16.05.22.
//

#ifndef RSA_UTILITIES_HPP
#define RSA_UTILITIES_HPP

#include "gmpxx.h"
#include "simple_number/simple_number.hpp"
#include <sstream>

void	thread_calc_big_number(mpz_class&	result, unsigned int bit);

template <typename Type> Type from_string(const std::string	&src, bool &is_failed);

#include "utilities.inl"

#endif //RSA_UTILITIES_HPP
