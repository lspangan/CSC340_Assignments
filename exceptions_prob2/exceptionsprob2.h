/* 
 * File:   exceptionsprob2.h
 * Author: leannapangan
 *
 * Created on October 27, 2015, 7:05 PM
 */

#ifndef EXCEPTIONSPROB2_H
#define	EXCEPTIONSPROB2_H

// this class manages an account's balance
// withdraws and deposits are available
class Account {
    private:
        double balance; 
    
    public:
        Account();
        Account(double initialDeposit);
        double getBalance();
        double deposit(double amount);
        double withdraw(double amount);
};

// exception class that is thrown if the deposit is a negative amount
class Exception_Negative_Deposit : public std::exception {
    public:
        const char *what() const throw() {
            return "Cannot deposit negative amount.";
        }    
};

// exception class that is thrown if there is not enough money in the account to withdraw
class Exception_Overdraw : public std::exception {
    public:
        const char *what() const throw() {
            return "Unable to withdraw that amount due to insufficient balance.";
        }    
};

// exception class that is thrown if the amount requested to withdraw is negative
class Exception_Negative_Withdraw : public std::exception {
    public:
        const char *what() const throw() {
            return "Cannot withdraw a negative amount.";
        }    
};



#endif	/* EXCEPTIONSPROB2_H */

