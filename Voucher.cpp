#include "SanThuongMai.h"

// constructor - destructor
Voucher::Voucher()
{
	voucherName = "\0";
	voucherType = "\0";
	percentDiscount = 0.0;
	maxValueDiscount = 0.0;
	request = "\0";
}

Voucher::~Voucher()
{
	voucherName.clear();
	voucherType.clear();
	percentDiscount=0.0;
	maxValueDiscount=0.0;
	request.clear();

}

// Getter - Setter
string Voucher:: getVoucherRequest()
{
	return request;
}

float Voucher::getPercentDisCount()
{
	return percentDiscount;
}

float Voucher::getMaxValueDiscount()
{
	return maxValueDiscount;
}

string Voucher::getVoucherName()
{
	return this->voucherName;
}

string Voucher::getVoucherType()
{
	return voucherType;
}

// read data of voucher via file txt
void Voucher::readVoucherData(istream& is)
{
	getline(is, voucherName);
	is >> voucherType;
	is >> percentDiscount;
	is >> maxValueDiscount;
	is.ignore();
	getline(is, request);
}

// print data of voucher on console
void Voucher::printVoucherData()
{
	cout << voucherName << endl;
	cout << voucherType << endl;
	cout << percentDiscount << "%" << endl;
	cout << maxValueDiscount << endl;
	cout << request << endl;
}