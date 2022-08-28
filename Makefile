output: main.o patron.o patrons.o book.o books.o loan.o loans.o date.o
	g++ main.o patron.o patrons.o book.o books.o loan.o loans.o date.o -o output

main.o: main.cpp
	g++ -c main.cpp

patron.o: patron.cpp patron.h
	g++ -c patron.cpp

patrons.o: patrons.cpp patrons.h
	g++ -c patrons.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

books.o: books.cpp books.h
	g++ -c books.cpp

loan.o: loan.cpp loan.h
	g++ -c loan.cpp

loans.o: loans.cpp loans.h
	g++ -c loans.cpp

date.o: date.cpp date.h
	g++ -c date.cpp
	
clean:
	rm *.o output