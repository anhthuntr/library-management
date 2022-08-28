/* 
* CSCE 1040 Homework 3 
* Section: 001 or 002 or 003, depending on which section you are enrolled in 
* Name: Tran Anh Thu Nguyen
* UNT Email: trananhthunguyen@my.unt.edu
* Date submitted: 
 
*File name: patrons.cpp
*Description: a .cpp file contains the function definitions of all the functions 
* that were declared in the file patrons.h
* for the input from file, there's a file name pats.dat; 
* however, i set the output for any changes or updates to a different file named pats1.dat
* the test file includes number of patrons, name, patron id, fine balance, and number of books borrowed
*/ 


#include "patron.h"
#include "patrons.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;

Patrons::Patrons() { int patcount = 0;}

Patrons::Patrons(int patcount) {this->patcount=patcount;}

int Patrons::getcount() { return patcount ;}

void Patrons::inccount() { patcount++; }

void Patrons::deccount() { patcount-- ;}

void Patrons::addpat(string name, int id, float balance, int numbooks) 
{
    Patron *temp;

    temp=new Patron(name,id,balance,numbooks);
    patlist.push_back(temp);

    cout<<"Patron added successfully."<<endl;
    temp->PrintInfo(); //display recently add patron info

    inccount();

}


void Patrons::loadpat()
{

    ifstream fin;
    string name, id1, amtP, bal;
    int id;
	float amountPaid, balance;
	char input[20];

    //cout<<"Enter input file name: "; cin>>input;
    //fin.open(input);

    fin.open("pats.dat");
    if (fin.fail())
    {
    	cout<<"File error."<<endl;
    	exit(1);
    }

    fin >> patcount; fin.ignore();
    
    Patron *temp;
    
    for ( int i=0; i < patcount; i++)
    {
        getline(fin,name,',');
        getline(fin,id1,',');
        getline(fin,amtP,',');
        getline(fin,bal);

        id=stoi(id1);
        amountPaid=stof(amtP);
        balance=stof(bal);
        
    	temp=new Patron(name,id,amountPaid,balance);
    	patlist.push_back(temp);

    }

    fin.close();
    
}

void Patrons::storepat()
{
	ofstream fout;
	char output[20];

	//cout<<"Enter output file name: ";cin>>output;

	fout.open("pats1.dat");
	if (fout.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}

	fout<<patcount<<endl;
	Patron *temp;
	vector<Patron*>::iterator it;

	for (it=patlist.begin(); it!=patlist.end();++it)
	{
		temp=*it;
		fout<<temp->getName()<<", "<<temp->getID()<<", "<<temp->getBalance()<<", "
        	<<temp->getnumbooks()<<endl;
	}
	fout.close();

}

void Patrons::editpat(int id)
{

    unsigned i;
    int choice=-1;
    string name;
    float balance;
    int numbooks;
    bool found=false;

    for (i=0; i<patcount; ++i)
    {
        if(patlist[i]->getID()==id)
        {
            found=true;
            cout<<"\nPATRON FOUND.\n\n";
            cout<<"\tName: "<< patlist[i]->getName() << endl;
            cout<<"\tPatron ID: "<< patlist[i]->getID() <<endl;
            cout<<"\tFine balance: $"<<patlist[i]->getBalance()<<endl;
            cout<<"\tBook issued: "<<patlist[i]->getnumbooks()<<endl;

            while (choice!=5)
            {
            cout<<"\nWhat do you want to do?"<<endl;
            cout<<"\t 1. Edit name\n"
                   "\t 2. Edit ID\n"
                   "\t 3. Edit fine balance:\n"
                   "\t 4. Edit # of books\n"
                   "\t 5. Quit\n"<<endl;

            cout<<"Choose an option: ";
            cin>>choice;
            cin.ignore();

                switch (choice)
                {
                    case 1:
                        cout<<"Enter new name: "; getline(cin,name);
                        patlist[i]->setName(name);
                        cout<<"Edited successfully.\n";

                        break;

                    case 2:
                        cout<<"Enter new ID: "; cin>>id;
                        patlist[i]->setID(id);
                        cout<<"Edited successfully.\n";

                        break;

                    case 3:
                        cout<<"Enter new fine balance: "; cin>>balance;
                        patlist[i]->setBalance(balance);
                        cout<<"Edited successfully.\n";

                        break;

                    case 4:
                        cout<<"Enter new current # of books: "; cin>>numbooks;
                        patlist[i]->setnumbooks(numbooks);
                        cout<<"Edited successfully.\n";

                        break;

                }

            }
        }
    }
}

