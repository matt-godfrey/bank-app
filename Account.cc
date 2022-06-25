#include "Account.h"


Account::Account(const string& t, const string& b, const string& bank, const string& n) {
	srand((unsigned)time(NULL));
	this->bank = bank;
	transit = t;
	branch = b;
	balance = 0;
	numTransactions = 0;
	owner = n;
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

const string& Account::getOwner() {
	return owner;
}

bool Account::deposit(double a) {
	if (a < 0) return false;
	
	balance += a;
	transactions++;
	return true;
}

void Account::print() {
	cout << "Bank: " << bank << " | ";
	cout << "Owner: " << owner << " | ";
	cout << "Transit: " << transit << " | ";
	cout << "Branch: " << branch << " | ";
	cout << "Balance: " << balance << " | ";
	cout << "Transactions: " << numTransactions << " | ";
	cout << "Account #: " << acctNum << endl;
}


