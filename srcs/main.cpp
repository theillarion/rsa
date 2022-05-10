#include "common.hpp"
#include <filesystem>

int main()
{
	mpz_class p;
	mpz_class q;
	std::wstring original_text;
	std::wstring encrypt_text;
	std::wstring deencrypt_text;

	p = GenerateSimpleNumber(1024);
	q = GenerateSimpleNumber(1024);

	//std::cout << "P = " << p << std::endl << "Q = " << q << std::endl;

	auto [e, d, n] = algorithms::Rsa(p, q);

	//std::cout << "E = " << e << std::endl << "D = " << d << std::endl << "N = " << n << std::endl;

	original_text = BinaryReadUtf8File("test/input.txt");

	encrypt_text = EncryptionTextMethodRsa(original_text, e, n);
	deencrypt_text = DeEncryptionTextMethodRsa(encrypt_text, d, n);

	BinaryWriteUtf8File("test/output_encrypt.txt", encrypt_text);
	BinaryWriteUtf8File("test/output_decrypt.txt", deencrypt_text);

	return (0);
}
