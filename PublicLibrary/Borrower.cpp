#include <iostream>
#include "Borrower.h"


using namespace std;


Borrower::Borrower()
{
	
}

Borrower::Borrower(int borrowerID, Book *borrowedBooks)
	:borrowerID(borrowerID), booksBorrowed(borrowedBooks)
{
	Book empty("N/A", "N/A", 0);
	
	maxBooksBorrowed = 3;
	
	booksBorrowed = new Book[maxBooksBorrowed];
	for (int i = 0; i < maxBooksBorrowed; i++)
	{
		booksBorrowed[i] = empty;
	}
}

Borrower::~Borrower()
{
	delete[] booksBorrowed;
	booksBorrowed = NULL;
}

void Borrower::showBooks()
{
	for (int i = 0; i < maxBooksBorrowed; i++)
	{
		booksBorrowed[i].getBookInfo();
	}
}

Book Borrower::returnBook(int bookID)
{
	return booksBorrowed[bookID];
}
