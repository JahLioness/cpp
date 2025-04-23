
template <typename T> Array<T>::Array(void): _theArray(NULL), _size(0){

}

template <typename T> Array<T>::Array(unsigned int n): _theArray(new T[n]), _size(n) {

}

template <typename T> Array<T>::Array(const Array &ref) {
	*this = ref;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &ref) {
	if (this != &ref)
	{
		delete[] _theArray;
		_size = ref._size;
		_theArray = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_theArray[i] = ref._theArray[i];
	}
	return (*this);
}

template <typename T> T& Array<T>::operator[](unsigned int n) {
	if (n >= _size)
		throw std::out_of_range("Index out of range");
	return _theArray[n];
}

template <typename T> Array<T>::~Array(void) {
	delete[] _theArray;
}

template <typename T> unsigned int Array<T>::size(void) const {
	return(_size);
}

template <typename T> void Array<T>::getArray () const {
	for (unsigned int i = 0; i < this->size(); i++ ) {
	   std::cout << _theArray[i] << std::endl;
   }
}