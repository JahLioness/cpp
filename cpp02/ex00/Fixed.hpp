#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int _raw;
		static int const _bitNb = 8;

	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &fix);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
