/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: books.cpp
*Description: a .cpp file contains the function definitions of all the functions 
* that were declared in the file books.h
* for the input from file, there's a file name books.dat; 
* however, i set the output for any changes or updates to a different file named books1.dat
* the test file includes number of books, title, author, isbn, book id, price, and status
*/ 


#include "book.h"
#include "books.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;

Books::Books() { int bookcount = 0;}

Books::Books(int bookcount) { this->bookcount=bookcount;}

int Books::getcount() { return bookcount ;}

void Books::inccount() { bookcount++; }

void Books::deccount() { bookcount-- ;}

void Books::addBook(string title, string author, string isbn, int libID, float price, string status) 
{
    Book *temp;

    temp=new Book(title,author,isbn,libID,price,status);
    booklist.push_back(temp);

    cout<<"Book added successfully."<<endl;
    temp->PrintInfo(); //display recently add book info

    cout<<endl;

    inccount();

}

void Books::loadBook()
{
    ifstream fin;
    string title, author, isbn;
    int libID;
	float price;
	string status;
	string price1, libID1;
	char input[20];

    //cout<<"Enter input file name: "; cin>>input;
    //fin.open(input);

    fin.open("books.dat");
    if (fin.fail())
    {
    	cout<<"File error."<<endl;
    	exit(1);
    }

    fin >> bookcount; fin.ignore();

    Book *temp;
    
    for ( int i=0; i < bookcount; i++)
    {
        getline(fin,title,',');
        getline(fin,author,',');
        getline(fin,isbn,',');
        getline(fin,libID1,',');
        getline(fin,price1,',');
        getline(fin,status);

       	price=stof(price1);
       	libID=stoi(libID1);
        
        temp=new Book(title,author,isbn,libID,price,status);
        booklist.push_back(temp);
    }

    fin.close();
}

void Books::storeBook()
{
	ofstream fout;
	string title, author, isbn, status;
	int libID;
	float price;
	char output[20];

	//cout<<"Enter output file name: ";cin>>output;

	fout.open("books1.dat");
	if (fout.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}

	fout<<bookcount<<endl;
	Book *temp;
	vector<Book*>::iterator it;

	for (it=booklist.begin(); it!=booklist.end();++it)
	{
		temp=*it;
		fout<<temp->getTitle()<<", "<<temp->getAuthor()<<", "<<temp->getISBN()<<", "
        	<<temp->getLibID()<<", "<<temp->getPrice()<<", "<<temp->getStatus()<<endl;
	}
	fout.close();

}

void Books::printList()
{
	Book *temp;
	vector<Book*>::iterator it;
	cout<<"\n                                ========== LIST OF BOOK ==========\n";
	cout<<setw(22)<<"Title"
		<<setw(20)<<"Author"
		<<setw(7)<<"ISBN"
        <<setw(10)<<"Book ID"
        <<setw(11)<<"Price"
        <<setw(13)<<"Status\n";
    cout<<endl;
    for (it = booklist.begin(); it !=booklist.end(); ++it)
    {
        temp = *it;
        cout<<setw(22)<<temp->getTitle()
        	<<setw(20)<<temp->getAuthor()
        	<<setw(7)<<temp->getISBN()
        	<<setw(10)<<temp->getLibID()
        	<<setw(7)<<"$"<<fixed<<setprecision(2)<<temp->getPrice()
        	<<setw(12)<<temp->getStatus()<<endl;
    }
}

void Books::printname()
{
	
}


