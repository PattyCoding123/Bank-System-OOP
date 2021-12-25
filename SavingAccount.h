#pragma once
#include "Account.h"
#include "CheckingAccount.h"

// SavingAccount is a derived class from the abstract class "Account"
class SavingAccount : public Account {
public:
	float getBalance() const;
	// returns balance of savings acccount

	void deposit(float amount);
	// deposits the amount passed in the function into 
	// the balance of the savings account

	void setSavingRate(float rate);
	// setter function for the saving account's
	// saving rate

	float getSavingRate() const;
	// returns the saving rate of the savings account

	void transfer(CheckingAccount* &checkingAcc, float amount);
	// will transfer money from savings account into checking account
	// if there is enough money in the savings account to do so

	SavingAccount(float amount, float rate);
	// constructor that initializes balance of savings account
	// and its saving rate

private:
	float SavingRate = 0;

};