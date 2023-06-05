#include "SanThuongMai.h"

// constructor - destructor
Order::Order() : BagItem()
{
	orderCode = "MYSHOP";
	dateOrder= "\0";
}

Order::Order(const Order& mOrder) : BagItem(mOrder)
{
	this->orderCode = mOrder.orderCode;
	this->dateOrder = mOrder.dateOrder;
}

Order::~Order()
{
	BagItem::~BagItem();
	orderCode.clear();
	dateOrder.clear();
	dateOrder.clear();
}

// Getter - setter
void Order::setMyOrder(BagItem*& myBag)
{
	setBagItem(myBag);
	dateOrder = calcDateOder();
}

float Order::getTotalPaid()
{
	return totalPaid;
}

string Order::getDateOrder()
{
	return dateOrder;
}

// print data of order
void Order::printMyOder()
{
	cout << "Name of your oder: " << orderCode << endl;
	printMyBag();
	cout << "Date order: ";
	cout << dateOrder << endl;
	// tong thanh toan

	
}

