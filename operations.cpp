
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string searchItem;

void setSearchItem(string i)
{
	searchItem = i;
}

string getSearchItem()
{
	return searchItem;
}

class search 
{
public:


void searchItem()
{
	ifstream myFile("file.txt");

	string line;

	string searchString = getSearchItem();

	int lineNumber = 0;

	bool found = false;

	if (!myFile.is_open())
	{
		cout << "File is not opened";
	}

		while (getLine(myFile,line))
		{
				lineNumber++;
				if (line.find(searchString))
				{
					cout << "Found \"" << searchString << "\" at line " << lineNumber << line ;
				}
				else if (!found)
				{
					cout << "\"" << searchString << "\" not found in the file" ;
				}
				else
				{
					cout << "Unable to open file.";
				}


		}
		myFile.close();
	
} //end of function
};//end of class



int main()
{
	string item;
	cout << "Please enter the string that you would like to search." ;
	cin >> item ;
	setSearchItem(item);
	return 0;
}

