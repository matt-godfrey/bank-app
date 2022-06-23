#include "Customer.h"


Customer::Customer(const string& f, const string& l, const string& e, long p) {
	// set random id
	first = f;
	last = l;
	email = e;
	pin = p;
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

void Customer::print() {
	cout << "First: " << first << endl;
	cout << "Last: " << last << endl;
	cout << "Email: " << email << endl;
}
