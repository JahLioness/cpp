
template <typename T> Array<T>::Array(void): _theArray(NULL), _size(0){

}

template <typename T> Array<T>::Array(unsigned int n): _theArray(new T[n]), _size(n) {
	for (unsigned int i = 0; i < _size; i++)
		_theArray[i] = T();
}

template <typename T> Array<T>::Array(const Array &ref):_theArray(NULL), _size(ref._size) {
	*this = ref;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &ref) {
	if (this != &ref)
	{
		T *temp = new T[ref._size];
		for (unsigned int i = 0; i < ref._size; ++i)
			temp[i] = ref._theArray[i];
		delete[] _theArray;
		_size = ref._size;
		_theArray = temp;
	}
	return (*this);
}

template <typename T> T& Array<T>::operator[](unsigned int n) {
	if (n >= _size || !_theArray)
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