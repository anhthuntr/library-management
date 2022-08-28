/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: book.h
*Description: a header file which includes attributes for book entity and class definitions
*/ 


#ifndef BOOKH
#define BOOKH

#include <iostream>
#include <string>

using namespace std;

class Book {
public:
	Book();
	Book(string Title, string Author, string Isbn, int LibID, float Price, string Status);
	// ========== Mutators =========
	void setTitle(string);
	void setAuthor(string);
	void setISBN(string);
	void setLibID(int);
	void setPrice(float);
	void setStatus(string);

	// ========= Accessors ========
	string getTitle();
	string getAuthor();
	string getISBN();
	int getLibID();
	float getPrice();
	string getStatus();


	void PrintInfo();


private:
	string title, author, isbn;
	int libID;
	float price;
	string status;

};

#endif //BOOKH