#include <iostream>
#include <exception>

template <typename T> typename T::iterator easyfind(T &container, int val) {
	typename T::iterator end = container.end();
	for (typename T::iterator it = container.begin(); it != end; it++)
	{
		if ((*it) == val)
			return (it);
	}
	throw std::runtime_error("Value not find.");
}
