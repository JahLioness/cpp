#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T> class Array {
	private:
		T	*_theArray;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &ref);
		Array &operator=(const Array &ref);
		T &operator[](unsigned int n);
		~Array();
		unsigned int size() const;
		void	getArray() const;
} ;

#include "Array.tpp"

#endif