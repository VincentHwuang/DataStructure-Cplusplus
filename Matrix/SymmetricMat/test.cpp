#include"symmetricmat.h"

using ds::CSymmetricMat;

int main(void)
{
	int test[5][5]=
	{
		{1,2,3,4, 5},
		{2,6,7, 8, 9},
		{3,7,10,11,12},
		{4,8,11,13,14},
		{5,9,12,14,15}
	};
	CSymmetricMat<int> SymMat((int*)test,5);
	SymMat.PrintInfo();

	return 0;
}
