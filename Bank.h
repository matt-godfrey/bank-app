#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>

#include "Customer.h"
#include "Account.h"
#include "Chequing.h"
#include "Saving.h"
using namespace std;

class Bank {
	public:
		Bank(const string& n, const string& b, const string& t);
		~Bank();
		
		bool addAccount(Account*);
		bool deposit(double amount);
		bool addCustomer(Customer*);
		bool getCustomer(const string& first, const string& last, Customer**);
		const string& getBranch();
		const string& getTransit();
		const string& getName();
		int getNumCustomers();
		void print();
		void printCustomers();
		void printAccounts();

	
	private:
		int numAccounts;
		int numCustomers;
		string name;
		int funds;
		string transit;
		string branch;
		Account** accounts;
		Customer** customers;

};

#endif
