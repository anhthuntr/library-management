/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: main.cpp
*Description: a .cpp file contains all classes with menu display on screen
* there are 3 functions for each menu, patron menu, book menu, loan menu
* each menu will have different options for user
* and a main menu includes all of those 3

**NOTE: To check in book, check in time will be entered by the user,
* fine is only calculated based on day
* The output data file is only updated when the program is terminated (quitting)
*/ 


#include "book.h"
#include "books.h"
#include "patron.h"
#include "patrons.h"
#include "loan.h"
#include "loans.h"
#include "date.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

Books bo;
Patrons pat;
Loans trans;
Date date;


void patmenu()
{
	int selection=-1;
	int ID;
	string name;
	int numbooks;
	float balance;
	float amt;

	while (selection!=7)
					{
						cout<<"\nPATRON MENU\n"
							  "\t1. Add Patron\n"
							  "\t2. Edit Patron\n"
							  "\t3. Find Patron\n"
							  "\t4. Remove Patron\n"
							  "\t5. Pay Fine\n"
							  "\t6. Print List\n"
							  "\t7. Return to main menu\n"
							  //"\t7. Quit\n"
							  "Choose an option: "; cin>>selection;
							  switch (selection)
							  {
							  	case 1: 
							  		balance=0;
							  		numbooks=0;

								    cout<<"Enter new patron ID: ";
								    cin>>ID;
								    cin.ignore();

								    cout<<"Enter name: "; 
								    getline(cin, name);

							  		pat.addpat(name, ID, balance, numbooks); 
							  		break;

							  	case 2: 
							  			cout<<"Enter patron ID you want to edit: "; cin>>ID;
							  			cout<<endl;
							  			pat.editpat(ID); break;

							  	case 3: 
							  			cout<<"Enter patron ID you want to find: "; cin>>ID;
							  			cout<<endl;
							  			pat.findpat(ID); break;

							  	case 4: 
							  			cout<<"Enter patron ID to remove: "; cin>>ID;
							  			pat.delpat(ID); break;

							  	case 5:
							  			cout<<"Enter patron ID: "; cin>>ID;
							  			cout<<"Enter amount: "; cin>>amt;
							  			pat.payfine(ID, amt);
							  			break;

							  	case 6: pat.printList(); break;
							  }
					}
}

void bookmenu()
{
	int selection=-1;
	int ID;
	string title, author, isbn, status;
	int libID;
	float price;

	while (selection!=6)
					{
						cout<<"\nBOOK MENU\n"
							  "\t1. Add Book\n"
							  "\t2. Edit Book\n"
							  "\t3. Find Book\n"
							  "\t4. Remove Book\n"
							  "\t5. Print List\n"
							  "\t6. Return to main menu\n"
							  //"\t7. Quit\n"
							  "Choose an option: "; cin>>selection;
							  switch (selection)
							  {
							  	case 1: 

								  	cout<<"Enter new book ID: ";
								    cin>>libID;
								    cin.ignore();

								    cout<<"Enter title: "; 
								    getline(cin, title);

								    cout<<"Enter author's name: "; 
								    getline(cin, author);

								    cout<<"Enter ISBN: "; 
								    cin>>isbn;
								    

								    cout<<"Enter price: ";
								    cin>>price;
								    

								    cout<<"Enter status (available, in, out, lost, repair): ";
								    cin>>status;

								    bo.addBook(title, author, isbn, libID, price, status);
								    
								  	break;
							  	

							  	case 2: 
							  			cout<<"Enter book ID you want to edit: "; cin>>ID;
							  			
							  			bo.editBook(ID); break;
							  	case 3:
							  			cout<<"Enter book ID you want to find: "; cin>>ID;
							  			
							  			bo.findBook(ID); break;
							  	case 4: 
							  			cout<<"Enter book ID you want to delete: "; cin>>ID;
							  			bo.delBook(ID); break;
							  	case 5: bo.printList(); break;
							  	case 7: exit(1);

							  }
					}

}

