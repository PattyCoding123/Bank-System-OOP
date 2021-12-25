#include <iostream>
#include <iomanip>
#include <sstream>
#include "BankSystem.h"
using namespace std;

void BankSystem::start() {
	// Welcome message

	cout << "\nWelcome, " << oneClient.getFirstName() << " " << oneClient.getLastName() << "!";
	cout << setw(20) << right << "ID: " << oneClient.getID();
	cout << "\n============================================";
	int userChoice; // display options to user and get their choice on what to do with their bank
	bool exit = false;
	while (exit == false) {
		cout << "\n= Menu =" << endl;
		cout << "1. Add a Checking account \n2. Remove Checking Account \n3. Deposit into Checking Account" << endl;
		cout << "4. Withdraw from a Checking Account \n5. Add a Savings account \n6. Remove Savings Account" << endl;
		cout << "7. Deposit into Savings account \n8. Transfer from Savings to Checking account \n9. Exit" << endl;
		cout << "Choose an option[1-9]: ";
		cin >> userChoice;

		// If user enters a non-integer, send error message and clear the input buffer
		// Else, use switch statement to determine the user's intention
		if (cin.fail()) {
			cout << "Error: Not a valid choice. Please Try again!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		else {
			switch (userChoice) {
			case 1:  // call AddCheckingDialogue
				AddCheckingDialogue();
				break;

			case 2: // call RemoveCheckingDialogue
				RemoveCheckingDialogue();
				break;

			case 3: // call DepositCheckingDialogue
				DepositCheckingDialogue();
				break;

			case 4: // call WithdrawCheckingDialogue
				WithdrawCheckingDialogue();
				break;

			case 5: // call AddSavingDialogue
				AddSavingDialogue();
				break;

			case 6: // call RemoveSavingDialogue
				RemoveSavingDialogue();
				break;

			case 7: // call DepositSavingDialogue
				DepositSavingDialogue();
				break;

			case 8: // call TransferDialogue
				TransferDialogue();
				break;

			case 9: // Display the log to user (starting at most recent) and then exit menu
				cout << "\nAll log messages, starting at most recent: " << endl;
				cout << "-------------------------------------------------" << endl;
				for (int i = (signed)log.size() - 1; i >= 0 ; i--) {
					cout << log[i] << endl;
				}
				exit = true;
				break;

			default:
				cout << "Error: Option is invalid. Please enter a valid option." << endl;
			}
		}
	}

	return;
}

void BankSystem::AddCheckingDialogue() {
	// if oneClient's checking pointer is NOT null, display that client already
	// has a checking account and write an invalid overwrite statement in the log
	if (oneClient.checking != nullptr) {
		cout << "\nThe client already has a checking account." << endl;
		log.push_back("Invalid attempt to overwrite a checking account.");
	}

	// if oneClient's checking pointer IS null, ask for initial balance and 
	// create a checking member dynamically and set it in checking member of the client
	else {
		float initialAmount;
		cout << "\nWhat is the initial balance of your checking account?: $";
		cin >> initialAmount;

		// Log if user enters a negative amount
		if (initialAmount < 0) {
			cout << "Error: Initial amount must be greater than 0." << endl;
			log.push_back("Invalid attempt to initialize checking account with a negative balance.");
		}
			

		else {

			// creating new checking member dynamically using the oneClient's checking pointer
			oneClient.checking = new CheckingAccount(initialAmount);

			cout << fixed << setprecision(2);
			cout << "You now have $" << oneClient.checking->getBalance() << " in your checking account." << endl;

			// log that checking account was successfully created
			log.push_back("Checking account successfully created.");
		}
	}

	return;
}


void BankSystem::RemoveCheckingDialogue() {
	// if oneClient's checking pointer IS null, display that client does not have
	// a checking account to remove and write an invalid removal statement in the log
	if (oneClient.checking == nullptr) {
		cout << "\nThe client does not have a checking account." << endl;
		log.push_back("Invalid attempt to remove a non-existing checking account.");
	}

	// if oneClient's checking pointer is NOT null, remove checking account from memory
	// and set oneClient.checking to null
	else {
		delete oneClient.checking;
		oneClient.checking = nullptr;

		// log that checking account was successfully removed
		log.push_back("Checking account successfully removed.");
	}

	return;
}

