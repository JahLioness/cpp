#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &ref)
{
	*this = ref;
}

RPN &RPN::operator=(const RPN &ref)
{
	if (this != &ref)
	{
		while (!list.empty())
			list.pop();
		list = ref.list;
	}
	return (*this);
}

RPN::~RPN() {}


// 9 7 1 1 + - / 3 * 2 1 1 + + -