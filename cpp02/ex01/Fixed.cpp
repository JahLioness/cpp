#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const toConvert)
{
	std::cout << "Int constructor called" << std::endl;
	this->raw = toConvert << this->bitNb;
}

Fixed::Fixed(float const toConvert)
{
	std::cout << "Float constructor called" << std ::endl;
	this->raw = roundf(toConvert * (1 << this->bitNb));
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fix)
		this->raw = fix.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fix)
{
	return (os << fix.toFloat());
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->raw / (1 << this->bitNb));
}

int Fixed::toInt(void) const
{
	return (roundf(this->raw >> this->bitNb));
}
