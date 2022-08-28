/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: loan.cpp
*Description: a .cpp file contains the function definitions of all the functions 
* that were declared in the file loan.h
*/ 


#include "loan.h"

using namespace std;

Loan::Loan()
{
	loanid=0;
	patid=0;
	bookid=0;
	amount=0;
	dateStr="-";
	dueStr="-";
	status="none";
	recheck='-';
}

Loan::Loan(int loanid, int patid, int bookid, float amount, string dateStr, string dueStr, string status, char recheck)
{
	this->loanid=loanid;
	this->patid=patid;
	this->bookid=bookid;
	this->amount=amount;
	this->dateStr=dateStr;
	this->dueStr=dueStr;
	this->status=status;
	this->recheck=recheck;
}

void Loan::setLoanID(int loanid)
{
	this->loanid=loanid;
}

void Loan::setPatID(int patid)
{
	this->patid=patid;
}

void Loan::setBookID(int bookid)
{
	this->bookid=bookid;
}

void Loan::setAmount(float amount)
{
	this->amount=amount;
}

void Loan::setStatus(string status)
{
	this->status=status;
}

int Loan::getLoanID()
{
	return loanid;
}

int Loan::getPatID()
{
	return patid;
}

int Loan::getBookID()
{
	return bookid;
}

float Loan::getAmount()
{
	return amount;
}

string Loan::getStatus()
{
	return status;
}

void Loan::setyear(int year) { this->year=year; }

void Loan::setmonth(int month) { this->month = month; }

void Loan::setday(int day) { this->day = day; }

void Loan::setdate(string dateStr) { this->dateStr=dateStr; }

void Loan::setdue(string dueStr) { this->dueStr=dueStr ; }

void Loan::setre(char recheck) { this->recheck=recheck; }

int Loan::getyear() { return year; }

int Loan::getmonth() { return month; }

int Loan::getday() { return day; }

string Loan::getdate() { return dateStr; }

string Loan::getdue() { return dueStr; }

char Loan::getre() {return recheck; }

void Loan::PrintInfo()
{
	cout<<"LOAN INFO"<<endl;
	cout<<"\tLoan ID: "<<loanid<<endl;
	cout<<"\tPatron ID: "<<patid<<endl;
	cout<<"\tBook ID: "<<bookid<<endl;
	cout<<"\tAmount: $"<<amount<<endl;
	cout<<"\tIssued date: "<<dateStr<<endl;
	cout<<"\tDue date: "<<dueStr<<endl;
	cout<<"\tStatus: "<<status<<endl;
	cout<<"\tRecheck: "<<recheck<<endl;
}
