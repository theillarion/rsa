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
		mpz_class	message;
		mpz_class	encrypt_message;

		message = std::stoul(word);
		encrypt_message = algorithms::FastPowMod<mpz_class>(message, private_exponent, module);
		result += static_cast<char>(encrypt_message.get_ui());
	}
	return (result);
}
