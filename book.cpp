/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: book.cpp
*Description: a .cpp file contains the function definitions of all the functions 
* that were declared in the file book.h
*/ 

#include "book.h"

using namespace std;

Book::Book()
{
	title = "NONE";
	author = "NONE";
	isbn = "NONE";
	libID = 0;
	price = 0;
	status = "NONE";
}

Book::Book(string Title, string Author, string Isbn, int LibID, float Price, string Status)
{
	title = Title;
	author = Author;
	isbn = Isbn;
	libID=LibID;
	price=Price;
	status=Status;
}

void Book::setTitle(string Title)
{
	title=Title;
}

void Book::setAuthor(string Author)
{
	author=Author;
}

void Book::setISBN(string Isbn)
{
	isbn=Isbn;
}

void Book::setLibID(int LibID)
{
	libID=LibID;
}

void Book::setPrice(float Price)
{
	price=Price;
}

void Book::setStatus(string Status)
{
	status=Status;
}


string Book::getTitle()
{
	return title;
}

string Book::getAuthor()
{
	return author;
}

string Book::getISBN()
{
	return isbn;
}

int Book::getLibID()
{
	return libID;
}

float Book::getPrice()
{
	return price;
}

string Book::getStatus()
{
	return status;
}


void Book::PrintInfo()
{
	cout<<"BOOK DESCRIPTION\n";
	cout<<"\tTitle: " << title<<endl;
	cout<<"\tAuthor: " << author<<endl;
	cout<<"\tISBN: " << isbn<<endl;
	cout<<"\tBook ID: " <<libID<<endl;
	cout<<"\tPrice: $" << price<<endl;
	cout<<"\tStatus: " << status<<endl;
}


