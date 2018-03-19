#pragma once
#include <iostream>
#include "Borrower.h"

class Librarian :
	public Borrower
{
public:
	Librarian();
	~Librarian();
	void lendBook(Book bToAdd);
};

