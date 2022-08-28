/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: patrons.h
*Description: a header file which includes methods for patron entity and class definitions
*/ 


#ifndef PATRONSH
#define PATRONSH

#include "patron.h"
#include <vector>

using namespace std;

class Patrons{
public:
	Patrons();
	Patrons(int patcount);
	int getcount();
	void inccount();
	void deccount();

	void addpat(string, int, float, int);
	void editpat(int);
	void delpat(int);
	Patron *findpat(int);
	Patron *match(int, int);
	int check(int);
	void update(int, float);
	void payfine(int, float);

	void printList();
	void loadpat();
	void storepat();


private:
	int patcount;
	vector<Patron*> patlist;
};

#endif //PATRONSH