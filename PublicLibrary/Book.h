#pragma once
#include <string>
using namespace std;

class Book
{
public:
	Book();
	Book(string bName, string bAuthor, int bYear); // constructor overloading
	~Book();
	void getBookInfo() const; // prints the book name, year and author
	string getBookName() const { return bookName; };
	string getBookAuthor() const { return bookAuthor; };
	int getBookYear() const { return bookYear; };
	bool operator == (const Book &b) const; // overload of the == so we can compare 2 object of our class
	bool operator != (const Book &b) const; // overload of the !=

private:

	int bookYear;
	int bookUniqueID;
	static int bookUniqueIDcounter;
	
	string bookName;
	string bookAuthor;

};

