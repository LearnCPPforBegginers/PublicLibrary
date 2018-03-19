#pragma once
#include <iostream>
#include "User.h"
#include "Book.h"

using namespace std;

class Borrower :
	public User
{
public:
	Borrower();
	Borrower(int borrowerID, Book *borrowedBooks);
	~Borrower();
	void showBooks();

	Book returnBook(int bookID) { return booksBorrowed[bookID]; }

protected:
	int maxBooksBorrowed;
	int nrOfBooksBorrowed;
	Book *booksBorrowed;

private:
	int borrowerID;
};