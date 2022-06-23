#include <iostream>
#include "Bank.h"

void printMenu(int *choice);

int main() {
	Bank rbc("RBC", "003", "00549");
	int choice = -1;
	rbc.print();
	
	Account a(rbc.getTransit(), rbc.getBranch(), rbc.getName());
	
	while (choice != 0) {
		printMenu(&choice);
		if (choice == 0)
			break;
		
		switch(choice) {
		
			case 1:
				{
					string f;
					string l;
					string e;
					long p;
					cout << "First name: " << endl;
					cin >> f;
					cout << "Last name: " << endl;
					cin >> l;
					cout << "E-mail: " << endl;
					cin >> e;
					cout << "Pin #: " << endl;
					cin >> p;
					
					Customer* newCust = new Customer(f, l, e , p);
					newCust->print();
					if (rbc.addCustomer(newCust))
						cout << "New customer added!" << endl;
					
					break;
				}
			case 2:
			
				break;
			case 3:
			
				break;
			case 4:
			
				break;
			case 5:
			
				break;
			default:
			
				break;
		}
	}
	
	
	rbc.printCustomers();
	return 0;
}


void printMenu(int *choice) {
	
	int c = -1;
	int numOptions = 7;
	string str;

	cout << "\nBank Menu" << endl;
	cout << "  (1) Register New Customer"<< endl;
	cout << "  (2) Register New Account (Note: must be to a registered customer)"<< endl;
	cout << "  (3) Deposit"<< endl;
	cout << "  (4) Withdraw"<< endl;
	cout << "  (5) Print Accounts"<< endl;
	cout << "  (0) Exit" << endl;

	cout << "Please enter your selection: "<< endl;
	cin >> c;

	if (c == 0) {
		*choice = c;
		return;
	}

	while (c < 0 || c > numOptions) {
		printf("Please enter your selection: ");
		cin >> c;
	}

  *choice = c;
	
}
