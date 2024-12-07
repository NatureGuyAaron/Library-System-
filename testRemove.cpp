
#include <iostream>
#include <string>
#include <fstream>


void removeItem()//String i represent ID
{
	string index;
	string line;
	ifstream myFile("items.txt");
	cout << "Please enter the ID of the item you wish to remove.";
	cin >> index;

	while (getline(myFile, line))
	{
		string id(line.begin(), line.begin() + line.find(" "));
		cout << "Deleted line : \n" << line;
	}
}

int main()
{
	
	removeItem();

}