#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	raw;
		static int const bitNb = 8;
	public:
		Fixed();
		Fixed(int const toConvert);
		Fixed(float const toConvert);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &fix);
		bool operator>(const Fixed &fix) const;
		bool operator<(const Fixed &fix);
		bool operator>=(const Fixed &fix);
		bool operator<=(const Fixed &fix);
		bool operator==(const Fixed &fix);
		bool operator!=(const Fixed &fix);
		Fixed &operator+(const Fixed &fix);
		Fixed &operator-(const Fixed &fix);
		Fixed &operator*(const Fixed &fix);
		Fixed &operator/(const Fixed &fix);
		Fixed &operator++(int);
		Fixed &operator--(int);
		Fixed &operator++(void);
		Fixed &operator--(void);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
} ;

std::ostream &operator<<(std::ostream &os, const Fixed &fix);

#endif
