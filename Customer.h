#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer {
	public:
		Customer(const string&, const string&, const string&, long);
		
		const string& getFirstName();
		const string& getLastName();
		const string& getEmail();
		long getPin();
		void print();
	
	private:
		int id;
		string first;
		string last;
		string email;
		long pin;
};

#endif
