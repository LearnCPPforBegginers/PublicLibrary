#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"

using namespace std;

int Book::bookUniqueIDcounter = 0;

Book::Book()
{
}

Book::Book(string bName, string bAuthor, int bYear)
	:bookName(bName), bookAuthor(bAuthor), bookYear(bYear)
{
	bName = "N/A";
	bAuthor = "N/A";
	bYear = 0;

	bookUniqueID = bookUniqueIDcounter++;
}

Book::~Book()
{

}


void Book::getBookInfo() const
{
	if (bookName != "N/A")
	{
		cout << "\nUnique ID: " << bookUniqueID << endl;
		cout << "Name:   " << bookName << endl;
		cout << "Author: " << bookAuthor << endl;
		cout << "Year:   " << bookYear << endl;
		cout << endl;
	}
}

bool Book::operator==(const Book & b) const
{
	return ((bookName == b.bookName) && (bookAuthor == b.bookAuthor) && (bookYear == b.bookYear));
}

bool Book::operator!=(const Book & b) const
{
	return ((bookName != b.bookName) && (bookAuthor != b.bookAuthor) && (bookYear != b.bookYear));
}
