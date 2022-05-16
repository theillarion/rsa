#include "utilities.hpp"

template <typename Type> Type from_string(const std::string	&src, bool &is_failed)
{
	std::istringstream	stream(src);
	Type				result;
	stream >> result;
	if (!stream.fail() && stream)
		is_failed = false;
	else
		is_failed = true;
	return (result);
}
