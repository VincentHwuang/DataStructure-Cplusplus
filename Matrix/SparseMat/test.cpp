#include"sparsemat.h"

using ds::CSparseMat;

int main(void)
{
	int Elems[4][3]=
	{
		{1,2,3}, 
		{0,4,0}, 
		{5,6,0}, 
		{0,0,7}
	};
	CSparseMat<int> SparseMat{4,3,(int*)Elems};
//	SparseMat.PrintInfo();
	CSparseMat<int> SparseMat1{SparseMat.Transpose()};
	SparseMat1.PrintInfo();
//	SparseMat.Transpose();
//	SparseMat.PrintInfo();

	return 0;
}
