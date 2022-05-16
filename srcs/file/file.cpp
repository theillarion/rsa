//
// Created by Illarion on 27.04.22.
//
#include "file/file.hpp"

std::wstring	BinaryReadUtf8File(const std::string& path)
{
	std::wifstream		file;
	std::wstringstream	buff;

	if (!std::filesystem::is_regular_file(path))
		throw std::invalid_argument("path \"" + path + "\" is't a file");

	file.open(path, std::ios::binary);
	if (!file.is_open())
		throw std::ifstream::failure("file \"" + path + "\" is't open");
	file.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

	buff << file.rdbuf();

	if (!file)
		throw std::ifstream::failure("only " + std::to_string(file.gcount()) + " byte could be read");

	file.close();

	return (buff.str());
}

void	BinaryWriteUtf8File(const std::string& path, const std::wstring&	buff)
{
	std::wofstream	file;

	file.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
	file.open(path, std::ios::binary | std::ios::trunc);
	if (!file.is_open())
		throw std::ifstream::failure("file \"" + path + "\" is't open");

	file.write(&buff[0], static_cast<std::streamsize>(buff.size()));
	if (!file)
		throw std::ifstream::failure("error write");

	file.close();
}
