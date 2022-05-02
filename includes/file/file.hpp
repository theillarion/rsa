//
// Created by Illarion on 27.04.22.
//

#ifndef RSA_FILE_HPP
#define RSA_FILE_HPP

#include <string>
#include <fstream>

std::string	ReadFullFileBinary(const std::string&	path);
void		WriteFileBinary(const std::string&	path, const std::string&	src);

#endif //RSA_FILE_HPP
