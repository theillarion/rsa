//
// Created by illarion on 27.04.22.
//
#include "common.hpp"

std::string	DeEncryptionTextMethodRsa(const std::string&	text, mpz_class private_exponent, mpz_class module)
{
	std::string				result;
	std::vector<std::string>	numbers;

	boost::split(numbers, text, boost::is_any_of(L" "));
	for (const auto& word: numbers)
	{
		result += static_cast<char>(algorithms::FastPowMod<mpz_class>(mpz_class(word), private_exponent, module).get_ui());
	}
	return (result);
}
