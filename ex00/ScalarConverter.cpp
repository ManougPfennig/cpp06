#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){

	// std::cout << "ScalarConverter constructed"
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &sc){

	// std::cout << "ScalarConverter constructed"
	return ;
}

ScalarConverter::~ScalarConverter( void ){

	// std::cout << "ScalarConverter destructed"
	return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc){

	// std::cout << "ScalarConverter copied"
	return (*this);
}

bool	isChar(const std::string &literal){

	if (literal.length() == 1 && isprint(literal[0]))
		return (true);
	return (false);
}

bool	isInt(const std::string &literal){

	int	i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return (false);
	while (i < literal.length())
	{
		if (!isdigit(literal[i]))
			return (false);
		i++;
	}
	if (atoll(literal.c_str()) > INT_MAX || atoll(literal.c_str()) < INT_MIN)
		return (false);
	return (true);
}

bool	isFloat(const std::string &literal){

	int	i = 0;
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (i < literal.length() && isdigit(literal[i]))
		i++;
	if (literal[i] != '.')
		return (false);
	i++;
	while (i < literal.length() && isdigit(literal[i]))
		i++;
	if (literal[i] != 'f')
		return (false);
	i++;
	if (i != literal.length())
		return (false);
	if (atof(literal.c_str()) > FLT_MAX || atof(literal.c_str()) < -FLT_MAX)
		return (false);
	return (true);
}

bool	isDouble(const std::string &literal){

	int	i = 0;
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (i < literal.length() && isdigit(literal[i]))
		i++;
	if (literal[i] != '.')
		return (false);
	i++;
	if (i == literal.length())
		return (false);
	while (i < literal.length() && isdigit(literal[i]))
		i++;
	if (i != literal.length())
		return (false);
	if (atof(literal.c_str()) > LDBL_MAX || atof(literal.c_str()) < -LDBL_MAX)
		return (false);
	return (true);
}

char	convertToChar(const std::string &literal){

	if (findType(literal) == CHAR)
		return (literal[0]);
	double temp = atof(literal.c_str());
	if (temp > CHAR_MAX || temp < CHAR_MIN)
		throw (ScalarConverter::ImpossibleConversionException());
	char c = static_cast<char>(temp);
	if (std::isprint(c))
		return (c);
	else
		throw(ScalarConverter::NonDisplayableException());
}

int		convertToInt(const std::string &literal){

	if (literal == "-inff" || literal == "-inf")
		throw (ScalarConverter::ImpossibleConversionException());
	if (literal == "+inff" || literal == "+inf")
		throw (ScalarConverter::ImpossibleConversionException());
	if (findType(literal) == CHAR)
		return (static_cast<int>(literal[0]));
	double temp = atof(literal.c_str());
	if (temp > INT_MAX || temp < INT_MIN)
		throw (ScalarConverter::NonDisplayableException());
	return (static_cast<int>(atoi(literal.c_str())));
}

float	convertToFloat(const std::string &literal){

	if (literal == "-inff" || literal == "-inf")
		return (-FLT_MAX * 2);
	if (literal == "+inff" || literal == "+inf")
		return (FLT_MAX * 2);
	if (findType(literal) == CHAR)
		return (static_cast<float>(literal[0]));
	double temp = atof(literal.c_str());
	if (temp > FLT_MAX || temp < -FLT_MAX)
		throw (ScalarConverter::NonDisplayableException());
	return (static_cast<float>(atof(literal.c_str())));
}

double	convertToDouble(const std::string &literal){

	if (literal == "-inff" || literal == "-inf")
		return (-DBL_MAX * 2);
	if (literal == "+inff" || literal == "+inf")
		return (DBL_MAX * 2);
	if (findType(literal) == CHAR)
		return (static_cast<double>(literal[0]));
	long double temp = atof(literal.c_str());
	if (temp > FLT_MAX || temp < -FLT_MAX)
		throw (ScalarConverter::NonDisplayableException());
	return (static_cast<double>(atof(literal.c_str())));
}

const std::string	convertType(int type)
{
	switch (type)
	{
		case CHAR:
			return ("CHAR");
		case INT:
			return ("INT");
		case FLOAT:
			return ("FLOAT");
		case DOUBLE:
			return ("DOUBLE");
	}
	return ("NONE");
}

const int findType(const std::string &literal)
{
	if (isInt(literal))
		return (INT);
	else if (isFloat(literal))
		return (FLOAT);
	else if (isDouble(literal))
		return (DOUBLE);
	else if (isChar(literal))
		return (CHAR);
	throw (ScalarConverter::UnvalidEntryException());
}
