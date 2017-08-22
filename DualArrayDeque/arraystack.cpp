/*
 * arraystack.cpp
 * created at:2017-08-17
 * author:VincentHwuang
 */

#include"arraystack.h"
#include"utils.h"

namespace ArrayStack
{
	//Explicit instantiation
	template CArrayStack<int>::CArrayStack();
	template CArrayStack<int>::~CArrayStack();
	template void CArrayStack<int>::Add(int,int);
	template int  CArrayStack<int>::Remove(int);

	template CArrayStack<int*>::CArrayStack();
	template CArrayStack<int*>::~CArrayStack();
	template void CArrayStack<int*>::Add(int,int*);
	template int* CArrayStack<int*>::Remove(int);
}
