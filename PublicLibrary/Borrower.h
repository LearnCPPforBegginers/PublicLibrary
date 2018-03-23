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
	Book returnBook(int bookID);

	int borrowerID;
	int maxBooksBorrowed;
	int nrOfBooksBorrowed;
	Book *booksBorrowed;

private:

	
};