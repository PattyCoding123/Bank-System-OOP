#pragma once
#include <iostream>
#include <vector>
#include "Client.h"

// The bank system class will contain a log and a client 
// It will also contain functions that will make use of 
// The client's checking and savings account
class BankSystem {
public:
	void start();
	// Displays a menu with all options that a client 
	// can do with the banking system. Choice is determined
	// by user input

	BankSystem(int i, std::string fn, std::string ln);
	// Constructor that will call the client constructor to initializes
	// oneClient's id, first name, and last name

private:
	std::vector<std::string> log;
	Client oneClient;
	void AddCheckingDialogue();
	// Precondition: User must choose option 1 in start()
	// will attempt to add a checking account to client's bank
	// and logs attempt

	void RemoveCheckingDialogue();
	// Precondition: User must choose option 2 in start()
	// will attempt to remove the client's checking account from the system
	// and logs attempt

	void DepositCheckingDialogue();
	// Precondition: User must choose option 3 in start()
	// will attempt to deposit money into client's checking account
	// and logs attempt

	void WithdrawCheckingDialogue();
	// Precondition: User must choose option 4 in start()
	// will attempt to withdraw money from client's checking account
	// and logs attempt

	void AddSavingDialogue();
	// Precondition: User must choose option 5 in start()
	// will attempt to add a savings account to client's bank 
	// and logs attempt

	void RemoveSavingDialogue();
	// Precondition: User must choose option 6 in start()
	// will attempt to remove savings account from client's bank
	// and logs attempt

	void DepositSavingDialogue();
	// Precondition: User must choose option 7 in start()
	// will attempt to deposit money into client's savings account
	// and logs attempt

	void TransferDialogue();
	// Precondition: User must choose option 8 in start()
	// will attempt to transfer money from client's savings account
	// to their checking account and logs attempt

};