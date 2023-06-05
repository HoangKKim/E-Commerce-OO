#include "SanThuongMai.h"
#include "DanhMucHangHoa.h"

// read data of category from file txt
void Category::inputCategory(const char* filePath)
{
	fstream fi;
	fi.open(filePath);
	myCategory = new Composite;
	myCategory->input(fi);
}

void Category::displayCategory()
{
	myCategory->display(0);
}
