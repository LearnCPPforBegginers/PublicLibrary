#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"
#include "User.h"
#include "Librarian.h"
#include "Borrower.h"

using namespace std;

int main()
{
	int id = 1;
	Book book;
	Librarian librarian;

	const Book book1("1st Book", "1st Author", 2000);
	const Book book2("2nd Book", "2nd Author", 2001);
	const Book book3("3rd Book", "3rd Author", 2002);
	const Book book4("4th Book", "4th Author", 2003);
	
	Library lib("Book World", &book);
	Borrower br(1, &book);

	lib.addBook(book1);
	lib.addBook(book2);
	lib.addBook(book3);
	lib.addBook(book4);
	
	br.lendBook(lib.takeBookFromLibrary(1));
	br.showBooks();

	return 0;
}
