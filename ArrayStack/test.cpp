/*
 * arraystacktest.cpp
 * created at:2017-08-17
 * author:VincentHwuang
 * description:this is a test file used to test the implementions by the data structures
 */

#include"arraystack.h"

using ArrayStack::CArrayStack;

int main(int argc,char **argv)
{
	CArrayStack<int> ArrayStackA;
//	ArrayStackA.PrintInfo();
	//Test for 	'Add()'
	for(int i=0;i<5;i++)
	{
		ArrayStackA.Add(i,i);
	}
//	ArrayStackA.Add(4,100);
	//Test for 'Get()'
//	std::cout<<ArrayStackA.Get(4)<<std::endl;
	//Test for 'Set()'
//	ArrayStackA.Set(4,1234);
	//Test for 'Size()'
//	std::cout<<"The size:"<<ArrayStackA.Size()<<std::endl;
	//Test for 'Push()'
//	ArrayStackA.Push(4321);
	//Test for 'Remove()'
//	ArrayStackA.PrintInfo();
//	int BackCarrier=ArrayStackA.Remove(1);
//	ArrayStackA.PrintInfo();
//	std::cout<<BackCarrier<<std::endl;
	//Test for 'Clear()'
//	ArrayStackA.PrintInfo();
	ArrayStackA.Clear();
	ArrayStackA.PrintInfo();
	




	return 0;
}
