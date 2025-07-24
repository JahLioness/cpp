#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<unsigned int> vec, std::deque<unsigned int> deq): _vec(vec), _deq(deq) {
	process();
}

PmergeMe::PmergeMe(const PmergeMe &ref){
	*this = ref;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &ref){
	if (this != &ref){
		_vec.clear();
		_deq.clear();
		_vec = ref._vec;
		_deq = ref._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {
	_vec.clear();
	_deq.clear();
}

void	printContent(std::vector<unsigned int> vec)
{
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	printTimeVec(clock_t start, clock_t end, size_t vecSize)
{
	double time = static_cast<double>(1e6 * (end - start) / CLOCKS_PER_SEC); // fait un static cast au pire
	std::cout << "Time to process a range of " << vecSize << " with std::vector : " << time << " us" <<std::endl;
}

void	printTimeDeq(clock_t start, clock_t end, size_t vecSize)
{
	double time = static_cast<double>(1e6 * (end - start) / CLOCKS_PER_SEC); // fait un static cast au pire
	std::cout << "Time to process a range of " << vecSize << " with std::deque : " << time << " us" <<std::endl;
}

void	PmergeMe::process(void) {

	std::cout << "Before : ";
	printContent(this->_vec);
	std::clock_t start = clock();
	sortVec(this->_vec);
	std::clock_t end = clock();
	std::cout << "After : ";
	printContent(this->_vec);
	printTimeVec(start, end, this->_vec.size());

	start = clock();
	sortDeq(this->_deq);
	end = clock();
	printTimeDeq(start, end, this->_deq.size());
}

std::vector<unsigned int> PmergeMe::jacobI(size_t pendSize) {
	std::vector<unsigned int> jacob;
	std::vector<bool> check(pendSize, false);
	unsigned int i = 1;
	unsigned int j = 0;
	while (i < pendSize)
	{
		if (!check[i])
		{
			jacob.push_back(i);
			check[i] = true;
		}
		unsigned int next = i + 2 * j;
		j = i;
		i = next;
	}
	for (unsigned int k = 0; k < pendSize; ++k)
	{
		if (!check[k])
			jacob.push_back(k);
	}
	return (jacob);
}

void PmergeMe::sortVec(std::vector<unsigned int> &tab) {
	if (tab.size() < 2)
		return;

	std::vector<unsigned int> main;
	std::vector<unsigned int> pending;
	bool Odd = tab.size() % 2 != 0;
	int bolosse = -1;
	
	if (Odd)
	{
		bolosse = tab.back();
		tab.pop_back();
	}
	size_t tabSize = tab.size();
	// for (std::vector<unsigned int>::iterator it = tab.begin(); it != tab.end(); it+=2)
	for (unsigned int i = 0; i < tabSize; i+=2)
	{
		unsigned int a = tab[i];
		unsigned int b = tab[i + 1];
		main.push_back(std::max(a,b));
		pending.push_back(std::min(a,b));
	}
	
	sortVec(main);

	if (Odd)
		pending.push_back(bolosse);
	
	std::vector<unsigned int> jacobIdx = jacobI(pending.size());

	for(unsigned int i = 0; i < jacobIdx.size(); ++i)
	{
		unsigned int idx = jacobIdx[i];
		std::vector<unsigned int>::iterator pos = std::lower_bound(main.begin(), main.end(), pending[idx]);
	 	main.insert(pos, pending[idx]);
	}
	
	tab = main;
}

 void PmergeMe::sortDeq(std::deque<unsigned int> &tab) {
	if (tab.size() < 2)
		return;

	std::deque<unsigned int> main;
	std::deque<unsigned int> pending;
	bool Odd = tab.size() % 2;
	int bolosse = -1;
	
	if (Odd)
	{
		bolosse = tab.back();
		tab.pop_back();
	}
	unsigned int tabSize = tab.size();
	for (unsigned int i = 0; i < tabSize; i+=2)
	{
		unsigned int a = tab[i];
		unsigned int b = tab[i + 1];
		main.push_back(std::max(a,b));
		pending.push_back(std::min(a,b));
	}
	
	sortDeq(main);

	if (Odd)
		pending.push_back(bolosse);
	
	std::vector<unsigned int> jacobIdx = jacobI(pending.size());

	for(unsigned int i = 0; i < jacobIdx.size(); ++i)
	{
		unsigned int idx = jacobIdx[i];
		std::deque<unsigned int>::iterator pos = std::lower_bound(main.begin(), main.end(), pending[idx]);
	 	main.insert(pos, pending[idx]);
	}
	
	tab = main;
 }