/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: patron.h
*Description: a header file which includes attributes for patron entity and class definitions
*/ 


#ifndef PATRONH
#define PATRONH

#include <iostream>
#include <string>
#include "book.h"
#include "books.h"

using namespace std;

class Patron {
public:
	Patron(); //default constructor
	Patron(string name, int id, float balance, int numbooks);
	void setName(string);
	void setID(int);
	void setBalance (float);

	void setnumbooks(int);
	void PrintInfo();

	string getName();
	int getID();
	float getBalance();

	int getnumbooks();

private:
	string name;
	int id, numbooks;
	float balance;


};


#endif //PATRONH