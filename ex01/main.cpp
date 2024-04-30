#include "Serializer.hpp"
#include "Data.hpp"

int	main( void )
{
	Data *lol = new Data;
	lol->i = 42;
	lol->str = "hello";
	std::cout << "struct adresse's: " << lol << " and contains '" << lol->i << "' '" << lol->str << "'" << std::endl;

	uintptr_t ser = Serializer::serialize(lol);
	std::cout << "serialized adress: " << ser << std::endl;

	Data *mdr = Serializer::deserialize(ser);
	std::cout << "deserialized adresse: " << mdr << " and contains '" << mdr->i << "' '" << mdr->str << "'" << std::endl;

	return (0);
}