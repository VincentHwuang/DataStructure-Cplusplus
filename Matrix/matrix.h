/*
 * filename:matrix.h
 * created at:2017-09-01
 * author:VincentHwuang
 */

#ifndef MATRIX_H
#define MATRIX_H

#include<stdarg.h>
#include<iostream>
#include"error.h"

using namespace std;

#define MAX_MATRIX_DIM 10

namespace ds
{
template<typename T>
class CMatrix
{
	private:
		T	*pBase;
		int	Dim;
		int *pBounds;		//To store number of each dimension
		int *pConstants;	//To store the constants of image function
	public:
		//Constructor function
		CMatrix(int Dim,...);
		//Destructor function
		~CMatrix();
		//Method to get element of specified location
		Status GetValue(T &BackCarrier,...);	
		//Method to locate an element 
		Status Locate(va_list &Arg,int &Offset);
		//Method to set element of specified location
		Status SetValue(const T &NewElem,...);



		//Debug function
		void PrintInfo()
		{
			int ElemTotal=0;
			std::cout<<"Dim:"<<Dim<<std::endl;
			std::cout<<"pBase:"<<std::endl<<"Address:"<<pBase<<std::endl;
			std::cout<<"pBounds:"<<std::endl<<"Address:"<<pBounds<<std::endl;
			for(int i{0};i<Dim;i++)
			{
				std::cout<<pBounds[i]<<std::endl;
				ElemTotal+=pBounds[i];
			}
			std::cout<<"pConstants:"<<std::endl<<"Address:"<<pConstants<<std::endl;
			for(int i{0};i<Dim;i++)
			{
				std::cout<<pConstants[i]<<std::endl;
			}
			std::cout<<"ElemTotal:"<<ElemTotal<<std::endl;
			for(int i=0;i<ElemTotal;i++)
			{
				std::cout<<pBase[i]<<std::endl;
			}
		}

};

template<typename T>
CMatrix<T>::CMatrix(int Dim,...)
{
	//Check if the dimension is valid
	if(Dim < 1 || Dim > MAX_MATRIX_DIM)
		exit(ERROR);
	this->Dim=Dim;
	this->pBounds=new int[Dim];

	int ElemTotal{1};
	va_list Arg;
	va_start(Arg,Dim);
	for(int i=0;i < Dim;i++)
	{
		pBounds[i]=va_arg(Arg,int);
		if(pBounds[i] < 0)
			exit(ERROR);
		ElemTotal *= pBounds[i];
	}
	va_end(Arg);
	this->pBase=new T[ElemTotal];
	this->pConstants=new int[Dim];
	this->pConstants[this->Dim - 1]=1;
	for(int i{Dim-2};i >= 0;i--)
	{
		pConstants[i] = pBounds[i+1] * pConstants[i+1];
	}
}

template<typename T>
CMatrix<T>::~CMatrix()
{
	if(pBase == NULL)
		exit(ERROR);
	delete pBase;
	pBase=NULL;
	
	if(pBounds == NULL)
		exit(ERROR);
	delete pBounds;
	pBounds=NULL;

	if(pConstants == NULL)
		exit(ERROR);
	delete pConstants;
	pConstants=NULL;
}

template<typename T>
Status CMatrix<T>::GetValue(T &BackCarrier,...)
{
	va_list Arg{};
	int		Offset{};
	va_start(Arg,BackCarrier);
	if(Locate(Arg,Offset) == ERROR)
		return ERROR;
	BackCarrier=pBase[Offset];

	return OK;
}

template<typename T>
Status CMatrix<T>::Locate(va_list &Arg,int &Offset)
{
	int Index{};
	Offset=0;
	for(int i{0};i < Dim;i++)
	{
		Index=va_arg(Arg,int);
		//Check if the index is valid
		if(Index < 0 || Index >= pBounds[i])
			return ERROR;
		Offset += pConstants[i] * Index;
	}

	return OK;
}

template<typename T>
Status CMatrix<T>::SetValue(const T &NewElem,...)
{
	va_list Arg{};
	int		Offset{};
	va_start(Arg,NewElem);
	if(Locate(Arg,Offset) == ERROR)
		return ERROR;
	pBase[Offset]=NewElem;

	return OK;
}

}

#endif
