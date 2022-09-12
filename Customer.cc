#include "Customer.h"


Customer::Customer(const string& f, const string& l, const string& e, long p) {
	// set random id
	first = f;
	last = l;
	email = e;
	pin = p;
	balance = 0;
}


const string& Customer::getFirstName() {
	return first;
}
const string& Customer::getLastName() {
	return last;
}
const string& Customer::getEmail() {
	return email;
}
long Customer::getPin() {
	return pin;
}

float Customer::getBalance() {
	return balance;
}

void Customer::updateBalance(float amount) {
	
	balance += amount;
}


void Customer::print() {
	cout << "First: " << first << endl;
	cout << "Last: " << last << endl;
	cout << "Email: " << email << endl;
	cout << "Balance: " << balance << endl;
}
