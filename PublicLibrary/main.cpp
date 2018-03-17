#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"
#include "User.h"

using namespace std;

int main()
{
	Book book;

	const Book book1("1st Book", "1st Author", 2000);
	const Book book2("2nd Book", "2nd Author", 2001);
	const Book book3("3rd Book", "3rd Author", 2002);
	const Book book4("4th Book", "4th Author", 2003);

	Library lib("Book World", &book);
	
	lib.addBook(book1);
	lib.addBook(book2);
	lib.addBook(book3);
	lib.addBook(book4);
	
	lib.showBook(1);
	lib.showBook(2);
	lib.showBook(3);
	lib.showBook(4);
	lib.showBook(4);
	lib.showBook(4);

	return 0;
}
