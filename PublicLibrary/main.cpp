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
	Book book;
	Librarian librarian;

	Book book1("1st Book", "1st Author", 2000);
	Book book2("2nd Book", "2nd Author", 2001);
	Book book3("3rd Book", "3rd Author", 2002);
	Book book4("4th Book", "4th Author", 2003);
	
	Library lib("Book World", &book);
	Borrower br(1, &book);
	lib.addBook(book1);
	lib.addBook(book2);
	lib.addBook(book3);
	lib.addBook(book4);
	
	librarian.lendBook(br, lib.takeBookFromLibrary(1));
	br.showBooks();

	lib.showBook(1);

	return 0;

}
