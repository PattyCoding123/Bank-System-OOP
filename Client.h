#pragma once
#include <iostream>
#include <string>
#include "CheckingAccount.h"
#include "SavingAccount.h"

// Client class
class Client {
public:
	CheckingAccount* checking;
	// checking account pointer 

	SavingAccount* saving;
	// savings account pointer

	void setID(int i);
	// sets ID of the client

	int getID() const;
	// returns ID of the client

	void setName(std::string fn, std::string ln);
	// sets first and last name of the client

	std::string getFirstName() const;
	// returns first name of the client

	std::string getLastName() const;
	// returns last name of the client

	Client(int i, std::string fn, std::string ln);
	// constructor that initializes the client's id
	// first name, and last name

private:
	int id = 0;
	std::string firstName = "";
	std::string lastName = "";

};