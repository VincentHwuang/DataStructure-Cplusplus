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

namespace ds 
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
		//Method to add an element at specified location
		void Add(int Index,T NewElem);
		//Method to remove an element of specified location and return its payload
		T Remove(int Index);
		//Method to enqueue an element at the end
		virtual void EnqueueE(T NewElem);
		//Method to enqueue an element at the first
		virtual void EnqueueF(T NewElem);
		//Method to dequeue an element at the first
		virtual T DequeueF();
		//Method to dequeue an element at the end
		virtual T DequeueE();
		//Method to set element of specified location
		//and return its original value
		T Set(int Index,T NewElem);
		//Method to clear the deque
		virtual void Clear();

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
void CArrayDeque<T>::Add(int Index,T NewElem)
{
	//If the queue is full,resize it
	if((Count+1) > Array.Length)
	{
		Resize();
	}
	if(Index < Count/2)//Shift Array[IndexFlag%(Array.Length)],...,Array[(IndexFlag+Index-1)%(Array.Length)] left one position
	{
		IndexFlag= (IndexFlag==0)? (Array.Length-1):(IndexFlag-1);
		for(int i=0;i<=Index-1;i++)
		{
			Array[(IndexFlag+i)%(Array.Length)]=Array[(IndexFlag+i+1)%(Array.Length)];
		}
	}
	else			//Shift Array[Index%(Array.Length)],...,Array[(IndexFlag+Count-1)%(Array.Length)] right one position
	{
		for(int i=Count;i>Index;i--)
		{
			Array[(IndexFlag+i)%(Array.Length)]=Array[(IndexFlag+i-1)%(Array.Length)];
		}
	}
	Array[(IndexFlag+Index)%(Array.Length)]=NewElem;
	Count++;
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
T CArrayDeque<T>::Set(int Index,T NewElem)
{
	//Check if the index is valid
	assert(Index>=0 && Index<Count);

	T Temp=Array[(IndexFlag+Index)%(Array.Length)];
	Array[(IndexFlag+Index)%(Array.Length)]=NewElem;

	return Temp;
}

template<typename T>
void CArrayDeque<T>::Clear()
{
	CArray<T> Temp{1,0};
	Array=Temp;
	IndexFlag=0;
	Count=0;
}

template<typename T>
T CArrayDeque<T>::DequeueF()
{
	T Temp=Array[IndexFlag];
	IndexFlag=(IndexFlag+1)%(Array.Length);
	Count--;

	return Temp;
}

template<typename T>
T CArrayDeque<T>::DequeueE()
{
	T Temp=Array[(IndexFlag+Count-1)%(Array.Length)];
	Count--;

	return Temp;
}

template<typename T>
T CArrayDeque<T>::Remove(int Index)
{
	T Temp=Array[(IndexFlag+Index)%(Array.Length)];

	if(Index < Count/2)//Shift Array[(IndexFlag)%(Array.Length)],...,Array[(IndexFlag+Index-1)%(Array.Length)] right one position
	{
		for(int i=Index;i>0;i--)
		{
			Array[(IndexFlag+Index)%(Array.Length)]=Array[(IndexFlag+Index-1)%(Array.Length)];
		}
		IndexFlag=(IndexFlag+1)%(Array.Length);
	}
	else				//Shift Array[(IndexFlag+Index+1)%(Array.Length)],...,Array[(IndexFlag+Count-1)%(Array.Length)] left one position
	{
		for(int i=Index;i<(Count-1);i++)
		{
			Array[(IndexFlag+i)%(Array.Length)]=Array[(IndexFlag+i+1)%(Array.Length)];
		}
	}
	Count--;
	//If there is too mush space,resize it
	if(3*Count < Array.Length)
	{
		Resize();
	}

	return Temp;
}

template<typename T>
void CArrayDeque<T>::PrintInfo()
{
	std::cout<<"[CArrayDeque]:----->"<<std::endl;
	Array.PrintInfo();
	std::cout<<"[CArrayDeque]:<-----"<<std::endl;
	std::cout<<"IndexFlag:"<<IndexFlag<<std::endl<<"Count:"<<Count<<std::endl;
}

}

#endif
