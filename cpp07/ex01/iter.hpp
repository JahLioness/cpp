#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T,typename T1, typename F> void iter(T *adress, T1 length, F f) {
	for (T1 i = 0; i < length; i++) {
		f(adress[i]);
	}
}

template <typename F> void print(F val) {
	std::cout << val << std::endl;
}

#endif