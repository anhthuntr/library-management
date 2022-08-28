/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: books.h
*Description: a header file which includes methods for book entity and class definitions
*/ 


#ifndef BOOKSH
#define BOOKSH

#include "book.h"
#include <vector>

using namespace std;

class Books {
public:
	Books();
	Books(int bookcount);
	int getcount();
	void inccount();
    void deccount();

	void addBook(string, string, string, int, float, string);
	void editBook(int);
	void delBook(int);
	Book *findBook(int);
	Book *match(int, string);
	string check(int);
	float getcost(int);

	void loadBook();
	void storeBook();

	void printList();
	void printname();

private:
	int bookcount;
	vector<Book*> booklist;
};

#endif //BOOKSH