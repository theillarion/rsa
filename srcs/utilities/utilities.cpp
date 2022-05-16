//
// Created by illarion on 16.05.22.
//
#include "utilities/utilities.hpp"

void	thread_calc_big_number(mpz_class&	result, unsigned int bit)
{
	try
	{
		result = GenerateBigSimpleNumber(bit);
	}
	catch(const std::exception& exp)
	{
		result = 0;
	}
}
