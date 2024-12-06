#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Items {
protected:
   
    int id;
    string title;
  
    bool isAvailable;

public:
    enum ITEM_TYPE { CD, DVD };
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

    CD cd1(122, "Classical Music", Items::ITEM_TYPE::CD, Items::CONTENT_TYPE :: Music);
    cd1.displayDetails();

 
    DVD dvd1(456, "Science Documentary", Items::ITEM_TYPE::DVD, Items::CONTENT_TYPE::Science );
    dvd1.displayDetails();

  
    ifstream accountFiles("accounts.txt");

    if (!accountFiles.is_open()) {
        cout << "This file could not be opened" << endl;
        return 1;
    }

    string readFile;
    while (getline(accountFiles, readFile)) {
        cout << readFile << endl;
    }

    accountFiles.close();

    return 0;
}
