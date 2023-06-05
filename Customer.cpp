#include "SanThuongMai.h"

// constructor - destructor
Customer::Customer()
{
	customerName = "\0";
	customerEmail = "\0";
	customerAddress = "\0";
	customerSex = "\0";
	customerBirthday = "\0";
	myBag = new BagItem;
	myOrder.resize(0);
	myVoucher.resize(0);
	rank = 0;
	discount = 0;
}

Customer::Customer(const Customer& myCustomer)
{
	this->customerName = myCustomer.customerName;
	this->customerEmail = myCustomer.customerEmail;
	this->customerAddress = myCustomer.customerAddress;
	this->customerSex = myCustomer.customerSex;
	this->customerBirthday = myCustomer.customerBirthday;

	this->myVoucher.resize(myCustomer.myVoucher.size());
	for(int i=0; i<this->myVoucher.size(); i++)
	{
		this->myVoucher[i] = new Voucher;
		this->myVoucher[i] = myCustomer.myVoucher[i];
	}

	this->myOrder.resize(myCustomer.myOrder.size());
	for (int i = 0; i < this->myOrder.size(); i++)
	{
		this->myOrder[i] = new Order;
		this->myOrder[i] = myCustomer.myOrder[i];
	}

	this->myBag = new BagItem;
	this->myBag = myCustomer.myBag;

	this->discount = myCustomer.discount;
	this->rank = myCustomer.rank;
}

Customer::~Customer()
{
	delete myBag;
	myBag = NULL;

	for (int i = 0; i < this->myVoucher.size(); i++)
	{
		delete myVoucher[i];
		myVoucher[i] = NULL;
		myVoucher.erase(myVoucher.begin() + i);
	}
	myVoucher.resize(0);

	for (int i = 0; i < this->myOrder.size(); i++)
	{
		delete myOrder[i];
		myOrder[i] = NULL;
		myOrder.erase(myOrder.begin() + i);
	}
	myOrder.resize(0);

	rank = 0;
	discount = 0;

	customerName.clear();
	customerEmail.clear();
	customerAddress.clear();
	customerSex.clear();
	customerBirthday.clear();


}

// Getter - Setter
void Customer::setDiscount()
{
	switch (rank)
	{
	case 0:
		discount = 0;
		break;
	case 1:
		discount = 0.01;
		break;
	case 2:
		discount = 0.02;
		break;
	default:
		discount = 0.04;
		break;
	}
}

void Customer::setRank()
{
	float total = 0;
	for (int i = 0; i < myOrder.size(); i++)
	{
		total = total + myOrder[i]->getTotalPaid();
	}
	if (total >= 10000000)
	{
		rank = 1;
	}
	else if (total >= 50000000)
	{
		rank = 2;
	}
	else if (total >= 200000000)
	{
		rank = 3;
	}
	else rank = 0;
}

// sign up for customer to enter information
void Customer::signUp()
{
	cout << "Your name: ";
	getline(cin, customerName);
	cout << "Your email address: ";
	cin >> customerEmail;
	cin.ignore();
	cout << "Your address: ";
	getline(cin, customerAddress);
	cout << "Sex: ";
	cin >> customerSex;
	cin.ignore();
	cout << "Your date of birth: ";
	getline(cin, customerBirthday);
	cout << "Sign up successfully" << endl;

};

// print data of customer
void Customer::printCustomerData()
{
	cout << "Your name: " << customerName << endl;
	cout << "Your email address: " << customerEmail << endl;
	cout << "Your address: " << customerAddress << endl;
	cout << "Sex: " << customerSex << endl;
	cout << "Your date of birth: " << customerBirthday << endl;
	cout << "Your rank: ";
	switch (rank)
	{
	case 0:
		cout << "Non" << endl;
		break;
	case 1:
		cout << "Bronze" << endl;
		break;
	case 2:
		cout << "Silver" << endl;
		break;
	default:
		cout << "Gold" << endl;
		break;
	}
	myBag->printMyBag();
	cout << endl;
	for (int i = 0; i < myOrder.size(); i++)
	{
		myOrder[i]->printMyOder();
		cout << endl;
	}
}

// paid and print order on console
void Customer::paid(Shop mShop)
{

	if (myBag->getTotalItem() == 0)
	{
		cout << "Your bag is emty" << endl;
		return;
	} 
	string code;
	cout << "Enter voucher code: ";
	getline(cin, code);
	int pos = -1;
	// just apply only one voucher
	for (int i = 0; i < myVoucher.size(); i++)
	{
		if (code == myVoucher[i]->getVoucherName())
		{
			pos = i;
			break;
		}
	} 
	if (pos != -1)
	{
		myBag->calcTotalItem();
		myBag->calcTotalCost();
		myBag->calcTotalPaid(discount);
		myBag->checkVoucher(*myVoucher[pos],customerBirthday);
	}
	else
	{
		myBag->calcTotalItem();
		myBag->calcTotalCost();
		myBag->calcTotalPaid(discount);
	}

	// print list of order
	Order* mOrder = new Order;
	mOrder->setMyOrder(myBag);
	addCustomerOrder(mOrder);
	printListOrder();

	myBag->updateData();
	// refresh your item bag
	myBag->deleteMyBag();
	// update customer rank and their discount
	setRank();
	setDiscount();
}

// customers add an item in their bag
void Customer::addItemInBag(Shop* mShop)
{
	myBag->addItemInBag(*mShop);
	myBag->calcTotalItem();
	myBag->calcTotalCost();
	myBag->calcTotalPaid(discount);
}

// customers delete an item from their bag
void Customer::deleteItemInBag()
{
	myBag->deleteItemFromBag();
	myBag->calcTotalItem();
	myBag->calcTotalCost();
	myBag->calcTotalPaid(discount);
}

// print all items data in customer's bag
void Customer::seeItemBag()
{
	myBag->calcTotalItem();
	myBag->calcTotalCost();
	myBag->calcTotalPaid(discount);
	myBag->printMyBag();
}

// add new order in list order of customer
void Customer::addCustomerOrder(Order* mOrder)
{
	int size = myOrder.size();
	myOrder.resize(size + 1);
	myOrder[size] = new Order;
	*myOrder[size] = *mOrder;
}

// print list of customer's order
void Customer::printListOrder()
{
	for (int i = 0; i < myOrder.size(); i++)
	{
		myOrder[i]->printMyOder();
		cout << endl;
	}
}


