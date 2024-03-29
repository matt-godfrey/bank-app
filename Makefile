obj = main.o Bank.o Customer.o Account.o Chequing.o Saving.o
headers = Bank.h Customer.h Account.h Chequing.h Saving.h

out: $(obj)
	g++ $(obj) -o out
	
main.o: main.cc $(headers)
	g++ -c -g main.cc

Bank.o: Bank.cc Bank.h
	g++ -c -g Bank.cc

Customer.o: Customer.cc Customer.h
	g++ -c -g Customer.cc
	
Account.o: Account.cc Account.h
	g++ -c -g Account.cc
	
Chequing.o: Chequing.cc Chequing.h
	g++ -c -g Chequing.cc
	
Saving.o: Saving.cc Saving.h
	g++ -c -g Saving.cc


clean:
	rm *.o out
