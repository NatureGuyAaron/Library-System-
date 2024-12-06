#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class: Item
class Item {
protected:
    string id;
    string title;
    string type;  // Can be "Book", "CD", "DVD"
    bool isAvailable;

public:
    // Constructor
    Item(string id, string title, string type, bool isAvailable = true)
        : id(id), title(title), type(type), isAvailable(isAvailable) {
    }

    // Pure virtual function to display item details
    virtual void displayDetails() const = 0;

    // Getters and Setters
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getType() const { return type; }
    bool getAvailability() const { return isAvailable; }

    void setAvailability(bool status) { isAvailable = status; }

    // Virtual destructor
    virtual ~Item() {}
};
 