#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account {
	public:
		Account(const string&, const string&);
	
	
	protected:
		int acctNum;
		string transit;
		string branch;
		double balance;
		int numTransactions;
};

#endif
