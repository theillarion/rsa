//
// Created by illarion on 27.04.22.
//
#include "common.hpp"

std::wstring	EncryptionTextMethodRsa(const std::wstring&	text, const mpz_class& public_exponent, const mpz_class&
module)
{
	std::wstring	result;
	std::string		temp;

	for (auto it = text.begin(); it != text.end(); ++it)
	{
		temp = algorithms::FastPowMod<mpz_class>(mpz_class((unsigned int)*it), public_exponent, module).get_str();
		result += std::wstring(temp.begin(), temp.end());
		if (it != text.end() - 1)
			result += ' ';
	}
	return (result);
}
