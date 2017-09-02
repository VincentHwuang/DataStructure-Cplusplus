/*
 * filename:symmetricmat.h
 * created at:2017-09-02
 * author:VincentHwuang
 */

#ifndef SYMMETRICMAT_H
#define SYMMETRICMAT_H

#include<iostream>

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
			int ElemTotal{m_Dim*(Dim+1)/2};
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
};
}



#endif
