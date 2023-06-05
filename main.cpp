#include "SanThuongMai.h"
#include "DanhMucHangHoa.h"



int main()
{
	SanThuongMai* OO = new SanThuongMai;
	OO->shopping();
	delete OO;
	OO = NULL;

}