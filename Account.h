#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

class Account {
	public:
		Account(const string&, const string&, const string&);
		
		long getAcctNum();
		const string& getTransit();
		const string& getBranch();
		const string& getBank();
		void print();
	
	
	protected:
		long acctNum;
		string bank;
		string transit;
		string branch;
		double balance;
		int numTransactions;
};

#endif
