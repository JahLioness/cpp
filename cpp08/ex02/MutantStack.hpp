#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T, typename Container = std::deque<T> > class MutantStack: public std::stack<T, Container>
{
	
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		MutantStack();
		MutantStack(const MutantStack &ref);
		MutantStack &operator=(const MutantStack &ref);
		~MutantStack();
		iterator begin();
		iterator end();
		const_iterator MutantStack<T, Container>::cbegin(void);
		const_iterator MutantStack<T, Container>::cend(void);
		reverse_iterator MutantStack<T, Container>::rbegin(void);
		reverse_iterator MutantStack<T, Container>::rend(void);
		const_reverse_iterator MutantStack<T, Container>::crbegin(void) ;
		const_reverse_iterator MutantStack<T, Container>::crend(void);
} ;

#include "MutantStack.tpp"

#endif