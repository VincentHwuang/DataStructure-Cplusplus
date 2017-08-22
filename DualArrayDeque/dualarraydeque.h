/*
 * filename:dualarraydeque.h
 * created at:2017-08-21
 * author:VincentHwuang
 */

#ifndef DUALARRAYDEQUE_H
#define DUALARRAYDEQUE_H

#include"arraystack.h"
#include"utils.h"

using ArrayStack::CArrayStack;
using namespace Utility;

namespace DualArrayDeque
{
template<typename T>
class CDualArrayDeque
{
	protected:
		CArrayStack<T> Front;
		CArrayStack<T> Back;
		void Balance();
	public:
		CDualArrayDeque();
		virtual ~CDualArrayDeque();
		//Method to get the size 
		int Size();
		//Method to get an element of specified location
		T Get(int Index);
		//Method to add an element of specified location
		virtual void Add(int Index,T NewElem);
		//Method to set element of specified location
		//and return its original element
		T Set(int Index,T NewElem);
		//Method to remove an element of specified location
		//and return its original element
		virtual T Remove(int Index);
		//Method to clear the dual array deque
		virtual void Clear();
		void PrintInfo();

};

template<typename T>
CDualArrayDeque<T>::CDualArrayDeque()
{
}

template<typename T>
CDualArrayDeque<T>::~CDualArrayDeque()
{
}

template<typename T>
int CDualArrayDeque<T>::Size()
{
	return Front.Size()+Back.Size();
}

template<typename T>
void CDualArrayDeque<T>::Add(int Index,T NewElem)
{
	if(Index< Front.Size())
	{
		Front.Add(Front.Size()-Index,NewElem);
	}
	else
	{
		Back.Add(Index-Front.Size(),NewElem);
	}
	Balance();
}

template<typename T> inline
T CDualArrayDeque<T>::Get(int Index)
{
	//Check if the index is valid
	assert(Index>=0 && Index<Size());

	if(Index < Front.Size())
	{
		return Front.Get(Front.Size()-Index-1);
	}
	else
	{
		return Back.Get(Index-Front.Size());
	}
}

template<typename T>
void CDualArrayDeque<T>::Balance()
{
	if(3*Front.Size() < Back.Size() || 3*Back.Size() < Front.Size())
	{
		int N=Front.Size()+Back.Size();
		int Nf=N/2;
		CArray<T> Af(Max(2*Nf,1));
		for(int i=0;i<Nf;i++)
		{
			Af[Nf-i-1]=Get(i);
		}
		int Nb=N-Nf;
		CArray<T> Ab(Max(2*Nb,1));
		for(int i=0;i<Nb;i++)
		{
			Ab[i]=Get(Nf+i);
		}
		Front.Array=Af;
		Front.Count=Nf;
		Back.Array=Ab;
		Back.Count=Nb;
	}
}

template<typename T> inline
T CDualArrayDeque<T>::Set(int Index,T NewElem)
{
	//Check if the index is valid
	assert(Index>=0 && Index<Size());

	if(Index < Front.Size())
	{
		return Front.Set(Front.Size()-Index-1,NewElem);
	}
	else
	{
		return Back.Set(Index-Front.Size(),NewElem);
	}
}

template<typename T>
T CDualArrayDeque<T>::Remove(int Index)
{
	//Check if the index is valid
	assert(Index>=0 && Index<Size());

	T Temp;

	if(Index < Front.Size())
	{
		Temp=Front.Remove(Front.Size()-Index-1);	
	}
	else
	{
		Temp=Back.Remove(Index-Front.Size());
	}

	Balance();

	return Temp;
}

template<typename T>
void CDualArrayDeque<T>::Clear()
{
	Front.Clear();
	Back.Clear();
}

template<typename T>
void CDualArrayDeque<T>::PrintInfo()
{
	std::cout<<"[CDualArrayDeque]:"<<std::endl;
	std::cout<<"Front:"<<std::endl;
	Front.PrintInfo();
	std::cout<<"Back:"<<std::endl;
	Back.PrintInfo();
}

}

#endif
