#include "SanThuongMai.h"

// constructor - destructor
Shop::Shop()
{
	shopName = '\0';
	startDate = '\0';
	listItems.resize(0);
}

Shop::Shop(const Shop& mShop)
{
	this->shopName = mShop.shopName;
	this->startDate = mShop.startDate;
	this->listItems.resize(mShop.listItems.size());
	for (int i = 0; i < this->listItems.size(); i++)
	{
		this->listItems[i] = new Item;
		this->listItems[i] = mShop.listItems[i];
	}
}

Shop::~Shop()
{
	shopName.clear();
	startDate.clear();
	for (int i = 0; i < listItems.size(); i++)
	{
		delete listItems[i];
		listItems[i] = NULL;
	}
	listItems.resize(0);
}

// add new item from console in list item of shop - checked
void Shop::addItemInShop()
{
	Item* tmp = new Item;
	tmp->inputItem();
	listItems.push_back(tmp);
	ofstream fo;
	fo.open("input.txt", ios::ate);
	fo << listItems.size() << endl;
	for (int i = 0; i < listItems.size(); i++)
	{
		listItems[i]->writeItemInFile(fo);
		fo << endl;
	}
	fo.close();
	

}

// delete item from shop by name of item - checked
void Shop::deleteItemFromShop()
{
	string tmp;
	cout << "Enter name of item is deleted: ";
	getline(cin, tmp);
	for (int i = 0; i < listItems.size(); i++)
	{
		if (listItems[i]->getItemName() == tmp)
		{
			delete listItems[i];
			listItems[i] = NULL;
			listItems.erase(listItems.begin() + i);
		}
	}
	ofstream fo;
	fo.open("input.txt", ios::ate);
	fo << listItems.size() << endl;
	for (int i = 0; i < listItems.size(); i++)
	{
		listItems[i]->writeItemInFile(fo);
		fo << endl;
	}
	fo.close();
	//cout << "Don't have this item in shop";
}

// input list of item of a shop via file txt - checked
void Shop::inputItemsFromFile(const char* filePath)
{
	string tmp;
	ifstream fi;
	int numberItem_S; // number of items in shop
	fi.open(filePath);
	fi >> numberItem_S;
	listItems.resize(numberItem_S);
	for (int i = 0; i < numberItem_S; i++)
	{
		listItems[i] = new Item;
		listItems[i]->readItemFromFile(fi);
		fi.ignore();
	}
	fi.ignore();
	fi >> tmp;
	fi.close();
}

// print information of a shop on console - checked
void Shop::printInfOfShop()
{
	cout << "Name of shop: " << shopName << endl;
	cout << "Date of joining in: " << startDate << endl;
	cout << endl;
	cout << "List of items in shop" << endl;
	for (int i = 0; i < listItems.size(); i++)
	{
		listItems[i]->outputItem();
		cout << endl;
	}

}

// input information of shop include: Name and Date joined in - checked
void Shop::inputInforOfShop()
{
	cout << "Name of shop: ";
	getline(cin, shopName);
	cout << "Date of joining in: ";
	getline(cin, startDate);
}

// return an item with "mName" in shop
Item* Shop::findItemByName(string mName)
{
	for (int i = 0; i < listItems.size(); i++)
	{
		if (mName == listItems[i]->getItemName())
		{
			return listItems[i];
		}
	} 
	return NULL;
}

