#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int Num);
		Fixed(const float Num);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator = (const Fixed &fixed);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int	_num;
		static const int _fractionalBits = 8;
};

std::ostream &operator << (std::ostream &out, Fixed const &fixed);

#endif