#include "Fixed.hpp"

Fixed::Fixed() : _num(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int Num)
{
	// std::cout << "Int constructor called" << std::endl;

	this->_num = Num * (1 << this->_fractionalBits);
}

Fixed::Fixed(const float Num)
{
	// std::cout << "Float constructor called" << std::endl;

	this->_num = roundf(Num * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &fixed)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_num = fixed._num;
	return *this;
}

float Fixed::toFloat(void) const
{
	return (float)this->_num / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
	return ((float)this->_num / (1 << this->_fractionalBits));
}

std::ostream &operator << (std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator >(const Fixed& rightObj) const
{
	return this->_num > rightObj.getNum();
}

bool Fixed::operator<(const Fixed& rightObj) const
{
	return this->_num < rightObj.getNum();
}

bool Fixed::operator>=(const Fixed& rightObj) const
{
	return this->_num >= rightObj.getNum();
}

bool Fixed::operator<=(const Fixed& rightObj) const
{
	return this->_num <= rightObj.getNum();
}

bool Fixed::operator==(const Fixed& rightObj) const
{
	return this->_num == rightObj.getNum();
}

bool Fixed::operator!=(const Fixed& rightObj) const
{
	return this->_num != rightObj.getNum();
}

		// arithmetic operators overload:
Fixed Fixed::operator+(const Fixed& rightObj)
{
	Fixed resObj;
	resObj.setNum(this->_num + rightObj.getNum());
	return resObj;
}

Fixed Fixed::operator-(const Fixed& rightObj)
{
	Fixed resObj;
	resObj.setNum(this->_num - rightObj.getNum());
	return resObj;
}

Fixed Fixed::operator*(const Fixed& rightObj)
{
	Fixed resObj;
	long long tmp;
	tmp = (long long)(this->_num) * (long long)(rightObj.getNum());
	resObj.setNum(static_cast<int>((tmp / static_cast<long long>(1 << this->_fractionalBits))));
	return resObj;
}

Fixed Fixed::operator/(const Fixed& rightObj)
{
	Fixed resObj;
	if (rightObj.getNum() == 0) {
		std::cerr << "Error! Division by zero" << std::endl;
		return *this;
	} else {
		long long tmp;
		tmp = static_cast<long long>(this->_num) * static_cast<long long>(1 << this->_fractionalBits);
		resObj.setNum(static_cast<int>(tmp / static_cast<long long>(rightObj.getNum())));
	}
	return resObj;
}

Fixed& Fixed::operator++()
{
	++this->_num;
	return *this;
}

Fixed& Fixed::operator--()
{
	--this->_num;
	return *this;
}

const Fixed Fixed::operator++(int)
{
	Fixed resObj(*this);
	++this->_num;
	return resObj;
}

const Fixed Fixed::operator--(int)
{
	Fixed resObj(*this);
	--this->_num;
	return resObj;
}

Fixed& Fixed::min(Fixed& leftObj, Fixed& rightObj)
{
	if (leftObj < rightObj)
		return leftObj;
	else
		return rightObj;
}

const Fixed& Fixed::min(const Fixed& leftObj, const Fixed& rightObj)
{
	if (leftObj < rightObj)
		return leftObj;
	else
		return rightObj;
}

Fixed& Fixed::max(Fixed& leftObj, Fixed& rightObj)
{
	if (leftObj > rightObj)
		return leftObj;
	else
		return rightObj;
}

const Fixed& Fixed::max(const Fixed& leftObj, const Fixed& rightObj)
{
	if (leftObj > rightObj)
		return leftObj;
	else
		return rightObj;
}

int      Fixed::getNum(void) const
{
    return (this->_num);
}

void    Fixed::setNum(int const row)
{
    this->_num = row;
}
