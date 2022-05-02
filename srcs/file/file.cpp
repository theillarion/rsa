//
// Created by Illarion on 27.04.22.
//
#include "file/file.hpp"

std::string	ReadFullFileBinary(const std::string&	path)
{
	std::string		result;
	std::ifstream	file;
	size_t			size;

	file.open(path, std::ios::binary | std::ios::ate);
	if (!file.is_open())
		throw std::invalid_argument("Path " + path + " isn't valid");

	size = file.tellg();
	result.resize(size, '\n');
	file.seekg(0);

	if (!file.read(&result[0], size))
		throw std::ifstream::failure("Error read file " + path);

	return (result);
}

void	WriteFileBinary(const std::string&	path, const std::string&	src)
{
	std::ofstream file;

	file.open(path, std::ios::trunc);
	if (!file.is_open())
		throw std::invalid_argument("Path " + path + " isn't valid");
	if (!file.write(&src[0], src.size()))
		throw std::ifstream::failure("Error read file " + path);
}
