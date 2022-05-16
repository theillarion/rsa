#include "common.hpp"

int main(int argc, char **argv)
{
	unsigned int 	bit;
	mpz_class		p;
	mpz_class		q;
	mpz_class		e;
	mpz_class		d;
	mpz_class		n;
	std::string		path_to_filename;
	std::wstring	original_text;
	std::wstring	encrypted_text;
	std::wstring	decrypted_text;

	std::chrono::steady_clock::time_point	timer_start;
	std::chrono::steady_clock::time_point	timer_end;

	if (argc == 3)
	{
		bool	is_fail = false;
		int		current = 0;

		current = from_string<int>(std::string(argv[1]), is_fail);
		if (is_fail || current <= 0)
		{
			std::cerr << "\033[91mError: wrong numeric argument" << std::endl;
			return (EXIT_FAILURE);
		}
		else
		{
			bit = current;
		}
		path_to_filename = std::string(argv[2]);
	}
	else
	{
		std::cerr << "\033[91mError: wrong number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		timer_start = std::chrono::steady_clock::now();

		original_text = BinaryReadUtf8File(path_to_filename);

		std::thread calc_p(thread_calc_big_number, std::ref(p), bit);
		std::thread calc_q(thread_calc_big_number, std::ref(q), bit);

		calc_p.join();
		calc_q.join();

		std::tie(e, d, n) = algorithms::Rsa(p, q);

		encrypted_text = EncryptionTextMethodRsa(original_text, e, n);
		decrypted_text = DeEncryptionTextMethodRsa(encrypted_text, d, n);

		BinaryWriteUtf8File("encrypted_file.txt", encrypted_text);
		BinaryWriteUtf8File("decrypted_file.txt", decrypted_text);

		timer_end = std::chrono::steady_clock::now();

		if (original_text == decrypted_text)
			std::cout	<< "\033[92mCompleted\033[0m" << std::endl
						<< "Time:          " << std::chrono::duration<double>(timer_end - timer_start).count() << std::endl
						<< "Count symbols: " << original_text.length() << std::endl
						<< "Count bits:    " << bit << std::endl;
		else
			std::cerr << "\033[91mError: original text and decoded text do not match\033[0m" << std::endl;
	}
	catch(const std::exception& exp)
	{
		std::cerr << "\033[91m" << "Exception: " << "\033[0m" << exp.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
