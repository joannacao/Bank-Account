#include "stdafx.h"
#include "SavingsAccount.h"
#include "BankAccount.h"

SavingsAccount::SavingsAccount() : BankAccount()
{
	status = false; //makes savings account inactive then calls BankAccount
}

//setters and getters
void SavingsAccount::setStatus(bool s)
{
	status = s; 
}

bool SavingsAccount::getStatus()
{
	return status;
}

void SavingsAccount::deposit(double d)
{
	if (status) { //if the account is active, deposit like normal
		BankAccount::deposit(d); 
	}
	else {
		if ((getBalance() + d) > 25) { //if not, check if the balance + deposit will be more than 25
			status = true; //if it is, then make the status active and then deposit like normal
			BankAccount::deposit(d); 
		}
	}
}

void SavingsAccount::withdraw(double d)
{
	if (status) { //only withdraws if the account is active
		BankAccount::withdraw(d); 
	}
}

void SavingsAccount::monthlyProc()
{
	if (getNumWithdrawals() > 4) { 
		setServiceCharge(getNumWithdrawals() - 4); //a dollar for every withdrawal past 4 is added to service charge
	}
	BankAccount::monthlyProc(); //calls normal func
	if (getBalance() < 25) { //if the balance is less than 25, makes the status inactive again
		status = false; 
	}
}
