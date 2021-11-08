#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42345678f);
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << c.toInt() << std::endl;
	std::cout << 42 << std::endl;
	return 0;
}