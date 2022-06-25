#include <iostream>
#include "Bank.h"

void printMenu(int *choice, Customer*);
void printAccountMenu(int *choice);

int main() {
	Bank rbc("RBC", "003", "00549");
	int choice = -1;
	rbc.print();
	
	Customer *curr = NULL;
	
	while (choice != 0) {
		printMenu(&choice, curr);
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
				{
					string f;
					string l;
					long p;
					//Customer *c;
					int choice = -1;
					/*
					cout << "Please enter the following information to open an account: " << endl << endl;;
					cout << "First name: " << endl;
					cin >> f;
					cout << "Last name: " << endl;
					cin >> l;
					cout << "Pin #: " << endl;
					cin >> p;
					if (rbc.getCustomer(f, l, &c)) {
						if (c->getPin() == p) {
						*/
					if (curr == NULL) {
						cout << "You must login to open an account" << endl;
						break;
					}
						
					while (choice != 0) {
						printAccountMenu(&choice);
						if (choice == 0)
							break;
						
						switch(choice) {
							case 1:
								 {
								 	string n = curr->getFirstName() + " " + curr->getLastName();
								 	Chequing *a = new Chequing(rbc.getTransit(), rbc.getBranch(), rbc.getName(), n);
								 	if (rbc.addAccount(a)) {
								 		cout << "Chequing account created successfully!" << endl << endl;
										a->print();
										choice = 0;
								 	}
								 	
									break;
								 }
								
							case 2:
								{
									string n = curr->getFirstName() + " " + curr->getLastName();
									Saving *a = new Saving(rbc.getTransit(), rbc.getBranch(), rbc.getName(), n, 0.05);
									if (rbc.addAccount(a)) {
								 		cout << "Saving account created successfully!" << endl << endl;
										a->print();
										choice = 0;
								 	}
									break;
								}
								
							default:
								cout << "Please enter a valid selection" << endl;
								break;
						}
					}
						/*
						}
						else
							cout << "incorrect pin" << endl;
					}
					else
						cout << "Customer not found" << endl;
				
				*/
				}
			
				break;
			case 3:
				{
					if (curr != NULL) {
						curr = NULL;
						break;
					}
					string f;
					string l;
					long p;
					int attempts = 2;
					cout << "Please enter the following information: " << endl << endl;;
					cout << "First name: " << endl;
					cin >> f;
					cout << "Last name: " << endl;
					cin >> l;
					
					if (rbc.getCustomer(f, l, &curr)) {
						while (attempts > 0) {
							cout << "Attempts: " << attempts << endl;
							cout << "Enter your pin #: " << endl;
							cin >> p;
							if (p == curr->getPin()) {
								cout << "login successful" << endl;
								break;
							}
							else {
								cout << "incorrect pin" << endl;
								attempts--;
							}
						}
						if (attempts == 0) {
							cout << "Max attempts exceeded" << endl;
							curr = NULL;
						}
						
						
					}
					else {
						cout << "Customer not found" << endl;
						curr = NULL;
					}
					
				}
			
				break;	
			case 4:
				{
					if (curr == NULL) {
						cout << "Please login first" << endl;
						break;
					}
					double amount;
				
					cout << "Please enter the amount you want to deposit:" << endl;
					cin >> amount;
					if (amount < 0) {
						cout << "Please enter a valid amount" << endl;
						break;
					}
					long num;
					cout << "Enter your account #: " << endl;
					cin >> num;
					if (rbc.deposit(num, amount) == false) {
						cout << "ERROR: Wrong account number" << endl;
						break;
					}
					cout << "Successfully deposited " << amount << " into account " << num << endl;
			
				break;
				}
				
			case 5:
			
				break;
			default:
			
				break;
		}
	}
	
	
	rbc.printCustomers();
	rbc.printAccounts();
	return 0;
}

void printAccountMenu(int* choice) { 
	int c = -1;
	int numOptions = 3;
	cout << "Select an account: " << endl << endl;
	cout << "Chequing --- (1)" << endl;
	cout << "Saving   --- (2)" << endl;
	cout << "Exit     --- (0)" << endl;
	
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

void printMenu(int *choice, Customer *current) {
	
	int c = -1;
	int numOptions = 7;
	string str;
	
	if (current == NULL)
		str = "NONE";
	else
		str = current->getFirstName() + " " + current->getLastName();
	cout << "CURRENTLY LOGGED IN AS: " << str << endl << endl;

	cout << "\nBank Menu" << endl;
	cout << "  (1) Register"<< endl;
	cout << "  (2) Open an Account (Note: must be a registered customer)"<< endl;
	if (current == NULL)
		cout << "  (3) Login" << endl;
	else
		cout << "  (3) Logout" << endl;
	cout << "  (4) Deposit"<< endl;
	cout << "  (5) Withdraw"<< endl;
	cout << "  (6) Print Accounts"<< endl;
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
