#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	std::stringstream ss;

	ss << this->_accountIndex++;
	std::cout << "Account" + ss.str() + " has been created" << std::endl;
}

Account::Account(int initial_deposit)
{
	std::stringstream ss;

	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;
	_displayTimestamp();
	ss << this->_accountIndex;
	std::cout << " index:" + ss.str() + ";amount:";
	ss.str("");
	ss << this->_amount;
	std::cout << ss.str() + ";created" << std::endl;
	ss.str("");
}

Account::~Account(void)
{
	std::stringstream ss;

	_displayTimestamp();
	ss << this->_accountIndex;
	std::cout << " index" + ss.str() + ";amount:";
	ss.str("");
	ss << this->_amount;
	std::cout << ss.str() + ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	std::stringstream ss;

	_displayTimestamp();
	ss << this->_accountIndex;
	std::cout << " index:" + ss.str() + ";p_amount:";
	ss.str("");
	ss << this->_amount;
	std::cout << ss.str() + ";deposit:";
	ss.str("");
	ss << deposit;
	std::cout << ss.str() + ";amount:";
	ss.str("");
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	ss << this->_amount;
	std::cout << ss.str() + ";nb_deposits:";
	ss.str("");
	ss << this->_nbDeposits;
	std::cout << ss.str() << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	std::stringstream ss;

	_displayTimestamp();
	ss << this->_accountIndex;
	std::cout << " index:" + ss.str() + ";p_amount:";
	ss.str("");
	ss << this->_amount;
	std::cout << ss.str() + ";whitdrawal:";
	ss.str("");
	if (this->_amount - withdrawal >= 0)
	{
		ss << withdrawal;
		std::cout << ss.str() + ";amount:";
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		ss.str("");
		ss << this->_amount;
		std::cout << ss.str() + ";nb_withdrawals:";
		ss.str("");
		ss << this->_nbWithdrawals;
		std::cout << ss.str() << std::endl;
		return (1);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

std::string generateTimestamp(void)
{
	char	*value;

	std::time_t t = std::time(NULL);
	std::tm *now = std::localtime(&t);
	value = ctime(&t);
	std::strftime(value, 80, "%Y%m%d_%H%M%S", now);
	return (value);
}

void Account::_displayTimestamp(void)
{
	std::string timestamp;

	timestamp = generateTimestamp();
	std::cout << "[" + timestamp + ']' << std::ends;
}

void Account::displayAccountsInfos(void)
{
	std::stringstream ss;

	_displayTimestamp();
	ss << _nbAccounts;
	std::cout << " accounts:" + ss.str() + ";total:";
	ss.str("");
	ss << _totalAmount;
	std::cout << ss.str() + ";deposits:";
	ss.str("");
	ss << _totalNbDeposits;
	std::cout << ss.str() + ";withdrawals:";
	ss.str("");
	ss << _totalNbWithdrawals;
	std::cout << ss.str() << std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
void Account::displayStatus(void) const
{
	std::stringstream ss;

	_displayTimestamp();
	ss << this->_accountIndex;
	std::cout << " index:" + ss.str() + ";amount:";
	ss.str("");
	ss << this->_amount;
	std::cout << ss.str() + ";deposits:";
	ss.str("");
	ss << this->_nbDeposits;
	std::cout << ss.str() + ";withdrawals:";
	ss.str("");
	ss << this->_nbWithdrawals;
	std::cout << ss.str() << std::endl;
}
