/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:50:40 by kkamashi          #+#    #+#             */
/*   Updated: 2021/07/24 17:30:45 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <new>
#include <iomanip>

/*
** CONSTANTS
*/

const std::string statusCreated = "created";
const std::string statusClosed = "closed";
const std::string statusRefused = "refused";
const std::string delimiter = ";";
const std::string headerIndex = "index:";
const std::string headerAmount = "amount:";
const std::string headerPreviousAmount = "p_amount:";
const std::string headerAccounts = "accounts:";
const std::string headerTotal = "total:";
const std::string headerDeposit = "deposit:";
const std::string headerDeposits = "deposits:";
const std::string headerNumberDeposits = "nb_deposits:";
const std::string headerWithdrawal = "withdrawal:";
const std::string headerWithdrawals = "withdrawals:";
const std::string headerNumberWithdrawals = "nb_withdrawals:";
const int startIndex = 0;

/*
** STATIC VARIABLES
*/

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;
static int *amounts;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << headerIndex << this->_accountIndex << delimiter << std::flush;
	std::cout << headerAmount << this->_amount << delimiter << std::flush;
	std::cout << statusCreated << std::endl;
}

Account::~Account()
{
	if (amounts == NULL)
	{
		try {
			amounts = new(std::nothrow) int[_nbAccounts + 1];
			amounts[_nbAccounts + 1] = 0;
		} catch (std::bad_alloc) {
			std::cerr << "Exception: Allocation failure occured." << std::endl;
			std::abort();
		} catch (...) {
			std::cerr << "Exception: Other error occured." << std::endl;
			std::abort();
		}
	}
	amounts[_accountIndex] = _amount;
	if (_accountIndex == startIndex)
	{
		checkAmount();
		delete[] amounts;
		amounts = NULL;
	}
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << headerAccounts << getNbAccounts() << delimiter << std::flush;
	std::cout << headerTotal << getTotalAmount() << delimiter << std::flush;
	std::cout << headerDeposits << getNbDeposits() << delimiter << std::flush;
	std::cout << headerWithdrawals << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int currentAmount = this->_amount;
	int newAmount = this->_amount + deposit;
	this->_amount = newAmount;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << headerIndex << this->_accountIndex << delimiter << std::flush;
	std::cout << headerPreviousAmount << currentAmount << delimiter << std::flush;
	std::cout << headerDeposit << deposit << delimiter << std::flush;
	std::cout << headerAmount<< this->_amount << delimiter << std::flush;
	std::cout << headerNumberDeposits << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int currentAmount = this->_amount;
	int newAmount = this->_amount - withdrawal;
	bool isSuccess = false;
	if (0 <= newAmount)
	{
		isSuccess = true;
	}
	if (isSuccess)
	{
		this->_amount = newAmount;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
	}

	_displayTimestamp();
	std::cout << headerIndex << this->_accountIndex << delimiter << std::flush;
	std::cout << headerPreviousAmount << currentAmount << delimiter << std::flush;
	std::cout << headerWithdrawal << std::flush;

	if (!isSuccess)
	{
		std::cout << statusRefused << std::endl;
		return false;
	}

	std::cout << withdrawal << delimiter <<std::flush;
	std::cout << headerAmount<< this->_amount << delimiter << std::flush;
	std::cout << headerNumberWithdrawals << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount() const
{
	for (int i = 0; i < _nbAccounts; i++)
	{
		_displayTimestamp();
		std::cout << headerIndex << i << delimiter <<std::flush;
		std::cout << headerAmount << amounts[i] << delimiter << std::flush;
		std::cout << statusClosed << std::endl;
	}
	return (0);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << headerIndex << _accountIndex << delimiter << std::flush;
	std::cout << headerAmount << _amount << delimiter << std::flush;
	std::cout << headerDeposits << _nbDeposits << delimiter << std::flush;
	std::cout << headerWithdrawals << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	std::cout << "[" << std::flush;
	// REFERENCE: std::strftime
	// https://en.cppreference.com/w/cpp/chrono/c/strftime

	// サンプル用ログの出力時刻
	// std::cout << "19920104_091532" << std::flush;

 	std::time_t result = std::time(NULL);
	char s[100];
	std::strftime(s, 100, "%Y%m%d_%H%M%S", std::localtime(&result));
	std::cout << s << std::flush;
	std::cout << "] " << std::flush;
}