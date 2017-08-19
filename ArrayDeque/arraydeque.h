/*
 * filename:arraydeque.h
 * created at:2017-08-19
 * author:VincentHwuang
 */

#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

#include"array.h"
#include"utils.h"

using namespace std;
using namespace Array;
using namespace Utility;

namespace ArrayDeque
{
template<typename T>
class CArrayDeque
{
	protected:
		CArray<T> Array;
		int       IndexFlag;
		int       Count;
		void      Resize();
	public:
		CArrayDeque();
		virtual ~CArrayDeque();
		//Method to get the actual size
		int Size();
		//Method to get an element without removing it
		T Get(int Index);
		//Method to enqueue an element at the end
		virtual void EnqueueE(T NewElem);
		//Method to enqueue an element at the first
		virtual void EnqueueF(T NewElem);
		void PrintInfo();
};

template<typename T>
CArrayDeque<T>::CArrayDeque() : Array(1)
{
	IndexFlag=0;
	Count=0;
}

template<typename T>
CArrayDeque<T>::~CArrayDeque()
{
}

template<typename T> inline 
int CArrayDeque<T>::Size()
{
	return Count;
}

template<typename T> inline 
T CArrayDeque<T>::Get(int Index)
{
	return Array[(IndexFlag+Index)%(Array.Length)];
}

template<typename T>
void CArrayDeque<T>::Resize()
{
	CArray<T> Temp(Max(1,2*Count));
	for(int i=0;i<Count;i++)
	{
		Temp[i]=Array[(IndexFlag+i)%(Array.Length)];
	}
	Array=Temp;
	IndexFlag=0;
}

template<typename T>
void CArrayDeque<T>::EnqueueE(T NewElem)
{
	//If the queue is full,resize it
	if(Count+1 > Array.Length)
	{
		Resize();
	}
	Array[(IndexFlag+Count)%(Array.Length)]=NewElem;
	Count++;
}

template<typename T>
void CArrayDeque<T>::EnqueueF(T NewElem)
{
	//If the queue is full,resize it
	if(Count+1 > Array.Length)
	{
		Resize();
	}
	IndexFlag=(IndexFlag==0)? (Array.Length-1):(IndexFlag-1);
	Array[IndexFlag]=NewElem;
	Count++;
}

template<typename T>
void CArrayDeque<T>::PrintInfo()
{
	Array.PrintInfo();
	std::cout<<"IndexFlag:"<<IndexFlag<<std::endl<<"Count:"<<Count<<std::endl;
}

}

#endif
