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
bool Bank::getCustomer(const string& first, const string& last, Customer**) {
	return true;
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

void Bank::print() {
	cout << "********* " << name << " Bank Info **********" << endl;
	cout << "Accounts: " << numAccounts << endl;
	cout << "Customers: " << numCustomers << endl;
	cout << "Branch: " << branch << endl;
	cout << "Transit: " << transit << endl;
	cout << "**********************************" << endl;
}


