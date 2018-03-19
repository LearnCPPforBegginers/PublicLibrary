#include <iostream>
#include "Library.h"
#include "Book.h"

using namespace std;


Library::Library()
{
}

Library::Library(string lName, Book *bArchive)
	:libraryName(lName), bookArchive(bArchive)
{	
	Book empty("N/A", "N/A", 0);
	maxAmountOfBooks = 7; // set the library capacity

	bookArchive = new Book[maxAmountOfBooks]; // dynamic memory allocation for our book database
	for (int i = 0; i < maxAmountOfBooks; i++) // fill the book database with the empty book
	{
		bookArchive[i] = empty;
	}
}

Library::~Library()
{
	// free the alocated memory when the object is deconstructed
	delete [] bookArchive;
	bookArchive = NULL;
}

void Library::addBook(Book bToAdd)
{
	Book empty("N/A", "N/A", 0);
	if (nrOfBooks < maxAmountOfBooks)
	{
		for (int i = 0; i < maxAmountOfBooks; i++) // checks for the first empty spot in our database and places book there
		{
			if (bookArchive[i] == empty)
			{
				bookArchive[i] = bToAdd;
				nrOfBooks++;
				break;
			}
		}
	}
	else
	{
		cout << "The library is FULL!" << endl;
	}
}

void Library::showBook(int id) // we need to search in book archive for (id-1) because the array starts from 0 and book unique ID starts from 1
{
	Book empty("N/A", "N/A", 0);
	if ((id <= maxAmountOfBooks) && (id > 0) && (bookArchive[id - 1] != empty)) // check if the book number you search for is valid
	{
		cout << "Library " << libraryName << " book " << id << ": "<< endl;
		bookArchive[id - 1].getBookInfo();
	}
	else if (id < 1)
	{
		cout << "Invalid book number!" << endl;
	}
	else if (id > maxAmountOfBooks)
	{
		cout << "This library can only store " << maxAmountOfBooks << " books!" << endl;
	}
	else
	{
		cout << "There is no book stored in this location!\n" << endl;
		cout << "nrOfBooks = " << nrOfBooks << endl;
	}
}

Book Library::takeBookFromLibrary(int id)
{
	Book empty("N/A", "N/A", 0), tempBook("N/A", "N/A", 0);
	if (bookArchive[id - 1] != empty) // we need to verify if there is a book at given location so we don't change the number of books if location is empty
	{
		bookArchive[id - 1].getBookInfo();
		tempBook = bookArchive[id - 1];
		bookArchive[id - 1] = empty;
		nrOfBooks--;
		return tempBook;
	}
	else
	{
		cout << "There is no book in the specified location!\n" << endl;
		return empty;
	}
}

// searchBy = 'a' or 'n' - 'a' stands for Author and 'n' stands for Name of the book
void Library::searchLibrary(string searchParam, char searchBy)
{
	bool bookFound = false;
	if(tolower(searchBy) == 'n')
	{ 
		for (int i = 0; i < maxAmountOfBooks; i++)
		{
			if (searchParam == bookArchive[i].getBookName())
			{
				showBook(i+1);
				bookFound = true;
			}
			else if (i + 1 == maxAmountOfBooks && !bookFound)
			{
				cout << "Can not find requested book name.\n" << endl;
				bookFound = false;
			}
		}
	}
	else if (tolower(searchBy) == 'a')
	{
		for (int i = 0; i < maxAmountOfBooks; i++)
		{
			if (searchParam == bookArchive[i].getBookAuthor())
			{
				showBook(i + 1);
				bookFound = true;
			}
			else if (i + 1 == maxAmountOfBooks && !bookFound)
			{
				cout << "Can not find requested author.\n" << endl;
				bookFound = false;
			}
		}
	}
	else
	{
		cout << "The search can be only by the name 'n' or the author 'a'.\n" << endl;
	}
}

void Library::searchLibrary(int byBookYear)
{
	for (int i = 0; i < maxAmountOfBooks; i++)
	{
		if (byBookYear == bookArchive[i].getBookYear())
		{
			showBook(i + 1);
		}
	}
}

void Library::swapBooks(int bookOne, int bookTwo)
{
	Book tmpBook1("N/A", "N/A", 0); // temporary book object to store the Book from the location before swap
	Book tmpBook2("N/A", "N/A", 0);
	tmpBook1 = bookArchive[bookOne - 1];
	tmpBook2 = bookArchive[bookTwo - 1];
	takeBookFromLibrary(bookOne);
	addBook(tmpBook2);
	takeBookFromLibrary(bookTwo);
	addBook(tmpBook1);
}

int Library::retriveBookByInfo(string bName, string bAuthor)
{
	for (int i = 0; i < maxAmountOfBooks; i++)
	{
		if (bName == bookArchive[i].getBookName() && bAuthor == bookArchive[i].getBookAuthor())
		{
			return i+1;
		}
	}
	return 0;
}




