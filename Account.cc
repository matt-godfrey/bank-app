#include "Account.h"

Account::Account(const string& t, const string& b) {
	
	transit = t;
	branch = b;
	balance = 0;
	numTransactions = 0;
	// set random account num
}


