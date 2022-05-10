//
// Created by Illarion on 27.04.22.
//

#ifndef RSA_FILE_HPP
#define RSA_FILE_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include <filesystem>

std::wstring	BinaryReadUtf8File(const std::string& path);
void	BinaryWriteUtf8File(const std::string& path, const std::wstring&	buff);

#endif //RSA_FILE_HPP