void Patrons::printList()
{
	Patron *temp;
	vector<Patron*>::iterator it;
	cout<<"\n                 ========== LIST OF PATRON ==========\n";
	cout<<setw(18)<<"Full Name"
        <<setw(10)<<"ID"
        <<setw(15)<<"Fine Balance"
        <<setw(15)<<"# of books\n";
    cout<<endl;
    for (it = patlist.begin(); it !=patlist.end(); ++it)
    {
        temp = *it;
        cout<<setw(18)<<temp->getName()
            <<setw(10)<<temp->getID()
            <<setw(10)<<"$"<<fixed<<setprecision(2)<<temp->getBalance()
            <<setw(10)<<temp->getnumbooks()<<endl;
    }
}


Patron* Patrons::findpat(int id)
{
    Patron *temp;
    bool found=false;

    for (int i =0; i < patcount; i++)
    {
        if (patlist[i]->getID() == id) 
        {
        	found=true;
        
        cout<<"\nPATRON FOUND!\n";
            cout<<"\tName: "<< patlist[i]->getName() << endl;
            cout<<"\tPatron ID: "<< patlist[i]->getID() <<endl;
            cout<<"\tFine balance: $"<<patlist[i]->getBalance()<<endl;
            cout<<"\t# of books: "<<patlist[i]->getnumbooks()<<endl;
		}
        
    }
    
    if(!found)
    {
    	cout<<"Patron not found.";
    }
    return NULL;

}

void Patrons::delpat(int id)
{

    vector<Patron*>::iterator it;
    bool found=false;
    for (it=patlist.begin(); it!=patlist.end(); ++it)
    {
    	if ((*it)->getID() == id)
    	{
    		found=true;
    		patlist.erase(it);
    		deccount();
    		cout<<"Patron deleted successfully."<<endl;
    	}
    }

    if (!found)
    {
    	cout<<"Patron not exist."<<endl;
    }

    return;
    
}


Patron* Patrons::match(int id, int newnum)
{
    Patron *temp;

    for (int i =0; i < patcount; i++)
    {
        if (patlist[i]->getID() == id) 
        {
            //newnum=patlist[i]->getnumbooks()+1;
            patlist[i]->setnumbooks(newnum);
        }
        
    }
    
    return NULL;

}

int Patrons::check(int id)
{
    Patron *temp;
    bool found=false;
    int numbooks;

    for (int i =0; i < patcount; i++)
    {
        if (patlist[i]->getID() == id) 
        {
            found=true; 
            numbooks=patlist[i]->getnumbooks();
        }
        
    }
        
    
    if(!found)
    {
        cout<<"Patron not exist.\n";
    }

    return numbooks;

}

void Patrons::update(int id, float cost)
{
    
    for (int i=0;i<patcount;++i)
    {
        if (patlist[i]->getID()==id)
        {
            patlist[i]->setBalance(patlist[i]->getBalance()+cost);
            cout<<"Fine: $"<<cost<<endl;
            cout<<"Total fine balance: $"<<patlist[i]->getBalance()<<endl;
        }
    }
}

void Patrons::payfine(int id, float amt)
{
    bool found=false;
    for (int i=0;i<patcount;++i)
    {
        if (patlist[i]->getID()==id)
        {
            found=true;
            patlist[i]->setBalance(patlist[i]->getBalance()-amt);
            cout<<"Amount paid: $"<<amt<<endl;
            cout<<"New current balance: $"<<patlist[i]->getBalance()<<endl;
        }
    }

    if (!found)
    {
        cout<<"Patron not found."<<endl;
    }
}

