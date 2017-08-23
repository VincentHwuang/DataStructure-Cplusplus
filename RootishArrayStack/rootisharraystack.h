/*
 * filename:rootisharraystack.h
 * crated at:2017-08-22
 * author:VincentHwuang
 */

#ifndef ROOTISHARRAYSTACK_H
#define ROOTISHARRAYSTACK_H

#include<math.h>
#include"arraystack.h"

using ArrayStack::CArrayStack;

namespace RootishArrayStack
{
template<typename T>
class CRootishArrayStack
{
	protected:
		CArrayStack<T*> Blocks;
		int				Count;
		//Method to transform index to block number
		int Index2Block(int Index);
		//Method to grow the stack
		void Grow();
		//Method to shrink the stack
		void Shrink();
	public:
		CRootishArrayStack();
		virtual ~CRootishArrayStack();
		//Method to get the size 
		int Size();
		//Method to get an element of specified location
		T Get(int Index);
		//Method to set element of specified location
		//and return its original element
		T Set(int Index,T NewElem);
		//Method to add an element at specified location
		virtual void Add(int Index,T NewElem);
		//Method to remove an element of specified location
		//and return it
		virtual T Remove(int Index);
		//Method to clear the stack
		virtual void Clear();
		void PrintInfo();


};

template<typename T>
CRootishArrayStack<T>::CRootishArrayStack()
{
	Count=0;
}

template<typename T> inline 
int CRootishArrayStack<T>::Size()
{
	return Count;
}

template<typename T>
CRootishArrayStack<T>::~CRootishArrayStack()
{
}

template<typename T>
int CRootishArrayStack<T>::Index2Block(int Index)
{
	double db=(-3.0+sqrt(9+8*Index))/2.0;
	int BlockNumber=(int)ceil(db);

	return BlockNumber;
}

template<typename T>
T CRootishArrayStack<T>::Get(int Index)
{
	int BlockNumber=Index2Block(Index);
	int LocalIndex=Index-BlockNumber*(BlockNumber+1)/2;

	return Blocks.Get(BlockNumber)[LocalIndex];
}

template<typename T>
T CRootishArrayStack<T>::Set(int Index,T NewElem)
{
	//Check if the index is valid
	assert(Index>=0 && Index<Count);

	int BlockNumber=Index2Block(Index);
	int LocalIndex=Index-BlockNumber*(BlockNumber+1)/2;
	T Temp=Blocks.Get(BlockNumber)[LocalIndex];
	Blocks.Get(BlockNumber)[LocalIndex]=NewElem;

	return Temp;
}

template<typename T>
void CRootishArrayStack<T>::Add(int Index,T NewElem)
{
	//If the stack is full,grow it
	int r=Blocks.Size();
	if(r*(r+1)/2 < Count+1)
	{
		Grow();
	}
	Count++;
	//Move elements to get space to the 'NewElem'
	for(int i=Count-1;i>Index;i--)
	{
		Set(i,Get(i-1));
	}
	Set(Index,NewElem);
}

template<typename T>
void CRootishArrayStack<T>::Grow()
{
	Blocks.Add(Blocks.Size(),new T[Blocks.Size()+1]);
}

template<typename T>
void CRootishArrayStack<T>::Shrink()
{
	int r=Blocks.Size();
	while(r>0 && (r-2)*(r-1)/2 >= Count)
	{
		delete [] Blocks.Remove(Blocks.Size()-1);
		r--;
	}
}

template<typename T>
T CRootishArrayStack<T>::Remove(int Index)
{
	//Check if the index is valid
	assert(Index>=0 && Index<Size());

	T Temp=Get(Index);
	//Move elements to fill the space
	for(int i=Index;i<Count-1;i++)
	{
		Set(i,Get(i+1));
	}
	Count--;
	//If the size of stack is too big,shrink it
	int r=Blocks.Size();
	if((r-2)*(r-1)/2 >= Count)
	{
		Shrink();
	}

	return Temp;
}

template<typename T>
void CRootishArrayStack<T>::Clear()
{
	while(Blocks.Size() > 0)
	{
		delete [] Blocks.Remove(Blocks.Size()-1);
	}
	Count=0;
}

template<typename T>
void CRootishArrayStack<T>::PrintInfo()
{
	std::cout<<"[CRootishArrayStack]:"<<std::endl;
	int BlockNumber=Index2Block(Count-1);
	std::cout<<"Total blocks:"<<BlockNumber+1<<std::endl;
	for(int i=0;i<BlockNumber+1;i++)
	{
		std::cout<<"BlockNumber:"<<i<<std::endl;
		for(int j=0;j<i+1;j++)
		{
			std::cout<<Blocks.Get(i)[j]<<std::endl;
		}
	}
	std::cout<<"Count:"<<Count<<std::endl;
}

}

#endif
