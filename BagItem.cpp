#include "SanThuongMai.h"

// constructor - destructor
BagItem::BagItem()
{
	listItemInBag.resize(0);
	applyVouchers.resize(0);
	totalItem = totalCost = totalPaid = 0;
}

BagItem::BagItem(const BagItem& myBag)
{
	
	this->listItemInBag.resize(myBag.listItemInBag.size());
	for (int i = 0; i < listItemInBag.size(); i++)
	{
		this->listItemInBag[i] = new Item;
		this->listItemInBag[i] = myBag.listItemInBag[i];
	}

	this->applyVouchers.resize(myBag.applyVouchers.size());
	for (int i = 0; i < applyVouchers.size(); i++)
	{
		this->applyVouchers[i] = new Voucher;
		this->applyVouchers[i] = myBag.applyVouchers[i];
	}

	this->totalItem = myBag.totalItem;
	this->totalCost = myBag.totalCost;
	this->totalPaid = myBag.totalPaid;
	
}

BagItem::~BagItem()
{
	for (int i = 0; i < listItemInBag.size(); i++)
	{
		delete listItemInBag[i];
		listItemInBag[i] = NULL;
	}
	listItemInBag.resize(0);

	for (int i = 0; i < applyVouchers.size(); i++)
	{
		delete applyVouchers[i];
		applyVouchers[i] = NULL;
	}
	applyVouchers.resize(0);
}

// Getter - Setter
void BagItem::setBagItem(BagItem* myBag)
{
	this->listItemInBag.resize(myBag->listItemInBag.size());
	for (int i = 0; i < listItemInBag.size(); i++)
	{
		this->listItemInBag[i] = new Item;
		Item tmp = *myBag->listItemInBag[i];
		*this->listItemInBag[i] = tmp;
	}

	this->applyVouchers.resize(myBag->applyVouchers.size());
	for (int i = 0; i < applyVouchers.size(); i++)
	{
		*this->applyVouchers[i] = *myBag->applyVouchers[i];;
	}

	this->totalItem = myBag->totalItem;
	this->totalCost = myBag->totalCost;
	this->totalPaid = myBag->totalPaid;
}

int BagItem::getTotalItem()
{
	return totalItem;
}

// add an item from mShop in your bag by name and number of items
void BagItem::addItemInBag(Shop mShop)
{
	string name;
	int number;
	cout << "Enter name of item: ";
	getline(cin,name);
	Item * mItem = mShop.findItemByName(name);
	if (mItem == NULL)
	{
		cout << "This product is not exist" << endl;
		return;
	}
	else
	{
		int max = mItem->getNumberOfItem();
		do
		{
			cout << "Enter number of item: ";
			cin >> number;
			if (number > max)
			{
				cout << "Don't have enough product" << endl;
			}
		} while (number > max);
		mItem->setNumberOfItem(number);
	}
	int pos = listItemInBag.size();
	listItemInBag.resize(pos + 1);
	listItemInBag[pos] = new Item;
	*listItemInBag[pos] = *mItem;

}

// delete item from your bag by entering the name of item and number of this item is deleted 
void BagItem::deleteItemFromBag()
{
	if (listItemInBag.size() == 0)
	{
		cout << "Your bag is empty" << endl;
		return;
	}
	string tmp;

	cout << "Enter name of item deleted: ";
	getline(cin, tmp);
	for (int i = 0; i < listItemInBag.size(); i++)
	{
		if (listItemInBag[i]->getItemName() == tmp)
		{
			int max = listItemInBag[i]->getNumberOfItem();
			int number;
			do
			{
				cout << "Enter number of items deleted: ";
				cin >> number;
				if (number < max)
				{
					listItemInBag[i]->setNumberOfItem(max - number);
				}
				else if (number == max)
				{
					delete listItemInBag[i];
					listItemInBag[i] = NULL;
					listItemInBag.erase(listItemInBag.begin() + i);
				}
				else
				{
					cout << "Invalid number" << endl;
				}
			} while (number > max);
			return;
		}
		else
		{
			cout << "Don't have this item in your bag" << endl;
		}
	}
}

