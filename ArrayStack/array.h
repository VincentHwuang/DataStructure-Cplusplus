/*
 * filename:array.h
 * created at:2017-08-14
 * author:VincentHwuang
 */

#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<assert.h>

using namespace std;

namespace Array 
{
template<typename T>
class CArray 
{
	protected:
		T *pArray;
	
	public:
		int Length;
		//Constructor functions
		CArray(int LengthValue);
		CArray(int LengthValue,T Initialization);
		//Method to fill each value in 'pArray' with 'Value'
		void Fill(T value);
		//Debug function
		void PrintInfo(void);
		//Method to set value of specified location
		void SetValue(int Index,T Value);
		//Destructor function
		virtual ~CArray();
		//Method to reverse datas in the array
		virtual void Reverse();
		//Method to implement index operation
		T& operator[](int Index);
		//Method to implement assign operator
		CArray<T>& operator=(CArray<T> &ArrayB);
		//Method to implement '+' operator
		T* operator+(int i);
		//Method to swap two values in the array
		void swap(int i,int j);
		//Method to copy a range of elements from another array 
		//Usage:CopyOfRange(SourceArray,StartIndex,EndIndex)
		void CopyOfRange(CArray<T> &SourceArray,int StartIndex,int EndIndex);
};


template<typename T>
CArray<T>::CArray(int LengthValue)
{
	this->Length=LengthValue;
	this->pArray=new T[this->Length];

	return;
}

template<typename T>
CArray<T>::CArray(int LengthValue,T Initialization)
{
	this->Length=LengthValue;
	this->pArray=new T[this->Length];
	for(int i=0;i<(this->Length);i++)
	{
		pArray[i]=Initialization;
	}

	return;
}

template<typename T>
CArray<T>::~CArray()
{
	if(pArray != NULL)
	{
		delete [] pArray;
	}
}

template<typename T>
void CArray<T>::Fill(T Value)
{
	std::fill(this->pArray,(this->pArray)+(this->Length),Value);

	return;
}

template<typename T>
void CArray<T>::PrintInfo(void)
{
	std::cout<<"[CArray]:"<<std::endl;
	if(this->pArray == NULL)
	{
		std::cout<< "Sorry,the 'pArray' is NULL"<<std::endl;
	}
	else
	{
		std::cout<<"The address of the array is:"<<this->pArray<<std::endl;
		std::cout<<"The Length of the array is:"<<this->Length<<std::endl<<"The datas stored in the array are:"<<std::endl;
		for(int i=0;i<(this->Length);i++)
		{
			std::cout<<pArray[i]<<std::endl;
		}
	}

	return;
}

template<typename T>
void CArray<T>::SetValue(int Index,T Value)
{
	assert(Index>=0 && Index<Length);
	pArray[Index]=Value;

	return;
}

template<typename T>
void CArray<T>::Reverse()
{
	for(int i=0;i<(Length/2);i++)
	{
		swap(i,Length-1-i);
	}

	return;
}

template<typename T>
void CArray<T>::swap(int i,int j)
{
	assert(i>=0 && i<Length && j>=0 && j<Length);
	T Value=pArray[i];
	pArray[i]=pArray[j];
	pArray[j]=Value;

	return;
}

template<typename T>
T* CArray<T>::operator+(int i)
{
	return &pArray[i];
}

template<typename T>
CArray<T>& CArray<T>::operator=(CArray<T> &ArrayB)
{
	if((this->pArray) != NULL)
	{
		delete [] (this->pArray);
	}
	this->pArray=ArrayB.pArray;
	this->Length=ArrayB.Length;
	ArrayB.pArray=NULL;

	return *this;
}

template<typename T>
T& CArray<T>::operator[](int Index)
{
	//Check if the index is valid
	assert(Index >= 0 && Index < (this->Length));
	return (this->pArray)[Index];
}

template<typename T>
void CArray<T>::CopyOfRange(CArray<T> &SourceArray,int StartIndex,int EndIndex)
{
	//Check if the indices are valid
	assert(StartIndex >=0 && EndIndex < (SourceArray.Length) && EndIndex > StartIndex);
	CArray<T> TempArray(EndIndex-StartIndex+1);
	std::copy((SourceArray.pArray)+StartIndex,(SourceArray.pArray)+EndIndex+1,TempArray.pArray);
	*this=TempArray;

	return;
}
	
}
#endif
