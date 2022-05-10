//
// Created by illarion on 27.04.22.
//

#ifndef RSA_COMMON_HPP
#define RSA_COMMON_HPP

#include "gmpxx.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "algorithms/algorithms.hpp"
#include "random/random.hpp"
#include "algorithms/check_simple/miller_rabin_test.hpp"
#include "file/file.hpp"
#include <string>

std::wstring	EncryptionTextMethodRsa(const std::wstring&	text, mpz_class public_exponent, mpz_class module);
std::wstring	DeEncryptionTextMethodRsa(const std::wstring&	text, mpz_class private_exponent, mpz_class module);

int	main();

#endif //RSA_COMMON_HPP
