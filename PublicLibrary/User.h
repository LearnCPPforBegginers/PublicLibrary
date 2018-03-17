#pragma once
#include <iostream>

using namespace std;

class User
{
public:
	User();
	User(string firstName, string lastName);
	~User();
	string getFirstName() const { return userFirstName; }
	string getLastName() const { return userLastName; }

private:
	string userFirstName;
	string userLastName;
};

