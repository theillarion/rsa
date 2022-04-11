#include <iostream>
#include <codecvt>
#include <string>
#include <locale>
#include <cmath>
#include <fstream>
#include "gmpxx.h"
#include <boost/algorithm/string/split.hpp>
//#include "algorithms.hpp"
#include "includes/basic_functions.hpp"
#include "includes/algorithms.hpp"

template<typename T>
std::tuple<T, T> ft_rsa(T p, T	q)
{
	T	n = p * q;
	T	phi = (p - 1) * (q - 1);
	T	e = 2;
	T	d;

	while (e < phi)
	{
		if (algorithms::EuclideanAlgorithm<T>(e, phi) == 1)
			break;
		++e;
	}
	std::tie(std::ignore, std::ignore, d) = algorithms::EuclideanExtendedAlgorithm<T>(phi, e);
	if (d < 0)
		d = basic_functions::Mod(d, phi);
	return (std::make_tuple(e, d));
}

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
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	wout << converter.from_bytes(src.get_str());
	return (wout);
}

int main()
{
	setlocale(LC_ALL, "ru_RU.utf8");
	std::wifstream file_input("../test/input.txt");
	std::wofstream file_output("../test/output_crypt.txt", std::ios_base::trunc);
	//std::wofstream file_output2("../test/output_decrypt.txt", std::ios_base::trunc);

	file_input.imbue(std::locale(file_input.getloc(), new std::codecvt_utf8<wchar_t>));
	file_output.imbue(std::locale(file_output.getloc(), new std::codecvt_utf8<wchar_t>));
	//file_output2.imbue(std::locale(file_output2.getloc(), new std::codecvt_utf8<wchar_t>));
	std::wstring buff;
	mpz_class p;
	mpz_class q;
	mpz_class e;
	mpz_class d;
	mpz_class n;

	p = 89;
	q = 79;
	n = p * q;
	std::tie(e, d) = ft_rsa<mpz_class>(p, q);

	std::cout << "e = " << e << std::endl << "d = " << d << std::endl << "n = " << n << std::endl;


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
	file_input.open("../test/output_crypt.txt");
	file_output.open("../test/output_decrypt.txt", std::ios_base::trunc);

	file_input.imbue(std::locale(file_input.getloc(), new std::codecvt_utf8<wchar_t>));
	file_output.imbue(std::locale(file_output.getloc(), new std::codecvt_utf8<wchar_t>));

	if (file_input.is_open() && file_output.is_open())
	{
		while (!file_input.eof() && file_input.good())
		{
			mpz_class		crypt_message;
			mpz_class		deencrypt_message;
			unsigned long 	number;

			file_input >> number;
			crypt_message = number;
			deencrypt_message = algorithms::FastPowMod<mpz_class>(crypt_message, d, n);
			file_output << static_cast<wchar_t >(deencrypt_message.get_ui());
		}
		/*std::vector<std::wstring> numbers;
			std::getline(file_input, buff);
			if (!file_input.eof() && file_input.good())
				buff += L'\n';
			*/
		std::cout << "Success decrypt" << std::endl;
	}
	/*mpz_class g, a, b, n;
	a = 2;
	b = 1024;
	n = 100000000;
	g = algorithms::FastPowMod<mpz_class>(a, b, n);
	std::cout << g;*/
}

//		0 - 0    - 1s
//		1 - 1    - 1
//		2 - 10   - 2
//      3 - 11   - 2
//		4 - 100  - 3
//		5 - 101  - 3
//		7 - 111  - 3
//		8 - 1000 - 4
