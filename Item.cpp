#include "SanThuongMai.h"

// constructor - destructor
Item::Item()
{
	itemName = '\0';
	itemType = '\0';
	itemPrice = 0;
	numberOfItem = 0;
}

Item::Item(const Item& mItem)
{
	this->itemName = mItem.itemName;
	this->itemType = mItem.itemType;
	this->itemPrice = mItem.itemPrice;
	this->numberOfItem = mItem.numberOfItem;

}

Item::~Item()
{
	itemName.clear();
	itemType.clear();
	itemPrice = 0;
	numberOfItem = 0;
}

// getter - setter for item
void Item::setItem(const Item& mItem)
{
	this->itemName = mItem.itemName;
	this->itemType = mItem.itemType;
	this->itemPrice = mItem.itemPrice;
	this->numberOfItem = mItem.numberOfItem;
}

int Item::getNumberOfItem()
{
	return this->numberOfItem;
}

void Item::setNumberOfItem(int number)
{
	this->numberOfItem = number;
}

string Item::getItemName()
{
	return this->itemName;
}

float Item::getItemPrice()
{
	return this->itemPrice;
}

string Item::getItemType()
{
	return itemType;
}

// input new item from console - checked 
void Item::inputItem()
{
	string tmp;
	cout << "Name of item: ";
	getline(cin, itemName);
	// check the length of name's item
	if (itemName.length() > 100)
	{
		itemName.erase(itemName.at(100), itemName.length()-1);
	}
	cout << "Category of item: ";
	getline(cin, itemType);
	cout << "Price of item: ";
	cin >> itemPrice;
	cout << "Number of items in store: ";
	cin >> numberOfItem;
}

// print data of item on console
void Item::outputItem()
{
	cout << "Name of item: " << itemName << endl;
	cout << "Category of item: " << itemType << endl;
	cout << "Price of item: " << itemPrice << endl;
	cout << "Number of item in shop: " << numberOfItem << endl;
}

// write data of item in file text
void Item::writeItemInFile(ostream& os)
{
	os << itemName << endl;
	os << itemType << endl;
	os << itemPrice << endl;
	os << numberOfItem << endl;
}

// read information of item via file txt - checked
void Item::readItemFromFile(istream& is)
{
	is.ignore();
	getline(is, itemName);
	getline(is, itemType);
	is >> itemPrice;
	is >> numberOfItem;
}

