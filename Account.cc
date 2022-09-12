#include "Account.h"


Account::Account(const string& t, const string& b, const string& bank, Customer* c) {
	srand((unsigned)time(NULL));
	this->bank = bank;
	transit = t;
	branch = b;
	balance = 0;
	numTransactions = 0;
	owner = c;
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

Customer* Account::getOwner() {
	return owner;
}

double Account::getBalance() {
	return balance;
}

bool Account::deposit(double a) {
	if (a < 0) return false;
	
	balance += a;
	owner->updateBalance(a);
	numTransactions++;
	return true;
}

bool Account::withdraw(double a) {
	if (a <= 0) {
		cout << "Please enter an amount greater than 0" << endl;
		return false;
	}
		
	if (a > balance) {
		cout << "Not enough funds in account" << endl;
		return false;
	}
		
	balance -= a;
	owner->updateBalance(-a);
	numTransactions++;
	return true;
}

void Account::print() {
	cout << "Bank: " << bank << " | ";
	cout << "Owner: " << owner->getFirstName() << " | ";
	cout << "Transit: " << transit << " | ";
	cout << "Branch: " << branch << " | ";
	cout << "Balance: " << balance << " | ";
	cout << "Transactions: " << numTransactions << " | ";
	cout << "Account #: " << acctNum << endl;
}


