#include "DanhMucHangHoa.h"
#include "SanThuongMai.h"

// constructor - destructor
SanThuongMai::SanThuongMai()
{
	mShop = new Shop;
	mCustomer = new Customer;
	mCategory = new Category;
	rating.resize(0);
}

SanThuongMai::SanThuongMai(const SanThuongMai& mSTM)
{
	this->mShop = new Shop;
	this->mCustomer = new Customer;
	this->mCategory = new Category;
	this->mShop = mSTM.mShop;
	this->mCustomer = mSTM.mCustomer;
	this->mCategory = mSTM.mCategory;
}

SanThuongMai::~SanThuongMai()
{
	delete mCustomer;
	delete mShop;
	delete mCategory;
	mCategory = NULL;
	mCustomer = NULL;
	mShop = NULL;
}

// rating of customer
void SanThuongMai::customerRating()
{
	string tmp;
	cout << "Your rating: ";
	getline(cin, tmp);
	rating.push_back(tmp);
}

void SanThuongMai::printRating()
{
	for (int i = 0; i < rating.size(); i++)
	{
		cout << rating[i] << endl;
	}
}

// Shopping
void SanThuongMai::shopping()
{
	// input items data of shop
	mShop->inputInforOfShop();
	mCategory->inputCategory("DanhMucSanPham.txt");
	string cont;
	int choice;
	do
	{
		Menu();
		mShop->inputItemsFromFile("input.txt");
		cout << "Your number of choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			system("cls");
			mCustomer->signUp();
			break;
		case 2:
			system("cls");
			mShop->printInfOfShop();
			break;
		case 3:
			system("cls");
			mCustomer->addItemInBag(mShop);
			break;
		case 4:
			system("cls");
			mCustomer->deleteItemInBag();
			break;
		case 5:
			system("cls");
			mCustomer->seeItemBag();
			break;
		case 6:
			system("cls");
			mCustomer->paid(*mShop);
			break;
		case 7: 
			system("cls");
			mCategory->displayCategory();
			break;
		case 8:
			system("cls");
			mCustomer->printCustomerData();
			break;
		case 9: 
			system("cls");
			customerRating();
			break;
		case 10: 
			system("cls");
			printRating();
			break;
		case 11:
			system("cls");
			mShop->addItemInShop();
			break;
		case 12:
			system("cls");
			mShop->deleteItemFromShop();
			break;
		default:
			return;
		}
		cout << "Continued shopping: ";
		cin >> cont;
		system("cls");
	} while (cont=="yes");
}