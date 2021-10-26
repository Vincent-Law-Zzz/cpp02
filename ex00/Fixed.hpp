#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int _rawBits;
        static const int _fractBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed &operator = (const Fixed& fixed);
        int     getRawBits(void) const;
        void    setRawBits(int const row);
};
#endif