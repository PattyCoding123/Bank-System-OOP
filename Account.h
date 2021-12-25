#pragma once

// Account is an abstract class, so all of its functions will be virtual
class Account {
public:
	
	virtual float getBalance() const = 0;
	// getBalance() is a pure virtual function, must be defined
	// in all derived classes

	virtual void deposit(float amount) = 0;
	// deposit() is a pure virtual function, must be defined
	//in all derived classes

protected:
	float balance = 0;

 };