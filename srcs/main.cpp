#include "common.hpp"
#include <filesystem>

template <typename Type>
std::vector<std::vector<Type>>	ReadAllLineFromFile(const std::string& path)
{
	std::ifstream					file;
	std::vector<std::vector<Type>>	result;
	std::string						line_buffer;

	if (!std::filesystem::is_regular_file(path))
		throw std::invalid_argument("File: " + path + " isn't exists");

	file.open(path);
	if (!file.is_open())
		throw std::ifstream::failure("File: " + path + " isn't open");

	while (std::getline(file, line_buffer))
	{
		std::vector<Type>	numbers;
		std::stringstream	buff(line_buffer);

		std::copy(std::istream_iterator<Type>(buff), std::istream_iterator<Type>(), std::back_inserter(numbers));
		result.push_back(numbers);
	}
	file.close();
	return (result);
}

int main()
{
	mpz_class p;
	mpz_class q;
	std::string original_text;
	std::string encrypt_text;
	std::string deencrypt_text;

	p = GenerateSimpleNumber(1024);
	q = GenerateSimpleNumber(1024);

	//std::cout << "P = " << p << std::endl << "Q = " << q << std::endl;

	auto [e, d, n] = algorithms::Rsa(p, q);

	//std::cout << "E = " << e << std::endl << "D = " << d << std::endl << "N = " << n << std::endl;

	original_text = ReadFullFileBinary("test/input.txt");

	encrypt_text = EncryptionTextMethodRsa(original_text, e, n);
	deencrypt_text = DeEncryptionTextMethodRsa(encrypt_text, d, n);

	WriteFileBinary("test/output_encrypt.txt", encrypt_text);
	WriteFileBinary("test/output_decrypt.txt", deencrypt_text);

	return (0);
}
