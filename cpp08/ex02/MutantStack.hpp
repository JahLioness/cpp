#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T, typename Container = std::deque<T> > class MutantStack: public std::stack<T, Container>
{
	
	public:
		typedef typename Container::iterator iterator;
		MutantStack();
		MutantStack(const MutantStack &ref);
		MutantStack &operator=(const MutantStack &ref);
		~MutantStack();
		iterator begin();
		iterator end();

		
} ;

#include "MutantStack.tpp"

#endif