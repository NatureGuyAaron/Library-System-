
#include <iostream>
#include <string>
#include <fstream>
#include "items.cpp"

using namespace std;


class search 

{
public: 

	string searchItem;

	void setSearchItem(string i)
	{
		searchItem = i;
	}

	string getSearchItem()
	{
		return searchItem;
	}



void searchItem(string search)
{
	ifstream myFile("items.txt");

	string line;

	int lineNumber = 0;

	bool found = false;

	if (!myFile.is_open())
	{
		cout << "File is not opened";
	}

		while (getline(myFile, line))
		{
				lineNumber++;
				if (line.find(search))
				{
					cout << "Found \"" << search << "\" at line " << lineNumber << line ;
				}
				else if (!found)
				{
					cout << "\"" << search << "\" not found in the file" ;
				}
				else
				{
					cout << "Unable to open file.";
				}


		}
		myFile.close();
	
} //end of function
};//end of class

class primaryOperations
{
	
	void addItem(string i, string ti, string ty, bool a = true)
	{	
		ofstream myFile("items.txt");
		item itemKey;
		myFile << "ID : \ " << itemKey.getID() << "Type : \ " << itemKey.getType() << "Title : \ " << itemKey.getTitle() << "Available : \ " << itemKey.getAvailability();
		
	}

	void removeItem()
	{
		ofstream myFile("items.txt");
	}

	void checkIn()
	{
		ofstream myFile("activity.txt");
	}

	void checkOut() 
	{
		ofstream myFile("activity.txt");
	}

	void report()
	{
		ofstream myFile("activity.txt");
	}



};


int main()
{
	string item;
	search searchKey;
	cout << "Please enter the string that you would like to search." ;
	cin >> item ;
	searchKey.searchItem(item);
	return 0;
}

