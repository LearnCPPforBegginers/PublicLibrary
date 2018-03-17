#include <iostream>
#include "Borrower.h"


using namespace std;

Borrower::Borrower()
{
}

Borrower::Borrower(int borrowerID, Book *borrowedBooks)
	:maxAmountOfBooksBorrowed(borrowerID), booksBorrowed(borrowedBooks)
{
	maxAmountOfBooksBorrowed = 3;

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

void Borrower::takeBook(Book bToAdd)
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
		cout << "This person can't borrow any more books!" << endl;
	}
}

void Borrower::showBooks()
{
	Book temp;
	for (int i = 0; i < maxAmountOfBooksBorrowed; i++)
	{
		booksBorrowed[i].getBookInfo();
	}
}
