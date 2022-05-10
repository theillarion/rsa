#include "common.hpp"
#include <filesystem>

int main()
{
	mpz_class p;
	mpz_class q;
	std::wstring original_text;
	std::wstring encrypt_text;
	std::wstring deencrypt_text;

	try
	{
		p = GenerateSimpleNumber(1024);
		q = GenerateSimpleNumber(1024);

		auto [e, d, n] = algorithms::Rsa(p, q);

		original_text = BinaryReadUtf8File("test/input.txt");

		encrypt_text = EncryptionTextMethodRsa(original_text, e, n);
		deencrypt_text = DeEncryptionTextMethodRsa(encrypt_text, d, n);

		BinaryWriteUtf8File("test/output_encrypt.txt", encrypt_text);
		BinaryWriteUtf8File("test/output_decrypt.txt", deencrypt_text);
	}
	catch(const std::exception& exp)
	{
		std::cout << "\033[91m" << "Exception: " << "\033[0m" << exp.what() << std::endl;
	}

	return (0);
}
