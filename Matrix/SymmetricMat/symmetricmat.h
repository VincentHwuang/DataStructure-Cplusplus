/*
 * filename:symmetricmat.h
 * created at:2017-09-02
 * author:VincentHwuang
 */

#ifndef SYMMETRICMAT_H
#define SYMMETRICMAT_H

#include<iostream>
#include<algorithm>

using namespace std;

namespace ds
{
template<typename T>
class CSymmetricMat
{
	private:
		T	*m_pBase;
		int m_Dim;
	public:
		//Constructor function
		CSymmetricMat(int Dim) : m_pBase(new T[Dim*(Dim+1)/2]),m_Dim(Dim)
		{}
		CSymmetricMat(const CSymmetricMat &SymMat) : CSymmetricMat(SymMat.m_Dim)
		{
			int ElemTotal{m_Dim*(m_Dim+1)/2};
			for(int i{0};i < ElemTotal;i++)
			{
				m_pBase[i]=SymMat.m_pBase[i];
			}
		}
		CSymmetricMat(T *pElems,int Dim) : m_pBase(new T[Dim*(Dim+1)/2]),m_Dim(Dim)
		{
			int Index{};
			for(int i{0};i < Dim;i++)
			{
				for(int j{0};j < Dim;j++)
				{
					if(i >= j)
					{
						m_pBase[Index]=pElems[i*Dim+j];
						Index++;
					}
					else
					{
						break;
					}
				}
			}
		}
		//Destructor function
		~CSymmetricMat()	
		{
			if(m_pBase == NULL)
				exit(-1);
			delete m_pBase;
			m_pBase=NULL;
		}
		//Method to get element of specified location
		T &Get(int row,int column)
		{
			if(row < column)
				std::swap(row,column);
			return m_pBase[row*(row+1)/2+column-1];
		}

		//Debug function
		void PrintInfo()
		{
			std::cout<<"m_Dim:"<<m_Dim<<std::endl;
			int ElemTotal{m_Dim*(m_Dim+1)/2};
			for(int i=0;i < ElemTotal;i++)
			{
				std::cout<<m_pBase[i]<<std::endl;;
			}
		}
};
}

#endif
