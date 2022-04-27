//
// Created by illarion on 27.04.22.
//

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