void Books::editBook(int id) 
{
	Book *temp;
	unsigned i;
	int choice=-1;
	bool found = false; 
	string title, author, isbn, status;
	int libID;
	float price;


    for ( i =0; i < bookcount; i++)
    {
        //cout<<booklist[i]->getLibID()<<endl;
        if (booklist[i]->getLibID() == id) 
        {
        	found = true;
        	cout<<"\nBOOK FOUND!\n\n";
		    cout<<"\tTitle: " << booklist[i]->getTitle()<<endl;
			cout<<"\tAuthor: " << booklist[i]->getAuthor()<<endl;
			cout<<"\tISBN: " << booklist[i]->getISBN()<<endl;
			cout<<"\tBook ID: " <<booklist[i]->getLibID()<<endl;
			cout<<"\tPrice: $" << booklist[i]->getPrice()<<endl;
			cout<<"\tStatus: " << booklist[i]->getStatus()<<endl;

        	while (choice!=7) {
        	cout<<"\nWhat do you want to do?"<<endl;
        	cout<<"\t 1. Edit title\n"
        		   "\t 2. Edit author\n"
        		   "\t 3. Edit ISBN\n"
        		   "\t 4. Edit book ID\n"
        		   "\t 5. Edit price\n"
        		   "\t 6. Edit status\n"
        		   "\t 7. Quit\n"<<endl;
        	
        	cout<<"Choose an option: ";
        	cin>>choice;
        	cin.ignore();

	        	switch (choice)
	        	{
	        	case 1: 
	        		cout<<"Enter new title: "; 
	        		getline(cin,title);
	        		booklist[i]->setTitle(title);
	        		cout<<"Edited successfully.\n";

					break;

				case 2:
					cout<<"Enter new author: ";
					getline(cin,author);
					booklist[i]->setAuthor(author);
					cout<<"Edited successfully.\n";

					break;

				case 3: 
					cout<<"Enter new ISBN: ";
					cin>>isbn;
					booklist[i]->setISBN(isbn);
					cout<<"Edited successfully.\n";

					break;

				case 4: 
					cout<<"Enter new book ID: ";
					cin>>libID;
					booklist[i]->setLibID(libID);
					cout<<"Edited successfully.\n";

					break;

				case 5:
					cout<<"Enter new price: ";
					cin>>price;
					booklist[i]->setPrice(price);
					cout<<"Edited successfully.\n";

					break;

				case 6:
					cout<<"Enter new status: ";
					cin>>status;
					booklist[i]->setStatus(status);
					cout<<"Edited successfully.\n";

					break;

				}
			}

        }
    }

    if (!found)
    {
    	cout<<"Book not found."<<endl;
    }
}


Book* Books::findBook(int id)
{
    Book *temp;
    bool found=false;

    for (int i =0; i < bookcount; i++)
    {
        if (booklist[i]->getLibID() == id) 
        {
        	found=true;
        
        cout<<"\nBOOK FOUND!\n";
		    cout<<"\tTitle: " << booklist[i]->getTitle()<<endl;
			cout<<"\tAuthor: " << booklist[i]->getAuthor()<<endl;
			cout<<"\tISBN: " << booklist[i]->getISBN()<<endl;
			cout<<"\tBook ID: " <<booklist[i]->getLibID()<<endl;
			cout<<"\tPrice: $" << booklist[i]->getPrice()<<endl;
			cout<<"\tStatus: " << booklist[i]->getStatus()<<endl;
			
			
		}
        
    }
    
    if(!found)
    {
    	cout<<"Book not found.";
    }
    return NULL;

}

void Books::delBook(int id)
{

    vector<Book*>::iterator it;
    bool found=false;
    for (it=booklist.begin(); it!=booklist.end(); ++it)
    {
    	if ((*it)->getLibID() == id)
    	{
    		found=true;
    		booklist.erase(it);
    		deccount();
    		cout<<"Book deleted successfully."<<endl;
    	}
    }

    if (!found)
    {
    	cout<<"Book not exist."<<endl;
    }

    return;
    
}

Book* Books::match(int id, string stt)
{
	bool found=false;
	string str=" available";
	for (int i=0;i<bookcount;++i)
	{
		if (booklist[i]->getLibID() == id) 
        {

        	booklist[i]->setStatus(stt);

        }

	}

	return NULL;
}

string Books::check(int id)
{
	bool found=false;
	string str;
	for (int i=0;i<bookcount;++i)
	{
		if (booklist[i]->getLibID()==id)
		{
			found=true;
			str=booklist[i]->getStatus();

		}
	}

	if (!found)
	{
		cout<<"Book not exist."<<endl;
	}

	return str;
}

float Books::getcost(int id)
{
	float cost;
	for (int i=0;i<bookcount;++i)
	{
		if (booklist[i]->getLibID()==id)
		{
			cost=booklist[i]->getPrice();
		}
	}

	return cost;
}