// check validity of voucher
void BagItem::checkVoucher(Voucher mVoucher, string mBirthday)
{
	string type = mVoucher.getVoucherType();
	if (type[type.length() - 1] == '2')
	{
		string cateItem = mVoucher.getVoucherRequest();
		float sum = 0;
		for (int i = 0; i < listItemInBag.size(); i++)
		{
			if (cateItem == listItemInBag[i]->getItemType())
			{
				//mVoucher.setVoucherStatus(true);
				float percent = mVoucher.getPercentDisCount();
				percent = 1.0*percent / 100;
				sum = sum + listItemInBag[i]->getItemPrice();
			}
		}
		if (sum != 0)
		{
			totalPaid = min(sum, mVoucher.getMaxValueDiscount());
		}
	}
	else if (type[type.length() - 1] == '3')
	{
		string today = calcDateOder();
		if (today == mBirthday)
		{
			float tmp;
			tmp = min(mVoucher.getMaxValueDiscount(), totalCost * (mVoucher.getPercentDisCount() / 100));
			totalPaid = totalCost - tmp;
		} 
	}
	else
	{
		float tmp;
		tmp = min(mVoucher.getMaxValueDiscount(), totalCost * (mVoucher.getPercentDisCount() / 100));
		totalPaid = totalCost - tmp;
	}
}

// calculate total number of items in your bag
void BagItem::calcTotalItem()
{
	totalItem = 0;
	for (int i = 0; i < listItemInBag.size(); i++)
	{
		totalItem = totalItem + listItemInBag[i]->getNumberOfItem();
	}
}

// calculate the total cost in your bag
void BagItem::calcTotalCost()
{
	totalCost = 0;
	for (int i = 0; i < listItemInBag.size(); i++)
	{
		totalCost = totalCost + listItemInBag[i]->getNumberOfItem()* listItemInBag[i]->getItemPrice();
	}
}

// set default total paid equal toal cost
void BagItem::calcTotalPaid(float discount)
{
	totalPaid = totalCost - totalCost*discount;
}

// print your bag item with information of item in it
void BagItem::printMyBag()
{
	if (listItemInBag.size() == 0)
	{
		cout << "Your bag is empty" << endl;
		return;
	}
	calcTotalItem();
	cout << "Total items in your bag: " << totalItem << endl;
	cout << "Total cost: " << totalCost << endl;
	for (int i = 0; i < listItemInBag.size(); i++)
	{
		listItemInBag[i]->outputItem();
	}
	cout << "Total paid: " << totalPaid << endl;
}

// update data of items after customer paid
void BagItem::updateData()
{
	vector <Item*> tmpList;
	ifstream fi;
	ofstream fo;
	int numberItem_S; // number of items in shop
	fi.open("Input.txt");
	fi >> numberItem_S;
	tmpList.resize(numberItem_S);
	for (int i = 0; i < numberItem_S; i++)
	{
		tmpList[i] = new Item;
		tmpList[i]->readItemFromFile(fi);
		fi.ignore();
	}
	fi.close();

	for (int i = 0; i < tmpList.size(); i++)
	{
		int tmpNumber = tmpList[i]->getNumberOfItem();
		for (int j = 0; j < listItemInBag.size(); j++)
		{
			if (this->listItemInBag[j]->getItemName() == tmpList[i]->getItemName())
			{
				int check = tmpNumber - listItemInBag[j]->getNumberOfItem();
				if (check != 0)
				{
					tmpList[i]->setNumberOfItem(check);
				}
				else
				{
					delete tmpList[i];
					tmpList[i] = NULL;
					tmpList.erase(tmpList.begin() + i);
				}
				break;
			}
		}
		
	}

	fo.open("input.txt", ios::ate);
	fo << tmpList.size() << endl;
	for (int i = 0; i < tmpList.size(); i++)
	{
		tmpList[i]->writeItemInFile(fo);
		fo << endl;
	}
	fo.close();
}

void BagItem::deleteMyBag()
{
	for (int i = 0; i < listItemInBag.size(); i++)
	{
		delete listItemInBag[i];
		listItemInBag[i] = NULL;
	}
	listItemInBag.resize(0);
	totalItem = 0;
	totalCost = 0;
	totalPaid = 0;

}
