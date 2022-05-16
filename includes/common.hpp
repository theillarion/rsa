//
// Created by illarion on 27.04.22.
//

#ifndef RSA_COMMON_HPP
#define RSA_COMMON_HPP

#include <string>
#include <thread>
#include <filesystem>
#include "gmpxx.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "algorithms/basic_functions/basic_functions.hpp"
#include "algorithms/basic_algorithms/basic_algorithms.hpp"
#include "simple_number/simple_number.hpp"
#include "utilities/utilities.hpp"
#include "random/random.hpp"
#include "file/file.hpp"

std::wstring	EncryptionTextMethodRsa(const std::wstring&	text, const mpz_class& public_exponent, const mpz_class&	module);
std::wstring	DeEncryptionTextMethodRsa(const std::wstring&	text, const mpz_class& private_exponent, const mpz_class&	module);
int				main(int argc, char **argv);

#endif //RSA_COMMON_HPP
