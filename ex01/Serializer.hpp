#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include <cstdint>
# include "Data.hpp"

class Serializer
{
	private:

	public:
		// constructor | destructor | operator override
		Serializer( void );
		Serializer( const Serializer &s);
		~Serializer( void );
		Serializer &operator=(const Serializer &s);

		// member functions
		static uintptr_t	serialize(Data* ptr){
		
			return (reinterpret_cast<uintptr_t>(ptr));
		}
		static Data			*deserialize(uintptr_t raw){

			return (reinterpret_cast<Data*>(raw));
		}
};

#endif