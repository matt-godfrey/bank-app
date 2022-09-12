#ifndef SAVING_H
#define SAVING_H

#include <iostream>
#include <string>
#include "Account.h"
#include "defs.h"
#include "Customer.h"

using namespace std;

class Saving:public Account {
	public:
		Saving(const string& t, const string& b, const string& bank, Customer* c, float i);
	

		
		int getInterestRate();
	
	private:
		int interest;
};

#endif
