#include <iostream>
#include <codecvt>
#include <string>
#include <locale>
#include <cmath>
#include <fstream>
#include "gmpxx.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
//#include "algorithms.hpp"
#include "basic_functions.hpp"
#include "algorithms.hpp"

bool    IsAlpha(wchar_t symbol)
{
	if ((unsigned int)symbol >= L'а' && (unsigned int)symbol <= L'я' ||
		(unsigned int)symbol >= L'А' && (unsigned int)symbol <= L'Я' ||
		(unsigned int)symbol >= L'a' && (unsigned int)symbol <= L'z' ||
		(unsigned int)symbol >= L'A' && (unsigned int)symbol <= L'Z' ||
		(unsigned int)symbol == L'ё' || (unsigned int)symbol == L'Ё')
		return (true);
	return (false);
}

std::wofstream& operator<<(std::wofstream&	wout,	mpz_class&	src)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	wout << converter.from_bytes(src.get_str());
	return (wout);
}

template<typename T>
std::wstring	EncryptionTextMethodRsa(const std::wstring&	text, T public_exponent, T module)
{
	std::wstring	result;
	bool			is_first;

	is_first = true;
	for (const auto& symbol: text)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		mpz_class	message;
		mpz_class	encrypt_message;

		//mpz_class((unsigned int)symbol);
		message = (unsigned long)symbol;
		encrypt_message = algorithms::FastPowMod<mpz_class>(message, public_exponent, module);
		if (!is_first)
			result += L' ';
		result += converter.from_bytes(encrypt_message.get_str());
		is_first = false;
	}
	return (result);
}

template<typename T>
std::wstring	DeEncryptionTextMethodRsa(const std::wstring&	text, T private_exponent, T module)
{
	std::wstring				result;
	std::vector<std::wstring>	numbers;

	boost::split(numbers, text, boost::is_any_of(L" "));
	for (const auto& word: numbers)
	{
		mpz_class	message;
		mpz_class	encrypt_message;

		message = std::stoul(word);
		encrypt_message = algorithms::FastPowMod<mpz_class>(message, private_exponent, module);
		result += static_cast<wchar_t>(encrypt_message.get_ui());
	}
	return (result);
}

int main()
{
	mpz_class p;
	mpz_class q;
	mpz_class e;
	mpz_class d;
	mpz_class n;
	std::wstring buff;
	std::wifstream file_input;
	std::wofstream file_output;

	setlocale(LC_ALL, "ru_RU.utf8");
	file_input.open("../test/input.txt");
	file_output.open("../test/output_crypt.txt", std::ios_base::trunc);

	file_input.imbue(std::locale(file_input.getloc(), new std::codecvt_utf8<wchar_t>));
	file_output.imbue(std::locale(file_output.getloc(), new std::codecvt_utf8<wchar_t>));

	p = 3557;
	q = 2579;
	std::tie(e, d, n) = algorithms::Rsa<mpz_class>(p, q);

	//std::cout << "e = " << e << std::endl << "d = " << d << std::endl << "n = " << n << std::endl;

	if (!file_input.is_open() || !file_output.is_open())
	{
		std::cout << "Error" << std::endl;
		return (EXIT_FAILURE);
	}
	else
	{
		mpz_class	symbol_endline = (unsigned int)'\n';
		symbol_endline = algorithms::FastPowMod<mpz_class>(symbol_endline, e, n);
		while (!file_input.eof() && file_input.good())
		{
			size_t	i = 0;
			std::getline(file_input, buff);
			if (!file_input.eof() && file_input.good())
				buff += L'\n';
			for (const auto& symbol : buff)
			{
				mpz_class	message;
				mpz_class	encrypt_message;

				if (symbol == L'\n')
					encrypt_message = symbol_endline;
				else
				{
					message = (int)symbol;
					encrypt_message = algorithms::FastPowMod<mpz_class>(message, e, n);
				}
				if (i != 0)
					file_output << ' ';
				file_output << encrypt_message;
				++i;
			}
			if (!file_input.eof() && file_input.good())
				file_output << ' ';
			buff.clear();
		}
		file_input.close();
		file_output.close();
		std::cout << "Success crypt" << std::endl;
	}
	std::wofstream file_output2;

	file_input.open("../test/output_crypt.txt");
	file_output2.open("../test/output_decrypt.txt", std::ios_base::trunc);

	file_input.imbue(std::locale(file_input.getloc(), new std::codecvt_utf8<wchar_t>));
	file_output2.imbue(std::locale(file_output2.getloc(), new std::codecvt_utf8<wchar_t>));

	if (file_input.is_open() && file_output2.is_open())
	{
		while (!file_input.eof() && file_input.good())
		{
			mpz_class		crypt_message;
			mpz_class		deencrypt_message;
			unsigned long 	number;

			file_input >> number;
			crypt_message = number;
			deencrypt_message = algorithms::FastPowMod<mpz_class>(crypt_message, d, n);
			file_output2 << static_cast<wchar_t >(deencrypt_message.get_ui());
		}
		file_input.close();
		file_output2.close();
		std::cout << "Success decrypt" << std::endl;
	}
}
