#include <iostream>
#include "Borrower.h"


using namespace std;


Borrower::Borrower()
{
}

Borrower::Borrower(int borrowerID, Book *borrowedBooks)
	:borrowerID(borrowerID), booksBorrowed(borrowedBooks)
{
	maxAmountOfBooksBorrowed = 7;
	nrOfBooksBorrowed = 0;

	Book empty("N/A", "N/A", 0);

	booksBorrowed = new Book[maxAmountOfBooksBorrowed];
	for (int i = 0; i < maxAmountOfBooksBorrowed; i++)
	{
		booksBorrowed[i] = empty;
	}
}


Borrower::~Borrower()
{
	delete [] booksBorrowed;
}

void Borrower::lendBook(Book bToAdd)
{
	Book empty("N/A", "N/A", 0);
	if (nrOfBooksBorrowed < maxAmountOfBooksBorrowed)
	{
		for (int i = 0; i < maxAmountOfBooksBorrowed; i++) // checks for the first empty spot in our database and places book there
		{
			if (booksBorrowed[i] == empty)
			{
				booksBorrowed[i] = bToAdd;
				nrOfBooksBorrowed++;
				break;
			}
		}
	}
	else
	{
		cout << "This person can't borrow any more books! " << maxAmountOfBooksBorrowed << endl;
	}
}

void Borrower::showBooks()
{
	for (int i = 0; i < maxAmountOfBooksBorrowed; i++)
	{
		booksBorrowed[i].getBookInfo();
	}
}
