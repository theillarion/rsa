//
// Created by illarion on 27.04.22.
//
#include "common.hpp"

std::string	EncryptionTextMethodRsa(const std::string&	text, mpz_class public_exponent, mpz_class module)
{
	std::string	result;

	for (auto it = text.begin(); it != text.end(); ++it)
	{
		result += algorithms::FastPowMod<mpz_class>(mpz_class((unsigned int)*it), public_exponent, module).get_str();
		if (it != text.end() - 1)
			result += ' ';
	}
	return (result);
}
