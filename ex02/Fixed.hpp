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
		bool operator>(const Fixed& rightObj) const;
		bool operator<(const Fixed& rightObj) const;
		bool operator>=(const Fixed& rightObj) const;
		bool operator<=(const Fixed& rightObj) const;
		bool operator==(const Fixed& rightObj) const;
		bool operator!=(const Fixed& rightObj) const;

		// arithmetic operators overload:
		Fixed operator+(const Fixed& rightObj);
		Fixed operator-(const Fixed& rightObj);
		Fixed operator*(const Fixed& rightObj);
		Fixed operator/(const Fixed& rightObj);

		// increment & decrement operators overload:
		Fixed& operator++();
		Fixed& operator--();
		const Fixed operator++(int);
		const Fixed operator--(int);
		static Fixed& min(Fixed& leftObj, Fixed& rightObj);
		static const Fixed& min(const Fixed& leftObj, const Fixed& rightObj);
		static Fixed& max(Fixed& leftObj, Fixed& rightObj);
		static const Fixed& max(const Fixed& leftObj, const Fixed& rightObj);
		float toFloat(void) const;
		int toInt(void) const;
		int     getNum(void) const;
        void    setNum(int const row);

	private:
		int	_num;
		static const int _fractionalBits = 8;
};

std::ostream &operator << (std::ostream &out, Fixed const &fixed);

#endif