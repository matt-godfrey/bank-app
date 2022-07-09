#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

class Account {
	public:
		Account(const string&, const string&, const string&, const string&);
		
		long getAcctNum();
		const string& getTransit();
		const string& getBranch();
		const string& getBank();
		const string& getOwner();
		double getBalance();
		bool deposit(double);
		bool withdraw(double);
		void print();
	
	
	protected:
		long acctNum;
		string bank;
		string transit;
		string branch;
		string owner;
		double balance;
		int numTransactions;
};

#endif