void BankSystem::DepositCheckingDialogue() {
	// if oneClient's checking pointer IS null, display that client does not have a
	// checking account and log an invalid deposit attempt to checking
	if (oneClient.checking == nullptr) {
		cout << "\nThe client does not have a checking account." << endl;
		log.push_back("Invalid attempt to deposit to a non-existing checking account.");
	}

	// if oneClient's checking pointer is NOT null, ask for deposit amount and add to checking
	else {

		float depositAmount;
		cout << "\nHow much would you like to deposit?: $";
		cin >> depositAmount;

		// Log if user enters a negative amount
		if (depositAmount < 0) {
			cout << "Error: Deposit amount must be greater than 0." << endl;
			log.push_back("Invalid attempt to deposit a negative amount to checking account.");
		}
			
		else {
			oneClient.checking->deposit(depositAmount);

			cout << fixed << setprecision(2);
			cout << "You have $" << oneClient.checking->getBalance() << " in your checking account." << endl;

			// log that deposit was successful
			// stringstream will add the deposit amount to userAmount variable, then we will concantenate
			// the addAmount.str along with the rest of the statement then store it in vector
			stringstream userAmount;
			userAmount << depositAmount;
			log.push_back("$" + userAmount.str() + " successfully deposited in checking account.");
		}
	}

	return;
}

void BankSystem::WithdrawCheckingDialogue() {
	// if oneClient's checking pointer IS null, display that client does not have a
	// checking account and log that
	if (oneClient.checking == nullptr) {
		cout << "\nThe client does not have a checking account." << endl;
		log.push_back("Invalid attempt to withdraw from a non-existing checking account.");
	}

	// if oneClient's checking pointer is NOT null, ask for withdraw amount and subtract
	// it from checking balance. 
	else {
		float withdrawAmount;
		cout << "\nHow much would you like to withdraw?: $";
		cin >> withdrawAmount;

		if (withdrawAmount < 0) {
			cout << "Error: Withdraw amount must be greater than 0" << endl;
			log.push_back("Invalid attempt to withdraw a negative amount from checking.");
		}
			
		
		else {
			float oldCheckingBalance = oneClient.checking->getBalance();
			oneClient.checking->withdraw(withdrawAmount);

			cout << fixed << setprecision(2);
			cout << "You have $" << oneClient.checking->getBalance() << " in your checking account." << endl;

			// If there was a successful withdrawal from checkings:
			// stringstream will add the withdraw amount to userAmount variable, then we will concantenate
			// the addAmount.str along with the rest of the statement then store it in vector
			if (oneClient.checking->getBalance() != oldCheckingBalance) {
				stringstream userAmount;
				userAmount << withdrawAmount;
				log.push_back("$" + userAmount.str() + " successfully withdrawn from checking account.");
			}

			// Else, log invalid withdrawal due to insufficient funds from checking account
			else
				log.push_back("Error: Insufficient checking account balance to complete withdrawal.");
		}
	}

	return;
}

void BankSystem::AddSavingDialogue() {
	// if oneClient's savings pointer is NOT null, display that client already
	// has a saving account and write an invalid overwrite statement in the log
	if (oneClient.saving != nullptr) {
		cout << "\nThe client already has a savings account." << endl;
		log.push_back("Invalid attempt to overwrite a savings account.");
	}

	// if oneClient's saving pointer IS null, ask for initial balance and 
	// create a savings member dynamically and set it in savings member of the client
	else {
		float initialAmount, newRate;
		cout << "\nWhat is the initial balance of your savings account?: $";
		cin >> initialAmount;

		cout << "What is the saving rate of your savings account?: ";
		cin >> newRate;

		// Check if initial balance or savings rate is less than 0
		if (initialAmount < 0 || newRate < 0) {
			cout << "Error: Initial amount and saving rate must be greater than 0." << endl;
			log.push_back("Invalid attempt to initialize a savings account with a negative amount or saving rate.");
		}
			
		
		// creating new savings member dynamically with the oneClient's savings pointer
		else {
			oneClient.saving = new SavingAccount(initialAmount, newRate);

			cout << fixed << setprecision(2);
			cout << "\nYou now have $" << oneClient.saving->getBalance() << " in your savings account ";
			cout << "with an account rate of " << oneClient.saving->getSavingRate() << "%." << endl;

			// log that savings account was successfully created
			log.push_back("Savings account successfully created.");
		}	
	}

	return;
}

