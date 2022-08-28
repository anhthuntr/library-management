/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: loans.cpp
*Description: a .cpp file contains the function definitions of all the functions 
* that were declared in the file patrons.h
* for the input from file, there's a file name loans.dat;
* however, i set the output for any changes or updates to a different file named loans1.dat
* The test file includes transaction id, patron id, book id, amount and status (overdue, normal)
*/ 


#include "loan.h"
#include "loans.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;


Loans::Loans() { int loancount=0;}

Loans::Loans(int loancount) {
    this->loancount=loancount;
}

int Loans::getcount() { return loancount ;}

void Loans::inccount() { loancount++; }

void Loans::deccount() { loancount-- ;}

void Loans::addloan(int loanid, int patid, int bookid, float amt, string date, string due, string status, char recheck) 
{
    Loan *temp;


    temp=new Loan(loanid, patid, bookid, amt, date, due, status, recheck);
    loanlist.push_back(temp);
    temp->PrintInfo(); //display recently add loan info
    inccount();

    }

void Loans::loadloan()
{

    ifstream fin;
    int loanid, bookid, patid;
    float amt;
    string stt, date, due;
    char recheck;
	char input[20];

    //cout<<"Enter input file name: "; cin>>input;
    //fin.open(input);

    fin.open("loans.dat");
    if (fin.fail())
    {
    	cout<<"File error."<<endl;
    	exit(1);
    }

    fin >> loancount; fin.ignore();
    
    Loan *temp;
    
    for ( int i=0; i < loancount; i++)
    {
        fin>>loanid>>patid>>bookid>>amt>>date>>due>>stt>>recheck;
        
    	temp=new Loan(loanid, patid, bookid, amt, date, due, stt, recheck);
    	loanlist.push_back(temp);

    }

    fin.close();
    
}

void Loans::storeloan()
{
	ofstream fout;
	char output[20];

	//cout<<"Enter output file name: ";cin>>output;

	fout.open("loans1.dat");
	if (fout.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}

	fout<<loancount<<endl;
	Loan *temp;
	vector<Loan*>::iterator it;

	for (it=loanlist.begin(); it!=loanlist.end();++it)
	{
		temp=*it;
		fout<<temp->getLoanID()<<" "<<temp->getPatID()<<" "<<temp->getBookID()<<" "
        	<<temp->getAmount()<<" "<<temp->getdate()<<" "<<temp->getdue()<<" "
            <<temp->getStatus()<<" "<<temp->getre()<<endl;
	}
	fout.close();

}

void Loans::printList()
{
	Loan *temp;
	vector<Loan*>::iterator it;
	cout<<"\n                       ========== LIST OF TRANSACTION ==========\n";
	cout<<"LoanID"
        <<setw(11)<<"PatronID"
        <<setw(9)<<"BookID"
        <<setw(10)<<"Amount"
        <<setw(15)<<"Issued Date"
        <<setw(12)<<"Due Date"
        <<setw(12)<<"Status"
        <<setw(12)<<"Recheck\n";

    cout<<endl;
    for (it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        temp = *it;
        cout<<temp->getLoanID()
            <<setw(10)<<temp->getPatID()
            <<setw(10)<<temp->getBookID()
            <<setw(5)<<"$"<<fixed<<setprecision(2)<<temp->getAmount()
            <<setw(15)<<temp->getdate()
            <<setw(15)<<temp->getdue()
            <<setw(10)<<temp->getStatus()
            <<setw(7)<<temp->getre();
            cout<<endl;
    }
}


Loan* Loans::findloan(int id)
{
    Loan *temp;
    bool found=false;

    for (int i =0; i < loancount; i++)
    {
        if (loanlist[i]->getLoanID() == id) 
        {
        	found=true;
        
        cout<<"\nLOAN FOUND!\n";
            cout<<"\tLoan ID: "<<loanlist[i]->getLoanID()<<endl;
            cout<<"\tPatron ID: "<<loanlist[i]->getPatID()<<endl;
            cout<<"\tBook ID: "<<loanlist[i]->getBookID()<<endl;
            cout<<"\tAmount: $"<<loanlist[i]->getAmount()<<endl;
            cout<<"\tIssued date: "<<loanlist[i]->getdate()<<endl;
            cout<<"\tDue date: "<<loanlist[i]->getdue()<<endl;
            cout<<"\tStatus: "<<loanlist[i]->getStatus()<<endl;
            cout<<"\tRecheck (y/n): "<<loanlist[i]->getre()<<endl;
		}
        
    }
    
    if(!found)
    {
    	cout<<"Transaction not found.";
    }
    return NULL;

}

