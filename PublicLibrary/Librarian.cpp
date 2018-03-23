#include <iostream>
#include "Librarian.h"



Librarian::Librarian()
{

}


Librarian::~Librarian()
{

}

void Librarian::lendBook(Borrower &toBorrower, Book bToAdd)
{
	Book empty("N/A", "N/A", 0);
	if (toBorrower.nrOfBooksBorrowed < toBorrower.maxBooksBorrowed)
	{
		for (int i = 0; i < toBorrower.maxBooksBorrowed; i++) // checks for the first empty spot in our database and places book there
		{
			if (toBorrower.booksBorrowed[i] == empty)
			{
				toBorrower.booksBorrowed[i] = bToAdd;
				toBorrower.nrOfBooksBorrowed++;
				break;
			}
		}
	}
	else
	{
		cout << "This person can't borrow any more books!\n";
	}
}