#include <iostream>

class Items
{

	

private: 
	std::string Id,title;
	enum Type{SelfHelp,Fiction, Non_Fiction,Science,SCI_Fi,CD,DVD};

	Type itemType;
public:

	 Items(std:: string ID, std::string title, Type itemType )
	{
		 this->Id = ID;
		 this->title = title;
		 this->itemType = itemType;
	}
};


class CD : public Items
{


};


class DVD : public Items
{

};

int main()
{

	std::cout << "We're going to create a library System yay!!!!";

}