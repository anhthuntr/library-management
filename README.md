# a simple library management system
An implemented library management system written in C++, made for homework 3 @ CSCE1040

Author: Tran Anh Thu Nguyen 

## Usage
Run the following command
```
$ make
$ ./output
```
To clean up
```
$ make clean
```

## Program Description
This program is to implement a simple system to manage loans from a library in which includes books and patrons data. There are three entities: ```patrons```,```books```,```loans```.

Patron data will include
```Name, Patron ID, Fine Balance, Number of Books Borrowed```. In the input file (pats.dat), number of total patrons is provided.

Book data will include
```title, author, isbn, book id, price, and status```, total number of books is provided in the input file (books.dat)

Loan data will include
```patron id, book id, amount and status (overdue, normal)```, total number of loans (transactions) is provided in loans.dat

All the changes will be outputted to different files, named pats1.dat, books1.dat, loans1.dat respectively.

## Features
Per collections of Patrons and Books, user will have the ability to ```Add, Edit, Delete, Search, Print``` based on ID.

Per collections of Loans, user will have the ability to 
```
Check-in and check-out book
List all books of a particular patron
List all overdue books
Update loan status based on system clock
Re-check a book
```

### Some rules that are implemented in the program
- A maximum of 6 books can be out to a single patron at a time.
- Loan period is 10 days with an additional recheck of 10 days (only 1 recheck is allowed).
- Fine rate is $0.25 per day. In this program, when check-in book, check in time will be entered by the user, fine is only calculated based on day.

In order to have the program work properly, please enter input accurately and in a correct format. Check the input files for format reference as all the data and codes will be followed by that format.
