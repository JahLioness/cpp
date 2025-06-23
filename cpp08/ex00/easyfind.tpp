#include <iostream>
#include <exception>
#include <algorithm>

template <typename T> typename T::iterator easyfind(T &container, int val) {

	typename T::iterator ret = std::find(container.begin(), container.end(), val);
	if (ret != container.end())
		return (ret);
	throw std::runtime_error("Value not find.");
}
