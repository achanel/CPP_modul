#include <iostream>
#include <iomanip>
#include <chrono>
#include "Account.hpp"

int     Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int     Account::_totalNbDeposits = 0;
int     Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << initial_deposit;
    std::cout << ";created" << std::endl;
}

Account::Account()
{
    _accountIndex = _nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:0;created" << std::endl;
}

Account::~Account()
{
    Account::_displayTimestamp();
    _nbAccounts--;
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closet" << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::chrono::time_point<std::chrono::system_clock> cur_time = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(cur_time);

    tm utc_tm = *localtime(&now_time);
    std::cout << std::setfill('0') << "[" << (utc_tm.tm_year + 1900)
        << std::setw(2) << utc_tm.tm_mon
        << std::setw(2) << utc_tm.tm_mday << "_"
        << std::setw(2) << utc_tm.tm_hour
        << std::setw(2) << utc_tm.tm_min
        << std::setw(2) << utc_tm.tm_sec << "] ";
}

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
   return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts;
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << "p_amount:" << _amount;
    if (_amount - withdrawal >= 0)
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal;
        std::cout << ";amount:" << _amount;
        std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
    else
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }


}

int		Account::checkAmount( void ) const
{
    return (_amount > 0);
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals" << _nbWithdrawals << std::endl;

}
