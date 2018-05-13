#include "stdafx.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>

using namespace std; 

int main() {
	int input; //indicate what choice the user wanted
	int another = 0; //does the user want to play again?
	double inputW; //input for withdraw amount
	double inputD; //input for deposit amount
	SavingsAccount s; //creates savings account
	CheckingAccount c; //creates checking account
	do {
		cout << "Would you like to access your savings (1) or checking (2)? "; //determines which object to work in
		cin >> input;
		while ((input != 1) && (input != 2)) { //input validation
			cout << endl << "Put in a valid number: (1) savings or (2) checking: ";
			cin >> input;
		}
		cout << "Current balance is " << s.getBalance() << endl; //prints old balance
		if (input == 1) {
			cout << endl << "Would you like to deposit (1) or withdraw (2)? "; //determines whether to deposit or withdraw
			cin >> input;
			while ((input != 1) && (input != 2)) { //input validation
				cout << endl << "Put in a valid number: (1) deposit or (2) withdraw: ";
				cin >> input;
			}
			if (input == 1) {
				cout << endl << "How much would you like to deposit? "; //how much money to deposit
				cin >> inputD;
				cout << "Old balance was " << s.getBalance() << endl;  //prints old balance
				s.deposit(inputD); //makes the deposit
			}
			else {
				cout << endl << "How much would you like to withdraw? "; //how much money to withdraw
				cin >> inputW;
				cout << "Old balance was " << s.getBalance() << endl; 
				s.withdraw(inputW); //makes withdrawal
			}
			cout << "New balance is " << s.getBalance() << endl; //prints new balance 
			cout << "Number of deposits: " << s.getNumDeposits() << endl; //prints number of deposits
			cout << "Number of withdrawals: " << s.getNumWithdrawals() << endl; //prints number of withdrawals
		}
		else {
			//THIS IS FOR IF THE USER INDICATES CHECKING ACCOUNT
			cout << endl << "Would you like to deposit (1) or withdraw (2)? ";
			cin >> input;
			while ((input != 1) && (input != 2)) {
				cout << endl << "Put in a valid number: (1) deposit or (2) withdraw: ";
				cin >> input;
			}
			if (input == 1) {
				cout << "How much would you like to deposit? ";
				cin >> inputD;
				cout << "Old balance is " << c.getBalance() << endl; 
				c.deposit(inputD);
			}
			else {
				cout << "How much would you like to withdraw? ";
				cin >> inputW;
				cout << "Old balance is " << c.getBalance() << endl; 
				c.withdraw(inputW);
			}
			cout << "New balance is " << c.getBalance() << endl; 
			cout << "Number of deposits: " << c.getNumDeposits() << endl; 
			cout << "Number of withdrawals: " << c.getNumWithdrawals() << endl; 
		}
		cout << "Service charge for savings account is: " << s.getServiceCharge() << endl; 
		cout << endl << "Done? Enter 1 for yes and 0 for no: "; //asks the user if they'd like to deposit or withdraw again
		cin >> another;
		while ((another != 1) && (another != 0)) { //input validation
			cout << "Enter a valid number: "; 
			cin >> another; 
		}
		if (another == 1) {
			break; //breaks out of the loop if indicated that they dont want to go again
		}
	} while (another == 0); 
	s.monthlyProc(); //fixes balance to account for service charge and interest
	c.monthlyProc(); 
	cout << "Savings balance at the end of the month: " << s.getBalance() << endl; //prints out balance after monthlyproc
	cout << "Checking balance at the end of the month: " << c.getBalance() << endl;
	return 0; 
}
