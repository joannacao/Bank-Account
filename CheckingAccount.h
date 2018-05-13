#pragma once
#include "stdafx.h"
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:
	CheckingAccount(); 
	void withdraw(double); //only changed withdraw function and monthlyProc function
	void monthlyProc(); 
};
