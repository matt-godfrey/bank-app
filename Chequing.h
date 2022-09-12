#ifndef CHEQUING_H
#define CHEQUING_H

#include <iostream>
#include <string>
#include "Account.h"
#include "defs.h"
#include "Customer.h"

using namespace std;

class Chequing:public Account {
	public:
		Chequing(const string& t, const string& b, const string& bank, Customer* c);
	

	
	private:
};

#endif
