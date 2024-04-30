#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <exception>
# include <string>
# include <ctype.h>
# include <climits>
# include <cfloat>


bool	isChar(const std::string &literal);
bool	isInt(const std::string &literal);
bool	isFloat(const std::string &literal);
bool	isDouble(const std::string &literal);
char	convertToChar(const std::string &literal);
int		convertToInt(const std::string &literal);
float	convertToFloat(const std::string &literal);
double	convertToDouble(const std::string &literal);

enum s_Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
};

const int			findType(const std::string &literal);
const std::string	convertType(int type);

class ScalarConverter {

	private:

	public:

		// Constructors | Destructor | Operator override
		ScalarConverter( void ); // default constructor
		ScalarConverter(const ScalarConverter &sc); // copy constructor
		~ScalarConverter(); // destructor
		ScalarConverter &operator=(const ScalarConverter &sc); // operation overload =

		// Member function
		static void	convert(const std::string &literal)
		{
			try
			{
				if (literal.length() == 0)
					throw(ScalarConverter::UnvalidEntryException());

				for (int i = 0; i < literal.length(); i++)
					if (!std::isprint(literal[i]))
						throw (ScalarConverter::UnvalidEntryException());

				int type = findType(literal);
				std::cout << convertType(type) << " detected" << std::endl;
				
				// convert to char
				try {std::cout << "char: ";
					char c = convertToChar(literal);
					std::cout << c << std::endl;}
				catch(const std::exception &e){std::cout << e.what() << std::endl;}
				
				// convert to int
				try {std::cout << "int: ";
					int i = convertToInt(literal);
					std::cout << i << std::endl;}
				catch(const std::exception &e){std::cout << e.what() << std::endl;}

				// convert to float
				try {std::cout << "float: ";
					float f = convertToFloat(literal);
					std::cout << f;
					if (f == static_cast<int>(f))
						std::cout << ".0";
					std::cout << "f" << std::endl;}
				catch(const std::exception &e){std::cout << e.what() << std::endl;}

				// convert to double
				try {std::cout << "double: ";
					double d = convertToDouble(literal);
					std::cout << d;
					if (d == static_cast<int>(d))
						std::cout << ".0";
						std::cout << std::endl;}
				catch(const std::exception &e){std::cout << e.what() << std::endl;}

			}
			catch (const std::exception &e)
			{
				std::cout << e.what();
			}
		}

		class UnvalidEntryException : public std::exception
		{
			const char *what() const throw()
			{
				return ("Unvalid entry\n");
			}
		};
		class ImpossibleConversionException : public std::exception
		{
			const char *what() const throw()
			{
				return ("impossible");
			}
		};
		class NonDisplayableException : public std::exception
		{
			const char *what() const throw()
			{
				return ("Non displayable");
			}
		};
};

#endif
