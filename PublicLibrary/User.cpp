#include <iostream>
#include "User.h"

using namespace std;

User::User()
{
}

User::User(string firstName, string lastName)
{
	userFirstName = firstName;
	userLastName = lastName;
}


User::~User()
{
}

void User::setName(string firstName, string lastName)
{
	userFirstName = firstName;
	userLastName = lastName;
}
