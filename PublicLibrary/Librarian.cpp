#include <iostream>
#include "Librarian.h"



Librarian::Librarian()
{
}


Librarian::~Librarian()
{

}

void Librarian::lendBook(Book bToAdd)
{
	Book empty("N/A", "N/A", 0);
	if (nrOfBooksBorrowed < maxBooksBorrowed)
	{
		for (int i = 0; i < maxBooksBorrowed; i++) // checks for the first empty spot in our database and places book there
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
		cout << "This person can't borrow any more books!\n";
	}
}