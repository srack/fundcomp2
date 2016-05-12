all: main

main:  main.o BankAccount.o SavingsAccount.o CreditCard.o
	g++ main.o BankAccount.o SavingsAccount.o CreditCard.o -o main

main.o:  main.cpp
	g++ -c main.cpp

BankAccount.o:  BankAccount.cpp
	g++ -c BankAccount.cpp

SavingsAccount.o:  SavingsAccount.cpp
	g++ -c SavingsAccount.cpp

CreditCard.o:  CreditCard.cpp
	g++ -c CreditCard.cpp

clean:
	rm -f *.o main
