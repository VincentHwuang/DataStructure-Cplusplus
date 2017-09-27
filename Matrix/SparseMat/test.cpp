#include"sparsemat.h"

using ds::CSparseMat;

int main(void)
{
	int SparseMat0[3][4]=
	{
		{3, 1,0,5 }, 
		{0,-1,0,0 }, 
		{2, 0,0,0 }, 
	};
	int SparseMat1[4][2]=
	{
		{ 9,2},
		{ 1,0},
		{-2,4},
		{ 0,0},
	};
	CSparseMat<int> SparseMatrix0{3,4,(int*)SparseMat0};
	CSparseMat<int> SparseMatrix1{4,2,(int*)SparseMat1};
	SparseMatrix0.PrintInfo();
	SparseMatrix1.PrintInfo();
	SparseMatrix0=SparseMatrix0*SparseMatrix1;
	SparseMatrix0.PrintInfo();

//	CSparseMat<int> SparseMat1{SparseMat.Transpose()};
//	SparseMat1.PrintInfo();
//	SparseMat.Transpose();
//	SparseMat.PrintInfo();

	return 0;
}
