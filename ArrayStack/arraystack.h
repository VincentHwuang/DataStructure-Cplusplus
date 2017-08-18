/*
 * filename:arraystack.h
 * created at:2017-08-17
 * author:VincentHwuang
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include"array.h"
#include"utils.h"

using namespace std;
using namespace Array;
using namespace Utility;

namespace ArrayStack
{
template<typename T>
class CArrayStack
{
	protected:
		CArray<T> Array;
		int		  Count;
		//Method to resize capacity of Array in case it is too big or too small 
		virtual void Resize();
	public:
		//Constructor function
		CArrayStack();
		//Destructor function
		virtual ~CArrayStack();
		//Method to return the actual count of the array stack
		int Size();
		//Method to get the element of specified location
		T Get(int Index);
		//Method to set element of a specified location and return its original element
		T Set(int Index,T NewElem);
		//Debug function
		void PrintInfo();
		//Method to add an element to specified location
		virtual void Add(int Index,T NewElem);
		//Method to push an element
		virtual void Push(T NewElem);
		//Method to remove an element of specified location and return it
		virtual T Remove(int Index);
		//Method to pop an element 
		virtual T Pop();
		//Method to clear the array
		virtual void Clear();


};

template<typename T>
CArrayStack<T>::CArrayStack() : Array(1)
{
	Count=0;
}

template<typename T>
CArrayStack<T>::~CArrayStack()
{
}

template<typename T> inline 
int CArrayStack<T>::Size()
{
	return Count;
}

template<typename T> inline 
T CArrayStack<T>::Get(int Index)
{
	//Check if the index is valid
	assert(Index >=0 && Index < Count);
	return Array[Index];
}

template<typename T> inline 
T CArrayStack<T>::Set(int Index,T NewElem)
{
	assert(Index >=0 && Index < Count);
	T Temp=Array[Index];
	Array[Index]=NewElem;

	return Temp;
}

template<typename T>
void CArrayStack<T>::PrintInfo() 
{
	std::cout<<"[CArrayStack]:"<<std::endl;
	Array.PrintInfo();
	std::cout<<"The actual count of elements is:"<<Count<<std::endl;

	return;
}

template<typename T>
void CArrayStack<T>::Resize()
{
	CArray<T> Temp(Max(2*Count,1));
//	for(int i=0;i<Count;i++)
//	{
//		Temp[i]=Array[i];
//	}
	//More efficient solution
	std::copy(Array+0,Array+Count,Temp+0);
	Array=Temp;
}

template<typename T>
void CArrayStack<T>::Add(int Index,T NewElem)
{
	//If the space is not enough,resize it
	if(Count+1>Array.Length)
	{
		Resize();
	}

	//Check if the Index is valid
	assert(Index >=0);

//	for(int i=Count;i>Index;i--)
//	{
//		Array[i]=Array[i-1];
//	}
	//More efficient solution
	std::copy_backward(Array+Index,Array+Count,Array+Count+1);

	Array[Index]=NewElem;
	Count++;
}

template<typename T>
void CArrayStack<T>::Push(T NewElem)
{
	Add(Size(),NewElem);
}

template<typename T>
T CArrayStack<T>::Remove(int Index)
{
	//Check if the Index is valid
	assert(Index >=0 && Index < Count);

	T Temp=Array[Index];
	
	for(int i=Index;i<Count-1;i++)
	{
		Array[i]=Array[i+1];
	}
	Count--;

	//If the space of array is too big, resize it
	if(Array.Length >= 3*Count)
	{
		Resize();
	}

	return Temp;
}

template<typename T> 
T CArrayStack<T>::Pop()
{
	return Remove(Size()-1);
}

template<typename T>
void CArrayStack<T>::Clear()
{
	CArray<T> Temp(1);
	Array=Temp;
	Count=0;
}

}

#endif
