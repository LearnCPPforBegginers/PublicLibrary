#pragma once
#include "book.h"


class Library
{
public:
	Library();
	Library(string lName, Book *bArchive); // constructor overloading
	~Library();
	
	void addBook(Book bToAdd); // add a book to the library
	void showBook(int id); // show a book stored in the library by it's unique ID number
	void takeBookFromLibrary(int id); // take a book out of the library
	void searchLibrary(string searchParam, char searchBy); // searchBy = 'a' or 'n' - 'a' stands for Author and 'n' stands for Name of the book
	void searchLibrary(int byBookYear); // search for the books by year of release
	void swapBooks(int bookOne, int bookTwo); // swap two books in the library
	
	int retriveBookByInfo(string bName, string bAuthor); // get the book ID number by Name and Author

private:
	
	int maxAmountOfBooks; // maximum number of books that our library can hold
	int nrOfBooks; // total number of books stored in our library
	
	string libraryName;
	
	Book *bookArchive; // our Book type archive where we store the book objects
};

