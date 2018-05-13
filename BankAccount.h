#pragma once
#include "stdafx.h"

class BankAccount {
private:
	double balance; 
	int numDeposits; 
	int numWithdrawals; 
	double annualInterest;
	double serviceCharge; 

public:
	BankAccount(); 

	void setBalance(double); 
	double getBalance(); 

	void setNumDeposits(int); 
	int getNumDeposits(); 

	void setNumWithdrawals(int); 
	int getNumWithdrawals(); 

	void setAnnualInterest(double); 
	double getAnnualInterest();

	void setServiceCharge(double); 
	double getServiceCharge(); 

	virtual void deposit(double); 
	virtual void withdraw(double); 
	virtual void calcInt(); 
	virtual void monthlyProc(); 
};
