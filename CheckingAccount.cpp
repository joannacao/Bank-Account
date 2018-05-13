#include "stdafx.h"
#include "CheckingAccount.h"
#include "BankAccount.h"
#include <iostream>

using namespace std; 

CheckingAccount::CheckingAccount() : BankAccount()
{
	//stores same values as BankAccount
}

void CheckingAccount::withdraw(double d)
{
	if ((getBalance() - d) < 0) { //double checks to see if withdrawing the argument amount will bring the balance to negatives
		setServiceCharge(getServiceCharge() + 15.0); //if it does, check if the balance can handle the service charge 
		if (getServiceCharge() > getBalance()) { //if not, then the account will owe the bank money
			BankAccount::withdraw(d); 
			cout << "You owe the bank $" << getBalance() << endl; 
		}
	}
	else {
		BankAccount::withdraw(d); //if it passes the tests, money is withdrawn like normal 
	}
}

void CheckingAccount::monthlyProc()
{
	setServiceCharge(getServiceCharge() + 5.0); //$5 is added to the service charge
	double extraCharge = getNumWithdrawals()*0.10; //an extra charge is added depending on the number of withdrawals
	setServiceCharge(getServiceCharge() + extraCharge); 
	BankAccount::monthlyProc(); //calls BankAccount monthlyProc
}
