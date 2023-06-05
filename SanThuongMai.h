#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "DanhMucHangHoa.h"

using namespace std;

class Item
{
private:
	string itemName;
	string itemType;
	float itemPrice;
	int numberOfItem;
public:
	Item();
	Item(const Item& mItem);
	~Item();

	void setItem(const Item& mItem);
	void setNumberOfItem(int number);
	int getNumberOfItem();
	float getItemPrice();
	string getItemName();
	string getItemType();

	void inputItem();
	void outputItem();
	void writeItemInFile(ostream& os);
	void readItemFromFile(istream& is);
};

class Shop
{
private:
	string shopName;
	string startDate;
	vector <Item*> listItems;
public: 
	Shop();
	Shop(const Shop& mShop);
	~Shop();
	
	void addItemInShop();
	void deleteItemFromShop();

	void inputItemsFromFile(const char* filePath);
	void printInfOfShop();
	void inputInforOfShop();

	Item* findItemByName(string mName);
	

	
};

class Category
{
private:
	Component* myCategory;
public:
	void inputCategory(const char* filePath);
	void displayCategory();
	
};

class Voucher
{
private: 
	string voucherName;
	string voucherType;
	float  percentDiscount;
	float  maxValueDiscount;
	string request;
public:
	Voucher();
	~Voucher();

	string getVoucherType();
	string getVoucherRequest();
	float getPercentDisCount();
	float getMaxValueDiscount();
	string getVoucherName();
	
	void readVoucherData(istream& is);
	void printVoucherData();
};

class BagItem
{
protected:
	vector <Item*> listItemInBag;
	int totalItem;
	float totalCost;
	float totalPaid;
	vector <Voucher*> applyVouchers;
public:
	BagItem();
	BagItem(const BagItem& myBag);
	~BagItem();

	void setBagItem(BagItem* myBag);
	int getTotalItem();

	void calcTotalItem();
	void calcTotalCost();
	void calcTotalPaid(float discount);
	
	void addItemInBag(Shop mShop);
	void deleteItemFromBag();
	void printMyBag();
	void checkVoucher(Voucher mVoucher, string mBirthday);
	void updateData();
	void deleteMyBag();
};

class Order: public BagItem
{
private:
	string orderCode;
	string dateOrder;
public:
	Order();
	Order(const Order& mOrder);
	~Order();

	float getTotalPaid();
	string getDateOrder();
	void setMyOrder(BagItem*& myBag);

	void printMyOder();
};

class Customer
{
private:
	string customerName;
	string customerEmail;
	string customerAddress;
	string customerSex;
	string customerBirthday;
	BagItem* myBag;
	vector <Order*> myOrder;
	vector <Voucher*> myVoucher;
	int rank; 
	float discount;
public:
	Customer();
	Customer(const Customer& myCustomer);
	~Customer();

	void signUp(); // checked
	void printCustomerData(); // checked
	void paid(Shop mShop);
	void addItemInBag(Shop* mShop);
	void deleteItemInBag();
	void seeItemBag();
	void addCustomerOrder(Order *mOrder);
	void printListOrder();

	void setDiscount();
	void setRank();
};

class SanThuongMai
{
private:
	Customer* mCustomer;
	Shop* mShop;
	Category* mCategory;
	vector <string> rating;
public:
	SanThuongMai();
	SanThuongMai(const SanThuongMai& mySTM);
	~SanThuongMai();
	void shopping();
	void customerRating();
	void printRating();
};

string intToString(int mInt);
string calcDateOder();
void Menu();