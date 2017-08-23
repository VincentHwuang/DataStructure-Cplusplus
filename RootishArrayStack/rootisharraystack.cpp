/*
 * filename:rootisharraystack.cpp
 * created at:2017-08-23
 * author:VincentHwuang
 */

#include"rootisharraystack.h"

namespace RootishArrayStack
{
	template CRootishArrayStack<int>::CRootishArrayStack();
	template CRootishArrayStack<int>::~CRootishArrayStack();
	template void CRootishArrayStack<int>::Add(int,int);
	template void CRootishArrayStack<int>::Grow();
}
