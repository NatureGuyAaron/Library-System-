#include "Accounts.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>


using namespace std;

 
map< string, string > userAccounts;

Accounts:: Accounts( string name, string password)
{
	this->name = name; 
	this->password = password;
	LogUserAccounts(name, password);
}



void Accounts:: setName( string name)
{
	this->name = name;
}

 string Accounts:: getName()
{
	 return this->name;
}

  void Accounts ::LogUserAccounts(string username,  string password )
 {
	 ofstream accountsFile("accounts.txt", ios::app);
	 try
	 {
		 if (!accountsFile.is_open())
		 {
			 cout << " This file could not be opened";
			 return;
		 }

		 userAccounts[username] = password;
		
		 for (const auto& account : userAccounts)
		 {
			 accountsFile << account.first << ":" << account.second << "\n";
		 }

	 }//end try
	 catch (...)
	 {
		 cout << " This file could not be accessed";
	 }

 }

 void Accounts::setPassword(std::string password)
 {
	 this->password = password;
 }

 std::string Accounts::getPassword()
 {
	 return this->password;
 }