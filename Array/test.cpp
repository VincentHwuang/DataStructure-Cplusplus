/*
 * test.cpp
 * created at:2017-08-14
 * author:VincentHwuang
 * description:this is a test file used to test the implementions by the data structures
 */

#include"array.h"

using Array::CArray;

int main(int argc,char **argv)
{
	//Test for construct functions
	CArray<int> ArrayA{5,10};
	CArray<int> ArrayB{6};
//	ArrayA.PrintInfo();
//	ArrayB.PrintInfo();
	//Test for 'operator[]' function
//	ArrayA.SetValue(0,100);
//	ArrayA.SetValue(2,101);
//	int Value0;
//	int Value1;
//	Value0=ArrayA[0];
//	Value1=ArrayA[2];
//	std::cout<<"Value0:"<<Value0<<std::endl<<"Value1:"<<Value1<<std::endl;
	//Test for 'operator=' function
//	ArrayA.PrintInfo();
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
//    //Test for 'swap()' function
//	ArrayA.swap(0,1);
//	ArrayA.PrintInfo();
	//Test for 'Reverse()' function
	int Length=ArrayA.Length;
	for(int i=0;i<Length;i++)
	{
		ArrayA.SetValue(i,i);
	}
//	ArrayA.PrintInfo();
//	ArrayA.Reverse();
//	ArrayA.PrintInfo();
	ArrayA.PrintInfo();
	ArrayB.PrintInfo();
	ArrayB.CopyOfRange(ArrayA,0,Length-1);
	ArrayB.PrintInfo();


	return 0;
}
