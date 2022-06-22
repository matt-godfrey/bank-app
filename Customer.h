#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer {
	public:
		Customer(const string&, const string&, int);
	
	private:
		int id;
		string first;
		string last;
		int pin;
};

#endif
