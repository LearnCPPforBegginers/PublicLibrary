#pragma once
#include "User.h"
#include "Book.h"

using namespace std;

class Borrower :
	public User
{
public:
	Borrower();
	Borrower(int borrowerID, Book *booksBorrowed);
	~Borrower();
	void lendBook(Book bToAdd);
	void showBooks();

	Book returnBook(int bookID) { return booksBorrowed[bookID]; }

private:
	int borrowerID;
	int maxAmountOfBooksBorrowed;
	int nrOfBooksBorrowed;

	Book *booksBorrowed;
};