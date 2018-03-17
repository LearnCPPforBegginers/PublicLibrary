#pragma once
#include "User.h"
#include "Book.h"

using namespace std;

class Borrower :
	public User
{
public:
	Borrower();
	Borrower(int maxBooks, Book *booksBorrowed);
	~Borrower();
	void takeBook(Book bToAdd);

private:
	int borrowerID;
	int maxAmountOfBooksBorrowed;
	int nrOfBooksBorrowed;

	Book *booksBorrowed;
};