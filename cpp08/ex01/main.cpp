#include "Span.hpp"

/* ADD TEST WITH 10 000 VAL */

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Tab values : " << std::endl;
	std::vector<int> tab = sp.getTab();
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	/*--------- TRY ADDING VAL WHEN AT FULL CAPACITY ----------*/
	try
	{
		sp.addNumber(60);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "shortest span : ";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "longest span : " ;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	/*--------- TRY SHORTESTSPAN WITH EMPTY TAB ----------*/
	Span noValue = Span(0);
	try
	{
		std::cout << noValue.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	Span sp2 = Span(10);
	std::vector<int> toAdd (5, 100);
	std::vector<int> toAdd2(5, 200);
	std::vector<int> canTAdd(2, 20);
	sp2.addNumber(toAdd);
	sp2.addNumber(toAdd2);
	/*--------- TRY ADDING VAL WHEN AT FULL CAPACITY ----------*/
	try
	{
		sp2.addNumber(canTAdd);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::vector<int> tab1 = sp2.getTab();
	std::cout << "Tab values : " << std::endl;
	for (std::vector<int>::iterator it = tab1.begin(); it != tab1.end(); it++)
		std::cout << *it << std::endl;
	return 0;
}
