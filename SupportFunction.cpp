#include "SanThuongMai.h"

string intToString(int mInt)
{
	string tmpS, res = "\0";
	while (mInt != 0)
	{
		int tmp = mInt % 10;
		char tmp2 = (char)(tmp + 48);
		tmpS.push_back(tmp2);
		mInt = mInt / 10;
	}
	for (int i = tmpS.length() - 1; i >= 0; i--)
	{
		res.push_back(tmpS[i]);
	}
	return res;
}

// calculate the date order
string calcDateOder()
{
	string res = "\0";
	time_t now = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &now);
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	string tmp = intToString(day);
	res = res + tmp + " ";
	tmp = intToString(month);
	res = res + tmp;
	return res;
}

void Menu()
{
	cout << "1. Sign up" << endl;
	cout << "2. See information of shop" << endl;
	cout << "3. Add item in your bag" << endl;
	cout << "4. Delete item in your bag" << endl;
	cout << "5. See your item bag" << endl;
	cout << "6. Paid" << endl;
	cout << "7. Display category " << endl;
	cout << "8. See your information" << endl;
	cout << "9. Rating " << endl;
	cout << "10. See customer rating" << endl;
	cout << "11. Add item in shop" << endl;
	cout << "12. Delete item in shop" << endl;
	cout << "13. Exit" << endl;
}