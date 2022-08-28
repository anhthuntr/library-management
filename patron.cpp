/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: patron.cpp
*Description: a .cpp file contains the function definitions of all the functions 
* that were declared in the file patron.h
*/ 


#include "patron.h"

using namespace std;

Patron::Patron()
{
	name = "none";
	id = 0;
	balance = 0;
	numbooks=0;
}

Patron::Patron(string name, int id, float balance, int numbooks)
{
	this->name=name;
	this->id=id;
	this->balance=balance;
	this->numbooks=numbooks;
}

void Patron::setName(string name)
{
	this->name=name;
}

void Patron::setID(int id)
{
	this->id=id;
}

void Patron::setBalance(float balance)
{
	this->balance=balance;
}

void Patron::setnumbooks(int numbooks)
{
	this->numbooks=numbooks;
}

string Patron::getName()
{
	return name;
}

int Patron::getID()
{
	return id;
}

float Patron::getBalance()
{
	return balance;
}

int Patron::getnumbooks()
{
	return numbooks;
}


void Patron::PrintInfo()
{
	cout<<"PATRON'S INFO"<<endl;
	cout<<"\tName: "<< name << endl;
	cout<<"\tPatron ID: "<<id<<endl;
	cout<<"\tFine balance: $"<<balance<<endl;
	cout<<"\t# book issued: "<<numbooks<<endl;
}