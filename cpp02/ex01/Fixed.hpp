#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	_raw;
		static int const _bitNb = 8;
	public:
		Fixed();
		Fixed(int const toConvert);
		Fixed(float const toConvert);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &fix);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
} ;

std::ostream &operator<<(std::ostream &os, const Fixed &fix);

#endif