int Loans::checkid(int id)
{
    int check;

    for (int i =0; i < loancount; i++)
    {
        if (loanlist[i]->getLoanID() == id) 
        {
            cout<<"Transaction already exist. Enter a different ID number.\n";
            check=0;
        
        }
        
    }

    return check;

}


void Loans::delloan(int id)
{

    vector<Loan*>::iterator it;
    bool found=false;
    for (it=loanlist.begin(); it!=loanlist.end(); ++it)
    {
    	if ((*it)->getLoanID() == id)
    	{
    		found=true;
    		loanlist.erase(it);
    		deccount();
    	}
    }

    if (!found)
    {
    	cout<<"Transaction not exist."<<endl;
    }
    
}

void Loans::getbook(int id)
{
    bool found=false;

    cout<<"== List of Books =="<<endl;
    for (int i=0;i<loancount;++i)
    {
        if (loanlist[i]->getPatID()==id)
        {
            found=true;
            cout<<loanlist[i]->getBookID()<<"\t"<<loanlist[i]->getStatus()<<endl;
        }
    }

    if (!found)
    {
        cout<<"Patron not found."<<endl;
    }
}

void Loans::getoverdue(string str)
{
    bool found=false;

    cout<<"== List of overdue books =="<<endl;
    cout<<"BOOK ID:\n";
    for (int i=0;i<loancount;++i)
    {
        if (loanlist[i]->getStatus()==str)
        {
            found=true;
            cout<<"\t"<<loanlist[i]->getBookID()<<endl;
        }
    }

    if (!found)
    {
        cout<<"No overdue book."<<endl;
    }
}

string Loans::checkStt(int id)
{
    bool found=false;
    string str;
    for (int i=0;i<loancount;++i)
    {
        if (loanlist[i]->getPatID()==id)
        {
            found=true;
            str=loanlist[i]->getStatus();

        }
    }

    if (!found)
    {
        cout<<"Transaction not exist."<<endl;
    }

    return str;
}

void Loans::addtime(int id, int y, int m, int d)
{
    bool found=false;
    for (int i=0;i<loancount;++i)
    {
        if (loanlist[i]->getBookID()==id)
        {
            found=true;
            loanlist[i]->setyear(y);
            loanlist[i]->setmonth(m);
            loanlist[i]->setday(d);

        }
    }
}

float Loans::checkdue(int id, int y, int m, int d)
{
    bool found=false;
    int due=0;
    int due1=0;
    float cost=0;
    char dateStr[3];

    
    for (int i=0;i<loancount;++i)
    {
        if (loanlist[i]->getBookID()==id)
        {
            found=true;
            string str=loanlist[i]->getdate();

            dateStr[0]=atoi(str.substr(0,2).c_str()); //month
            dateStr[1]=atoi(str.substr(3,2).c_str()); //day
            dateStr[2]=atoi(str.substr(6,4).c_str()); //year

            
            if (dateStr[0]==m) {

                if ((d-dateStr[1])>10)
                {

                    due=d-dateStr[1]-10;
                    cost=0.25*due;
                }
            }

            else if (dateStr[0]<m) {

                cout<<"How many days have passed? "; cin>>due;

                if (due<=10)
                {
                    cost=0;
                }

                else {
                    cost=(due-10)*0.25;
                }
                
            }


        
        }
    }


        if (!found)
        {
            cout<<"Book not found.\n";
        }  

    return cost;
}

void Loans::recheck(int id, string str)
{
    bool found=false;

    for (int i=0;i<loancount;++i)
    {
        if (loanlist[i]->getBookID()==id)
        {
            found=true;

            if (loanlist[i]->getre()=='n')
            {
                loanlist[i]->setdue(str);
                loanlist[i]->setre('r');
            }

            else if (loanlist[i]->getre()=='y')
            {
                cout<<"Only recheck once.\n";
            }

            
        }
    }

    if (!found)
    {
        cout<<"Book not found.";
    }
}

