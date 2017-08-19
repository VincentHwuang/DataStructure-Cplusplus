/*
 * filename:arrayqueue.h
 * created at:2017-08-18
 * author:VincentHwuang
 */

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include"array.h"
#include"utils.h"

using namespace Array;
using namespace Utility;

namespace ArrayQueue
{
template<typename T>
class CArrayQueue
{
	protected:
		CArray<T> Array;
		int       IndexFlag;//Record index of the last element
		int       Count;	//Number of total elements in the queue
		//Method to resize the queue in case it is too big or small 
		void      Resize();
	public:
		CArrayQueue();
		virtual ~CArrayQueue();
		//Method to enqueue an element
		virtual bool Enqueue(T NewElem);
		void PrintInfo();
		//Method to dequeue an element
		virtual T Dequeue();
		//Method to get the size
		int Size();

};

template<typename T>
CArrayQueue<T>::CArrayQueue() : Array(1)
{
	Count=0;
	IndexFlag=0;
}

template<typename T>
CArrayQueue<T>::~CArrayQueue()
{
//	delete Array;
}

template<typename T>
void CArrayQueue<T>::Resize()
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
bool CArrayQueue<T>::Enqueue(T NewElem)
{
	//If the queue has been full,resize it
	if(Count+1 > Array.Length)
	{
		Resize();
	}

	Array[(IndexFlag+Count)%(Array.Length)]=NewElem;
	Count++;

	return true;
}

template<typename T>
void CArrayQueue<T>::PrintInfo()
{
	std::cout<<"[CArrayQueue]:"<<std::endl;
	Array.PrintInfo();
	std::cout<<"'IndexFlag':"<<IndexFlag<<std::endl<<"'Count'"<<Count<<std::endl;
}

template<typename T>
T CArrayQueue<T>::Dequeue()
{
	T Temp;
	Temp=Array[IndexFlag];
	IndexFlag=(IndexFlag+1)%(Array.Length);
	Count--;

	//If the queue is too big,resize it
	if(Array.Length > 3*Count)
	{
		Resize();
	}

	return Temp;
}

template<typename T> inline
int CArrayQueue<T>::Size() 
{
	return Count;
}


}

#endif