void BankSystem::RemoveSavingDialogue() {
	// if oneClient's saving pointer IS null, display that client does not have
	// a saving account to remove and write an invalid removal statement in the log
	if (oneClient.saving == nullptr) {
		cout << "\nThe client does not have a savings account." << endl;
		log.push_back("Invalid attempt to remove a non-existing savings account.");
	}

	// if oneClient's savings pointer is NOT null, remove savings account from memory
	// and set oneClient.savings to null
	else {
		delete oneClient.saving;
		oneClient.saving = nullptr;

		// log that savings account was successfully removed
		log.push_back("Savings account successfully removed.");
	}
	return;
}

void BankSystem::DepositSavingDialogue() {
	// if oneClient's savings pointer IS null, display that client does not have a
	// savings account and log an invalid deposit attempt to savings
	if (oneClient.saving == nullptr) {
		cout << "\nThe client does not have a savings account." << endl;
		log.push_back("Invalid attempt to deposit to a non-existing savings account.");
	}

	// if oneClient's saving pointer is NOT null, ask for deposit amount and add to checking
	else {
		float depositAmount;
		cout << "\nHow much would you like to deposit?: $";
		cin >> depositAmount;

		// Log if user enters a negative amount
		if (depositAmount < 0) {
			cout << "Error: Deposit amount must be greater than 0." << endl;
			log.push_back("Invalid attempt to deposit a negative amount to savings.");

		}
			

		else {
			oneClient.saving->deposit(depositAmount);

			cout << fixed << setprecision(2);
			cout << "You have $" << oneClient.saving->getBalance() << " in your savings account." << endl;

			// log that deposit was successful
			// stringstream will add the deposit amount to userAmount variable, then we will concantenate
			// the addAmount.str along with the rest of the statement then store it in vector
			stringstream userAmount;
			userAmount << depositAmount;
			log.push_back("$" + userAmount.str() + " successfully deposited in savings account.");
		}
	}

	return;
}

void BankSystem::TransferDialogue() {
	// if oneClient's savings pointer IS null, display that client does not have a
	// savings account and log an invalid attempt to use a non-existing savings account
	if (oneClient.saving == nullptr) {
		cout << "\nThe client does not have a savings account." << endl;
		log.push_back("Invalid attempt to use a non-existing savings account.");
	}

	// if oneClient's checking pointer IS null, display that client does not have a
	// checking account and log an invalid attempt to use a non-existing checking account
	else if (oneClient.checking == nullptr) {
		cout << "\nThe client does not have a checking account." << endl;
		log.push_back("Invalid attempt to use a non-existing checking account.");
	}

	// If savings and checking are NOT null, ask for the transfer amount, then
	// withdraw it from the savings and add it to checking.
	else {
		float transferAmount;
		cout << "\nHow much would you like to transfer from your savings to your checking? $";
		cin >> transferAmount;

		// Log if user enters a negative amount
		if (transferAmount < 0) {
			cout << "Error: Transfer amount must be greater than 0." << endl;
			log.push_back("Invalid attempt to transfer a negative amount from savings account to checking account.");
		}
			

		else {
			float oldSavingBalance = oneClient.saving->getBalance();
			oneClient.saving->transfer(oneClient.checking, transferAmount);

			cout << fixed << setprecision(2);
			cout << "You have $" << oneClient.saving->getBalance() << " in your savings account." << endl;
			cout << "You have $" << oneClient.checking->getBalance() << " in your checking account." << endl;

			// Log message if there was a successful transfer. 
			// stringstream will add the deposit amount to userAmount variable, then we will concantenate
			// the addAmount.str along with the rest of the statement then store it in vector
			if (oneClient.saving->getBalance() != oldSavingBalance) {
				stringstream userAmount;
				userAmount << transferAmount;
				log.push_back("$" + userAmount.str() + " successfully transferred from savings to checking account.");
			}

			// Else, log invalid transfer due to insufficient funds from savings
			else {
				log.push_back("Error: Insufficient savings account balance to complete transfer.");
			}
		}	
	}

	return;
}

// Constuctor which initializes client information
BankSystem::BankSystem(int i, string fn, string ln) : oneClient(i, fn, ln) {

}