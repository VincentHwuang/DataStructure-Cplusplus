/*
 * test.cpp
 * created at:2017-08-14
 * author:VincentHwuang
 * description:this is a test file used to test the implementions by the data structures
 */

#include"array.h"

using DataStructure::CArray;

int main(int argc,char **argv)
{
	//Test for construct functions
	CArray<int> ArrayA{5,10};
	CArray<int> ArrayB{6};
//	ArrayA.PrintInfo();
//	ArrayB.PrintInfo();
	//Test for 'operator[]' function
//	int Value0;
//	int Value1;
//	Value0=ArrayA[0];
//	Value1=ArrayB[2];
	//Test for 'operator=' function
//	ArrayA=ArrayB;
//	ArrayA.PrintInfo();
	//Test for 'Fill()' function
//	ArrayA.Fill(15);
//	ArrayA.PrintInfo();
	//Test for 'operator+' function
//	int *pCarrier;
//	pCarrier=ArrayA+3;
//	ArrayA.PrintInfo();
//	std::cout<<"The address pCarrier points to is:"<<pCarrier<<std::endl<<"The value it points to is:"<<*pCarrier<<std::endl;
	//Test for 'SetValue()' function
//	ArrayA.SetValue(1,20);
//	ArrayA.PrintInfo();
	//Test for 'swap()' function
//	ArrayA.swap(0,1);
//	ArrayA.PrintInfo();
	//Test for 'Reverse()' function
	int Length=ArrayA.Length;
	for(int i=0;i<Length;i++)
	{
		ArrayA.SetValue(i,i);
	}
	ArrayA.Reverse();
	ArrayA.PrintInfo();


	return 0;
}
