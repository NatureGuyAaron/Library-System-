#include <iostream>
#include <fstream>
#include <string>
#include "Accounts.h"
#include <map>

using namespace std;

class Items {
protected:
   
    int id;
    string title;
  
    bool isAvailable;

public:
    enum ITEM_TYPE { CD, DVD ,Books};
    ITEM_TYPE itemType;
    enum CONTENT_TYPE { SelfHelp, Fiction, Non_Fiction, Science, SCI_Fi, Music};
    CONTENT_TYPE contentType;
  
    Items() : id(0), title(""), itemType(CD), contentType(SelfHelp) ,isAvailable(true) {}
    Items(int id, string title, ITEM_TYPE itemType, CONTENT_TYPE contentType)
        : id(id), title(title), itemType(itemType), contentType(contentType) , isAvailable(true) {}


    virtual void setItemName(string itemName) = 0;
    virtual void displayDetails() const = 0;

    int getId() const { return id; }
    string getTitle() const { return title; }
    ITEM_TYPE getType() const { return itemType; }
    bool getAvailability() const { return isAvailable; }

    void setAvailability(bool status) { isAvailable = status; }


    virtual ~Items() {}
};

class Books : public Items
{

public:

    Books() : Items(0, " ", Items::Books, Items::SelfHelp) {}
    Books(int id, string title, ITEM_TYPE itemType, CONTENT_TYPE contentType)
        : Items(id, "", itemType, contentType) {}


    void setItemName(string itemName) override {
        title = itemName;
    }

    void displayDetails() const override {
        cout << "Book -> ID: " << id << ", Title: " << title << ", ITEM_TYPE: Book" << endl;
    }

    


};

// I have to add the books class
class CD : public Items {
public:

    CD() : Items(0, " ", Items::CD, Items::SelfHelp) {}
    CD(int id, string title,  ITEM_TYPE itemType, CONTENT_TYPE contentType )
        : Items(id,"",  itemType, contentType) {}


    void setItemName(string itemName) override {
        title = itemName;
    }

    void displayDetails() const override {
        cout << "CD -> ID: " << id << ", Title: " << title << ", ITEM_TYPE: CD" << endl;
    }
};

class DVD : public Items {
public:
  
    DVD() : Items(0, "", Items::DVD, Items:: SelfHelp) {}
    DVD(int id, string title, ITEM_TYPE itemType, CONTENT_TYPE contentType)
        : Items(id, title, itemType,contentType) {}

   
    void setItemName(string itemName) override {
        title = itemName;
    }

    void displayDetails() const override {
        cout << "DVD -> ID: " << id << ", Title: " << title << ", ITEM_TYPE: DVD" << endl;
    }
};

int main() {

    Accounts acc1("John", "767");

    //ifstream books("Books.txt");
    //string printOutItemContents;

    //string username, password, fileName;;


    //Accounts acc1("Brian", "12@");
    //CD cd1(122, "Classical Music", Items::ITEM_TYPE::CD, Items::CONTENT_TYPE :: Music);
    //cd1.displayDetails();

 
    //DVD dvd1(456, "Science Documentary", Items::ITEM_TYPE::DVD, Items::CONTENT_TYPE::Science );
    //dvd1.displayDetails();

    //bool running = true;
    //while (running)
    //{
    //    cout << "____________Login_____________\n\n";
    //    cout << "______Enter Your Credentials_____\n";
    //    cout << " Enter your username:  \n\n";
    //    cin >> username;
    //    cout << "Enter your password:   \n\n";
    //    cin >> password;
    //    try {
    //        if (loguser() == true)
    //        {
    //            int choice;
    //            cout << "Enter 0,1 0r 2 for the type of Item you're looking for:(0)Book\n(1)DVD\n(2)CD ";
    //            cin >> choice;
    //            switch (choice)
    //            {
    //            case 0: while (getline(books, printOutItemContents))
    //            {
    //                cout << printOutItemContents << "\n";

    //            }

    //                  break;
    //            case 1:

    //                break;

    //            case 2:

    //            default:
    //                "The option you choose is not available";
    //            }
    //        }
    //    }
    //    catch (exception e)
    //    {

    //    } 
    //}//End Outer While loop which is for running the whole program 
 
    //ifstream accountFiles("accounts.txt");

    //if (!accountFiles.is_open()) {
    //    cout << "This file could not be opened" << endl;
    //    return 1;
    //}

    //string readFile;
    //while (getline(accountFiles, readFile)) {
    //    cout << readFile << endl;
    //}

    //accountFiles.close();

    return 0;
}


//bool searchFilesForTheUsersCredentials(string username, string password) // optional map<string , string > userAccounts 
//{
//    bool credentialsMatch = false;
//    ifstream accountsFile("accounts.txt");
//
//    if (accountsFile.contains(username, password))
//    {
//        credentialsMatch = true;
//    }
//    return credentialsMatch;
//}

