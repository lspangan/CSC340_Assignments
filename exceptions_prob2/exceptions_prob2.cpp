/* 
 * File:   exceptions_prob2.cpp
 * Author: Leanna Pangan
 *
 * A member function that returns a special error code can also be accomplished by throwing an exception. 
 * The following class maintains an account balance, where each member function is implemented as an inline function.
 * 
 * First, use separate compilation to redistribute the information in this class into a header file (.h) and an implementation file (.cpp). 
 * Next,  modify the deposit() and withdraw() member functions such that they throw appropriate exceptions instead of returning -1 as an error code. 
 * To this end, please define the following three exception classes as derived classes of the standard exception class: 
 * (1) Exception_Negative_Deposit, corresponding to the case of depositing a negative amount of money, 
 * (2) Exception_Overdraw, corresponding to withdrawing more than the account's balance, and 
 * (3) Exception_Negative_Withdraw corresponding to withdrawing a negative amount from an account. 
 * You can place these three exception classes in one header file (both the declaration and the implementation).  
 * Finally, write test code that attempts to withdraw and deposit invalid amounts and catches the exceptions that are thrown in a try-catch statement.
 * 
 */

#include <cstdlib>
#include <iostream>
#include "exceptionsprob2.h"

using namespace std;

Account::Account():balance(0) {
    
}

Account::Account(double initialDeposit):balance( initialDeposit) {
    
}

double Account::getBalance() {
        
    return balance;
}

// returns new balance or throws error message
double Account::deposit(double amount) {

    if (amount > 0)
        balance += amount;
    else
        throw Exception_Negative_Deposit(); // code indicating error

    return balance;
}

// returns new balance or throws error message if invalid amount
double Account::withdraw(double amount) {

    if(amount > balance)
        throw Exception_Overdraw();
    else if (amount < 0)
        throw Exception_Negative_Withdraw();
    else
        balance -= amount;

    return balance;
}

// test code to check whether program runs smoothly
int main() {
    Account myBalance;
    double deposit = 50;
    myBalance.deposit(deposit); // sets the balance = $50.00
    
    // exception class is thrown b/c deposit cannot be negative
    try {
        double myMoney = -1;
        cout << "Your current balance is: $" << myBalance.getBalance() << ".00" << endl;
        cout << "Amount requested to deposit: $" << myMoney << ".00" << endl;        
        myBalance.deposit(myMoney);  
    } catch (Exception_Negative_Deposit &e) {
        cout << "Error has occurred." << endl;
        cout << e.what() << endl;
    }    
    
    // exception class is thrown b/c the withdrawal amount exceeds the balance
    try {
        double getMoney = 100000000000;
        cout << "Your current balance is: $" << myBalance.getBalance() << ".00" << endl; 
        cout << "Amount requested to withdraw: $" << getMoney << ".00" << endl;        
        cout << myBalance.withdraw(getMoney)<< endl;
    } catch (Exception_Overdraw &e) {
        cout << "Error has occurred." << endl;
        cout << e.what() << endl;
    }
    
    // exception class is thrown b/c withdrawal amount cannot be negative
    try {
        double getMoney2 = -100;
        cout << "Your current balance is: $" << myBalance.getBalance() << ".00" << endl;
        cout << "Amount requested to withdraw: $" << getMoney2 << ".00" << endl;        
        cout << myBalance.withdraw(getMoney2)<< endl;
    } catch (Exception_Negative_Withdraw &e) {
        cout << "Error has occurred." << endl;
        cout << e.what() << endl;        
    }
    return 0;
}