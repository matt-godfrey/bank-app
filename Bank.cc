#include "Bank.h"
#include "defs.h"

Bank::Bank(const string& n, const string& b, const string& t) {
	accounts = new Account*[MAX_ARR];
	customers = new Customer*[MAX_ARR];
	numAccounts = 0;
	numCustomers = 0;
	name = n;
	branch = b;
	transit = t;
	funds = 0;
}

Bank::~Bank() {
	for (int i = 0; i < numAccounts; ++i)
		delete accounts[i];
	delete [] accounts;
	
	for (int i = 0; i < numCustomers; ++i)
		delete customers[i];
	delete [] customers;
}


bool Bank::addAccount(string type) {
	return true;
}

bool Bank::deposit(double amount) {
	
	return true;
}
bool Bank::addCustomer(string fname, string lname) {
	return true;
}
bool Bank::getCustomer(const string& first, const string& last, Customer**) {
	return true;
}