void loanmenu()
{
	int selection=-1;
	int ID;
	int loanid, bookid, patid, newnum;
	float amt, due;
	string stt;
	char recheck;
	string strDate="";
	string strDue="";
	string newDue="";
	bool flag=false;
	int duedate[3];
	int checkdate[3];
	ostringstream ss, oss, iss;




	while (selection!=8 && !flag)
					{
						cout<<"\nLOAN MENU\n"
							  "\t1. Check out\n"
							  "\t2. Check in\n"
							  "\t3. Find Transaction\n"
							  "\t4. Recheck\n"
							  "\t5. List of overdue books\n"
							  "\t6. Print List\n"
							  "\t7. List all books of a patron\n"
							  "\t8. Return to main menu\n"
							  
							  
							  "Choose an option: "; cin>>selection;
							  switch (selection)
							  {
							  	case 1: 
							  		

									cout<<"Enter new Loan ID: ";
									cin>>loanid;

									// each transaction will have its unique number, thus loanid cannot be same as ones already exist //
									if(trans.checkid(loanid)==0)
										{
											break;
										}
									
										    
									cout<<"Enter patron ID: "; 
									cin>>patid;
										    
									cout<<"Enter book ID: "; 
									cin>>bookid;
										    
									cout<<"Enter amount: "; 
									cin>>amt;	

									stt="normal";
									recheck='n';			   


							  		//check for conditions//

							  		if (pat.check(patid)>=6) // total books cannot exceed 6
							  		{
							  			cout<<"Exceed maximum number of books can borrow."<<endl;
							  		}

							  		else if (bo.check(bookid)!=" available") //book has to be available to check out
							  		{
							  			cout<<"Book not available."<<endl;
							  		}

							  		else if (trans.checkStt(patid)=="overdue") //patron has no overdue books
							  		{
							  			cout<<"Cannot issue book due to currently having overdue books."<<endl;
							  		}

							  		if (pat.check(patid)<6 && bo.check(bookid)==" available" && trans.checkStt(patid)=="normal")
							  		{
							  			
							  			ss<<setw(2)<<setfill('0')<<date.getCurrentMonthAsString()<<"/"<<setw(2)<<setfill('0')<<
							  				date.getCurrentDayAsString()<<"/"<<date.getCurrentYearAsString();

							  			strDate=ss.str();
							  			
							  			/* add 10 days for due date */
							  				time_t t;
											struct tm *tmp;
											time(&t);

											t += 10 * 24 * 60 * 60;
											tmp = localtime(&t);

							  			oss<<setw(2)<<setfill('0')<<tmp->tm_mon+1<<"/"<<setw(2)<<setfill('0')<<
							  				tmp->tm_mday<<"/"<<tmp->tm_year+1900;

							  			strDue=oss.str();

							  			trans.addloan(loanid, patid, bookid, amt, strDate, strDue, stt, recheck);

							  			//get time when check out book from system clock
							  			trans.addtime(bookid,date.getCurrentYearAsInt(),date.getCurrentMonthAsInt(), 
							  				date.getCurrentDayAsInt());
							  			
							  			
							  			cout<<"Loan added successfully."<<endl;

							  			//===update patron and book===//

							  			newnum=pat.check(patid); //get number of books
							  			pat.match(patid,++newnum); //update number of books
							  			bo.match(bookid, " out"); //change book status
							  		}

							  		
							  		break;

							  	case 2: 

							  			cout<<"Enter transaction ID: "; cin>>loanid;

							  			cout<<"Enter patron ID: "; cin>>patid;

							  			cout<<"Enter book ID: "; cin>>bookid;

							  			cout<<"Enter book status (in or lost): "; cin>>stt;

							  			//get the date
							  			do {
							  				cout<<"Enter check in date (mm/dd/yyyy): ";
							  				cin>>strDate;

							  				if (strDate.size()<10)
							  				{
							  					cout<<"Invalid date format."<<endl;
							  				}

							  				else {
							  					flag=true;
							  				}
							  			} while (!flag);

							  			duedate[0]=atoi(strDate.substr(0,2).c_str()); //month
        								duedate[1]=atoi(strDate.substr(3,2).c_str()); //day
            							duedate[2]=atoi(strDate.substr(6,4).c_str()); //year


							  			newnum=pat.check(patid);
							  			pat.match(patid,--newnum);
							  			

							  			due=trans.checkdue(bookid, duedate[2], duedate[0], duedate[1]);
							  			
							  			if (due>0)
							  			{
							  				cout<<"\nBook is overdue.\n";
							  				pat.update(patid,due); //update fine balance
							  				cout<<endl;
							  			}
							  										  			
							  			
							  			if (stt=="in")
							  			{
		
								  			bo.match(bookid, " available");
								  			cout<<"\nBook checked in.\n";
								  			//pat.update(patid,0);
								  			
							  			}


							  			else if (stt=="lost")
							  			{
							  				
							  				cout<<"\nBook is lost.\n";
							  				bo.match(bookid, " lost");
							  				pat.update(patid,bo.getcost(bookid)); //update fine balance
							  				cout<<endl;

							  			}

							  			trans.delloan(loanid); //FIXME

							  			break;
							  			
							  	case 3:
							  			cout<<"Enter transaction ID: "; cin>>ID;
							  			trans.findloan(ID); break;

							  	case 4: 
							  			cout<<"Enter book ID you would like to recheck: "; cin>>ID;

							  				/* add 10 days for due date */
							  				time_t t;
											struct tm *tmp;
											time(&t);

											t += 20 * 24 * 60 * 60;
											tmp = localtime(&t);

							  			iss<<setw(2)<<setfill('0')<<tmp->tm_mon+1<<"/"<<setw(2)<<setfill('0')<<
							  				tmp->tm_mday<<"/"<<tmp->tm_year+1900;

							  			newDue=iss.str();
							  			trans.recheck(ID,newDue); //set new due date
							  			cout<<"Due date updated.\n";
							  			break;

							  	case 5:
							  			trans.getoverdue("overdue");
							  			break;

							  	case 6: trans.printList(); break;

							  	case 7:
							  			cout<<"Enter patron ID: "; cin>>patid;
							  			trans.getbook(patid);
							  			break;


							  }
					}

}



int main(int argc, const char * argv[]) 
{
	
	int choice=-1;

	pat.loadpat();
	bo.loadBook();
	trans.loadloan();


	while (choice!=0)
	{
		cout<<"LIBRARY LOAN MANAGEMENT - MAIN MENU\n"
		  "\t1. Patron \n"
		  "\t2. Book\n"
		  "\t3. Loan\n"
		  "\t0. Quit\n"
		  "Enter choice: "; cin>>choice;

		  switch (choice)
		  {
		  	case 1: 
					
					patmenu();
					break;

			case 2: 
					
					bookmenu();
					break;

			case 3:
					
					loanmenu();
					break;

				}
			}


	return 0;
}