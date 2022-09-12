#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Customer.h"

using namespace std;

class Account {
	public:
		Account(const string&, const string&, const string&, Customer*);
		
		long getAcctNum();
		const string& getTransit();
		const string& getBranch();
		const string& getBank();
		Customer* getOwner();
		double getBalance();
		bool deposit(double);
		bool withdraw(double);
		void print();
	
	
	protected:
		long acctNum;
		string bank;
		string transit;
		string branch;
		Customer* owner;
		double balance;
		int numTransactions;
};

#endif
