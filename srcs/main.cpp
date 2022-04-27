#include "common.hpp"

int main()
{
	mpz_class p;
	mpz_class q;
	std::string original_text;
	std::string encrypt_text;
	std::string deencrypt_text;

	p = 3557;
	q = 2579;
	auto [e, d, n] = algorithms::Rsa(p, q);

	original_text = ReadFullFileBinary("test/input.txt");

	encrypt_text = EncryptionTextMethodRsa(original_text, e, n);
	deencrypt_text = DeEncryptionTextMethodRsa(encrypt_text, d, n);

	WriteFileBinary("test/output_encrypt.txt", encrypt_text);
	WriteFileBinary("test/output_decrypt.txt", deencrypt_text);

	return (0);
}
