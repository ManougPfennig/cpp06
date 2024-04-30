#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		std::string arg(av[1]);
		ScalarConverter::convert(arg);
	}
	else
		std::cout << "Please launch with argument." << std::endl;
	return (0);
}
