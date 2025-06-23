#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr) {
	uintptr_t ret;
	if (!ptr)
		throw std::runtime_error("Cannot cast null");
	ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data	*Serializer::deserialize(uintptr_t raw) {
	Data * ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}