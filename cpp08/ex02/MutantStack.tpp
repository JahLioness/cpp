#include <stack>

template <typename T, typename Container> MutantStack<T, Container>::MutantStack(void) {

}

template <typename T, typename Container> MutantStack<T, Container>::MutantStack(const MutantStack &ref): std::stack<T, Container>(ref) {

}

template <typename T, typename Container> MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &ref) {
	if (this != &ref)
		std::stack<T, Container>::operator=(ref);
	return (*this);
}

template <typename T, typename Container> MutantStack<T, Container>::~MutantStack(void) {}

template <typename T, typename Container> typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void) {
	return (this->c.begin());
}

template <typename T, typename Container> typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void) {
	return (this->c.end());
}
