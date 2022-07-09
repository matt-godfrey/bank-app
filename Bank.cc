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


bool Bank::addAccount(Account *a) {
	for (int i = 0; i < numAccounts; ++i) {
		if (accounts[i]->getAcctNum() == a->getAcctNum()) {
			a = NULL;
			return false;
		}
	}
	accounts[numAccounts] = a;
	numAccounts++;
	return true;
}

bool Bank::deposit(long acctNum, double amount) {
	for (int i = 0; i < numAccounts; ++i) {
		if (accounts[i]->getAcctNum() == acctNum) {
			accounts[i]->deposit(amount);
			return true;
		}
	}
	
	return false;
}


bool Bank::withdraw(long acctNum, double amount) {
	for (int i = 0; i < numAccounts; ++i) {
		if (accounts[i]->getAcctNum() == acctNum) {
			if (accounts[i]->withdraw(amount))
				return true;
		}
	}
	return false;
}

bool Bank::addCustomer(Customer* c) {
	if (numCustomers >= MAX_ARR)
		return false;
	
	int pos = numCustomers;
	
	for (int i = 0; i < numCustomers; ++i) {
		if (c->getLastName() <= customers[i]->getLastName()) {
			pos = i;
			for (int j = numCustomers; j >= i; j--) {
				customers[j+1] = customers[j];
			}
			break;
		}
	}
	customers[pos] = c;
	numCustomers++;
	return true;
}
bool Bank::getCustomer(const string& f, const string& l, Customer **c) {
	for (int i = 0; i < numCustomers; ++i) {
		if (customers[i]->getFirstName() == f) {
			if (customers[i]->getLastName() == l) {
				*c = customers[i];
				return true;
			}
		}
	}
	*c = NULL;
	return false;
}

const string& Bank::getBranch() {
	return branch;
}

const string& Bank::getTransit() {
	return transit;
}

const string& Bank::getName() {
	return name;
}

int Bank::getNumCustomers() {
	return numCustomers;
}

void Bank::printCustomers() {
	for (int i = 0; i < numCustomers; ++i)
		customers[i]->print();
}

void Bank::printAccounts() {
	for (int i = 0; i < numAccounts; ++i) {
		accounts[i]->print();
	}
}

void Bank::printCustomerAccounts(Customer *c) {
	string n = c->getFirstName() + " " + c->getLastName();
	for (int i = 0; i < numAccounts; ++i) {
		if (accounts[i]->getOwner() == n)
			accounts[i]->print();
	}
}

void Bank::print() {
	cout << "********* " << name << " Bank Info **********" << endl;
	cout << "Accounts: " << numAccounts << endl;
	cout << "Customers: " << numCustomers << endl;
	cout << "Branch: " << branch << endl;
	cout << "Transit: " << transit << endl;
	cout << "**********************************" << endl;
}


