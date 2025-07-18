#pragma once

# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <iomanip>

class RPN {
	public:
		std::stack<double> list;
		RPN();
		RPN(const RPN &ref);
		RPN &operator=(const RPN &ref);
		~RPN();
} ;