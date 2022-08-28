/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: loan.h
*Description: a header file which includes attributes for loan entity and class definitions
*/ 

#ifndef LOANH
#define LOANH

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Loan {
public:
	Loan();
	Loan(int, int, int, float, string, string, string, char);
	// ========= Mutators ========

	void setLoanID(int);
	void setPatID(int);
	void setBookID(int);
	void setAmount(float);
	void setStatus(string);
	void setyear(int);
	void setmonth(int);
	void setday(int);
	void setdue(string);
	void setdate(string);
	void setre(char);

	// ======== Accessors =======

	int getLoanID();
	int getPatID();
	int getBookID();
	float getAmount();
	string getStatus();
	int getyear();
	int getmonth();
	int getday();
	string getdue();
	string getdate();
	char getre();

	void PrintInfo();

private:
	int loanid, patid, bookid;
	float amount;
	string status;
	int year, month, day;
	string dueStr, dateStr;
	char recheck;
};

#endif // LOANH