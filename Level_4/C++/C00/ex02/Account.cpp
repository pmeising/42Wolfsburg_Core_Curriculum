/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:41:27 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/23 18:20:42 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"
#include "ctime"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_amount = initial_deposit;
	_accountIndex = Account::getNbAccounts();
	_nbAccounts++;
	_totalAmount = _totalAmount + initial_deposit;
	std::cout 
	<< "index:" << Account::_accountIndex
	<< ";amount:" << Account::_amount
	<< ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout 
	<< "index:" << Account::_accountIndex
	<< ";amount:" << Account::_amount
	<< ";closed";
	if (_accountIndex != 7)
		std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	previous_amount = _amount;
	
	if (deposit < 0)
		return;
	_amount = _amount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount = _totalAmount + deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << previous_amount
	<< ";deposit:" << deposit
	<< ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits << std::endl;
	// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	previous_amount = _amount;

	_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << previous_amount
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount = _amount - withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount = _totalAmount - withdrawal;
	std::cout
	<< "index:" << _accountIndex
	<< ";p_amount:" << previous_amount
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << _amount
	<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
	// index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
}

int	Account::checkAmount(void) const
{
	return(_amount);
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
	
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return(_totalNbDeposits);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
	<< "index:" << Account::_accountIndex
	<< ";amount:" << Account::_amount
	<< ";deposits:" << Account::_nbDeposits
	<< ";withdrawals:" << Account::_nbWithdrawals << std::endl;
	// index:0;amount:42;deposits:0;withdrawals:0
}

// Link: https://cplusplus.com/reference/ctime/strftime/
void	Account::_displayTimestamp( void )
{
	std::string	time;
	std::time_t	timer;
	char		result[100];

	timer = std::time(NULL);
	std::strftime(result, sizeof(result), "%Y%m%d_%H%M%S", std::localtime(&timer));
	std::cout << "[" << result << "] ";
}
