//
// Created by illarion on 27.04.22.
//
#include "common.hpp"

std::wstring	DeEncryptionTextMethodRsa(const std::wstring&	text, const mpz_class& private_exponent, const
mpz_class& module)
{
	std::wstring				result;
	std::vector<std::string>	numbers;

	boost::split(numbers, text, boost::is_any_of(L" "));
	for (const auto& word: numbers)
	{
		result += static_cast<wchar_t>(algorithms::FastPowMod<mpz_class>(mpz_class(word), private_exponent, module)
		        .get_ui());
	}
	return (result);
}
