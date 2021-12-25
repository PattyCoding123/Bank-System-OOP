#pragma once
#include "Account.h"

// this is a derived class from the abstract class "Account"
class CheckingAccount : public Account {
public:
	float getBalance() const;
	// returns checking account balance when called

	void deposit(float amount);
	// deposits the amount that was passed in the parameter into
	// the checking account's balance

	void withdraw(float amount);
	// will withdraw the amount that was passed in the parameter
	// from the checking account's balance if there is enough money

	CheckingAccount(float amount);
	// constructor that initializes checking account balance

};