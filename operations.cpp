
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

class Operations
{

public:
vector <string> vec;
string searchItem;
 int checkInCount = 0, checkOutCount = 0;
	  


	//set and get methods for the search item or the removed item
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
			if (line.find(searchItem))
			{
				cout << "Found " << searchItem << " at line " << lineNumber << line;
			}
			else if (!found)
			{
				cout << search << " not found in the file";
			}
			else
			{
				cout << "Unable to open file.";
			}
			myFile.close();
		}


	} //end of function

		//Adds an item to inventory
	void addItem(string id, string title, string type, bool availability = true)
	{
		ofstream myFile("items.txt");
		vec.push_back(id);
		myFile << "ID : " << id << "Type : " << type << "Title : " << title << "Available : " << availability;

	}

	//removes item from inventory
	void removeItem(string search)
	{
		string index;
		string line;
		ifstream myFile("items.txt");
		cout << "Please enter the ID of the item you wish to remove.";
		cin >> index;

		while (getline(myFile, line))
		{
			string id(line.begin(), line.begin() + line.find(" "));
			cout << "Deleted line : /n" << line;
		}
	}

	//checks in an item ie. when someone brings back an item
	void checkIn(string firstName, string lastName, string accountID, string type, string itemID, string title)
	{
		ofstream myFile("checkIn.txt");
		myFile << firstName << lastName << accountID << itemID << type << title;
		checkInCount++;
	}
	//checks out an item ie. when someone goes with an item
	void checkOut(string firstName, string lastName, string accountID, string type, string itemID, string title)
	{
		ofstream myFile("checkOut.txt");
		myFile << firstName << lastName << accountID << itemID << type << title;
		checkOutCount++;
	}

	void report(string id) // will check for popularity from the checkout file based on how many times the ID occurs in the file.
	{
		ifstream myFile("checkout.txt");
		string line;
		int count = 0;
		int position = 0;

		for (int i = 0; i < vec.size(); ++i)
		{
			while (getline(myFile, line))
			{

				if (line.find(vec[i]))
				{
					count++;
				}
				else if (!line.find(vec[i]))
				{
					cout << "\"" << id << "\" not found in the file";
				}
				else
				{
					cout << "Unable to open file.";
				}
			}
		}

		myFile.close();
		cout << "Popularity : " << count;
	}
};
	

