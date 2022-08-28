/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: loans.h
*Description: a header file which includes methods for loan entity and class definitions
*/ 


#ifndef LOANSH
#define LOANSH

#include "loan.h"
#include "patron.h"
#include "patrons.h"
#include <vector>

using namespace std;

class Loans{
public:
	Loans();
	Loans(int loancount);
	int getcount();
	void inccount();
	void deccount();

	void addloan(int, int, int, float,string, string, string, char);
	void editloan(int);
	void delloan(int);
	Loan *findloan(int);
	int checkid(int);
	string checkStt(int);
	void loadloan();
	void storeloan();

	void getbook(int);
	void getoverdue(string);
	void printList();

	void addtime(int, int, int, int);
	float checkdue(int, int, int, int);
	void recheck(int, string);

private:
	int loancount;
	vector<Loan*> loanlist;

};

#endif //LOANSH