#pragma once
#include "stdafx.h"
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private: 
	bool status; 

public:
	SavingsAccount(); 

	void setStatus(bool); 
	bool getStatus(); 

	void deposit(double); 
	void withdraw(double); 
	void monthlyProc(); 
};
