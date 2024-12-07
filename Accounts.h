#pragma once

#include <string>
using namespace std;
class Accounts
{
private:
	string name, password;
	bool Membership;

public:
	
	Accounts(string name, string password);
	
	string getName();
	void setName( string name);
	string getPassword();
	void setPassword(string password);
	 void LogUserAccounts(string username, string password);
};

