#include <iostream>
#include "CheckingAccount.h"
using namespace std;

// Implementation file for Checking Account class

// This function will return the checking account balance
float CheckingAccount::getBalance() const {
	return balance;
}

// the deposit method will increase checking balance by user's input
void CheckingAccount::deposit(float amount) {
	balance = balance + amount;
}

// the withdraw method will decrease balance by the user's input
// however, it will not decrease amount if withdraw amount exceeds balance
void CheckingAccount::withdraw(float amount) {
	if (amount > balance)
		cout << "You cannot withdraw an amount greater than the balance. No changes were done to the balance." << endl;
	else
		balance = balance - amount;
}

// constructor to initialize balance of checking account
CheckingAccount::CheckingAccount(float amount) {
	balance = amount;
}