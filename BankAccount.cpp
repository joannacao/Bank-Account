// BankAccount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BankAccount.h"

BankAccount::BankAccount()
{
	balance = 0.0; 
	numDeposits = 0; 
	numWithdrawals = 0; 
	annualInterest = 0.012; //everything except annual interest initialized to zero 
	serviceCharge = 0.0; 
}

//setters and getters
void BankAccount::setBalance(double b)
{
	balance = b; 
}

double BankAccount::getBalance()
{
	return balance;
}

void BankAccount::setNumDeposits(int nd)
{
	numDeposits = nd;
}

int BankAccount::getNumDeposits()
{
	return numDeposits;
}

void BankAccount::setNumWithdrawals(int nw)
{
	numWithdrawals = nw; 
}

int BankAccount::getNumWithdrawals()
{
	return numWithdrawals;
}

void BankAccount::setAnnualInterest(double ai)
{
	annualInterest = ai; 
}

double BankAccount::getAnnualInterest()
{
	return annualInterest;
}

void BankAccount::setServiceCharge(double sc)
{
	serviceCharge = sc; 
}

double BankAccount::getServiceCharge()
{
	return serviceCharge;
}

void BankAccount::deposit(double d)
{
	balance += d; //adds the argument to balance
	numDeposits++; //increments numDeposits by 1
}

void BankAccount::withdraw(double w)
{
	balance -= w; //subtracts the argument to balance
	numWithdrawals++; //increments numWithdrawals by 1
}

void BankAccount::calcInt()
{
	double monthlyInterestRate = annualInterest / 12; //calculates monthly interest rate
	double monthlyInterest = balance * monthlyInterestRate; //calculates amount of money generated from rate
	balance += monthlyInterest; //adds this amount to balance
}

void BankAccount::monthlyProc()
{
	balance -= serviceCharge; //deducts service charge from balance
	calcInt(); //calculates and adds interest
	numDeposits = 0; //resets num deposits, withdrawals, and service charge
	numWithdrawals = 0; 
	serviceCharge = 0.0; 
}
