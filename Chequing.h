#ifndef CHEQUING_H
#define CHEQUING_H

#include <iostream>
#include <string>
#include "Account.h"
#include "defs.h"

using namespace std;

class Chequing:public Account {
	public:
		Chequing(const string& t, const string& b, const string& bank, const string& n);
	

	
	private:
};

#endif
