#include"matrix.h"

using ds::CMatrix;

int main(void)
{
	CMatrix<int> Matrix{2,2,2};
	//Test for method 'SetValue()'
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			Matrix.SetValue(i+j,i,j);
		}
	}
	//Test for method 'GetValue()'
	int BackCarrier{};
	Matrix.GetValue(BackCarrier,1,1);
	std::cout<<BackCarrier<<std::endl;

//	Matrix.PrintInfo();


}
