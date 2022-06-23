#include "Account.h"


Account::Account(const string& t, const string& b, const string& bank) {
	srand((unsigned)time(NULL));
	this->bank = bank;
	transit = t;
	branch = b;
	balance = 0;
	numTransactions = 0;
	// set random account num
	long min = 1000000;
    long max = 99999999;
    acctNum = rand() % (max - min + 1) + min;

}

long Account::getAcctNum() {
	return acctNum;
}

const string& Account::getTransit() {
	return transit;
}
const string& Account::getBranch() {
	return branch;
}
const string& Account::getBank() {
	return bank;
}

void Account::print() {
	cout << "Bank: " << bank << endl;
	cout << "Transit: " << transit << endl;
	cout << "Branch: " << branch << endl;
	cout << "Balance: " << balance << endl;
	cout << "Transactions: " << numTransactions << endl;
	cout << "Account #: " << acctNum << endl;
}


