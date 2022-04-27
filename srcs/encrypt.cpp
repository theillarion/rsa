//
// Created by illarion on 27.04.22.
//
#include "common.hpp"

std::string	EncryptionTextMethodRsa(const std::string&	text, mpz_class public_exponent, mpz_class module)
{
	std::string	result;
	bool		is_first;

	is_first = true;
	for (const auto& symbol: text)
	{
		mpz_class	message;
		mpz_class	encrypt_message;

		//mpz_class((unsigned int)symbol);
		message = (unsigned long)symbol;
		encrypt_message = algorithms::FastPowMod<mpz_class>(message, public_exponent, module);
		if (!is_first)
			result += ' ';
		result += encrypt_message.get_str();
		is_first = false;
	}
	return (result);
}
