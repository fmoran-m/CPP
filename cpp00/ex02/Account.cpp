#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t	fromEpoch;
	tm		*local;

	time(&fromEpoch);
	local = localtime(&fromEpoch);
	std::cout << std::put_time(local, "[%Y%m%d_%H%M%S] ");
}

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0){

	_displayTimestamp();
	_accountIndex = _nbAccounts;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account(void){

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	_nbAccounts--;
}

int	Account::getNbAccounts(void){
	return _nbAccounts;
}

int	Account::getTotalAmount(void){
	return _totalAmount;
}

int	Account::getNbDeposits(void){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void){
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(){

	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit){

	_displayTimestamp();
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << ";" << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";";
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << ";" << std::endl;
	return true;
}

int		Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
}
