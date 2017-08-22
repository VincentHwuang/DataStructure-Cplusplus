/*
 * filename:dualarraydeque.cpp
 * created at:2017-08-21
 * author:VincentHwuang
 */


#include"dualarraydeque.h"
#include"utils.h"

using DualArrayDeque::CDualArrayDeque;

namespace DualArrayDeque
{
	template CDualArrayDeque<int>::CDualArrayDeque();
	template CDualArrayDeque<int>::~CDualArrayDeque();
	template int CDualArrayDeque<int>::Get(int);
	template int CDualArrayDeque<int>::Set(int,int);
	template void CDualArrayDeque<int>::Add(int,int);
	template int CDualArrayDeque<int>::Remove(int);
	template int CDualArrayDeque<int>::Size();
}
