/*
 * filename:sparsemat.h
 * created at:2017-09-04
 * author:VincentHwuang
 */

#ifndef SPARSEMAT_H
#define SPARSEMAT_H

#include<iostream>
#include<exception>
#include<algorithm>

using namespace std;

namespace ds
{
template<typename T>
class CSparseMat
{
	private:
		struct NonZeroElemT
		{
			int RF;	//Row Flag
			int CF;	//Column Flag
			T	Payload;
		};
		NonZeroElemT *m_pElems{};
		int m_RNum{};
		int m_CNum{};
		int m_NonZeroElemNum{};
#ifdef ROW_LOGICAL_LINKED
		int *m_pRpos{};	//Used for row-logical-linked representation while implementing multiply operation.
						//Records indices of the first non-zero element of each row in 'm_pElems'.
		//Method to calculate values for 'm_pRpos'
		void CalcuRpos(void)
		{
			if(m_pRpos != NULL)
			{
				delete m_pRpos;
			}
			try
			{
				m_pRpos=new int[m_RNum+1]{};
			}
			catch(std::bad_alloc& e)
			{
				std::cout<<"Failed to allocate memory for 'm_pRpos'!"<<std::endl;
				exit(-1);
			}
			int Num[m_RNum+1]{};
			for(int i{1};i <= m_NonZeroElemNum;i++)
			{
				++Num[m_pElems[i].RF];				
			}
			m_pRpos[1]=1;
			for(int j{2};j <= m_RNum;j++)
			{
				m_pRpos[j]=m_pRpos[j-1]+Num[j-1];
			}
		}
#endif
	public:
		//Constructor function
		CSparseMat(int RNum,int CNum,int NonZeroElemNum) :
			m_RNum{RNum},m_CNum{CNum},m_NonZeroElemNum{NonZeroElemNum}
		{
			try
			{
				m_pElems=new NonZeroElemT[NonZeroElemNum+1]{};
			}
			catch (std::bad_alloc& e)
			{
				std::cout<<"Failed to allocate memory for 'm_pElems'!"<<std::endl;
				exit(-1);
			}
		}
		CSparseMat(int RNum,int CNum,T *pElems)
		{
			int ElemTotal{RNum * CNum};
			int NonZeroElemNum{};
			
			for(int i{};i < RNum;i++)
			{
				for(int j{};j < CNum;j++)
				{
					if(pElems[i*CNum+j] != 0)
					{
						NonZeroElemNum++;
					}
				}
			}
			if(this->m_pElems != NULL)
			{
				delete this->m_pElems;
			}
			try
			{
				this->m_pElems=new NonZeroElemT[NonZeroElemNum+1];
			}
			catch(std::bad_alloc& e)
			{
				std::cout<<"Failed to allocate memory!"<<std::endl;
				exit(-1);
			}
			this->m_RNum=RNum;
			this->m_CNum=CNum;
			this->m_NonZeroElemNum=NonZeroElemNum;
			int k{1};
			for(int i{};i < RNum ;i++)
			{
				for(int j{};j < CNum;j++)
				{
					if(pElems[i*CNum+j] != 0)
					{	
						this->m_pElems[k].Payload=pElems[i*CNum+j];
						this->m_pElems[k].RF=i+1;
						this->m_pElems[k].CF=j+1;
						k++;
					}
				}
			}
#ifdef ROW_LOGICAL_LINKED
			CalcuRpos();
#endif			
		}
		CSparseMat(const CSparseMat& SparseMat)
		{
			if(this->m_pElems != NULL)
			{
				delete this->m_pElems;
			}
			try
			{
				this->m_pElems=new NonZeroElemT[SparseMat.m_NonZeroElemNum+1];
			}
			catch (std::bad_alloc& e)
			{
				std::cout<<"Failed to allocate memory!"<<std::endl;
				exit(-1);
			}
			for(int i{1};i <= SparseMat.m_NonZeroElemNum;i++)
			{
				this->m_pElems[i].Payload=SparseMat.m_pElems[i].Payload;
				this->m_pElems[i].RF=SparseMat.m_pElems[i].RF;
				this->m_pElems[i].CF=SparseMat.m_pElems[i].CF;
			}
			this->m_RNum=SparseMat.m_RNum;
			this->m_CNum=SparseMat.m_CNum;
			this->m_NonZeroElemNum=SparseMat.m_NonZeroElemNum;
#ifdef ROW_LOGICAL_LINKED
			CalcuRpos();
#endif
		}
		//Destructor function
		~CSparseMat()
		{
			if(m_pElems != NULL)
				delete m_pElems;
#ifdef ROW_LOGICAL_LINKED
			if(m_pRpos != NULL)
				delete m_pRpos;
#endif
		}
		//Implementation of assignment overriding operation
		void operator=(const CSparseMat &SparseMat)
		{
			if(this->m_pElems != NULL)
			{
				delete this->m_pElems;
			}
			try
			{
				this->m_pElems=new NonZeroElemT[SparseMat.m_NonZeroElemNum+1];
			}
			catch (std::bad_alloc& e)
			{
				std::cout<<"Failed to allocate memory!"<<std::endl;
				exit(-1);
			}
			for(int i{1};i <= SparseMat.m_NonZeroElemNum;i++)
			{
				this->m_pElems[i].Payload=SparseMat.m_pElems[i].Payload;
				this->m_pElems[i].RF=SparseMat.m_pElems[i].RF;
				this->m_pElems[i].CF=SparseMat.m_pElems[i].CF;
			}
			this->m_RNum=SparseMat.m_RNum;
			this->m_CNum=SparseMat.m_CNum;
			this->m_NonZeroElemNum=SparseMat.m_NonZeroElemNum;
#ifdef ROW_LOGICAL_LINKED
			CalcuRpos();
#endif
		}
		//Implementation of transposing the matrix,and return its result
		CSparseMat& Transpose()
		{
			/* Using the most normal method to obtain the transpose matrix with triple representation storing,time consuming of this algorithm is O(m_CNum*m_NonZeroElemNum),so when the number of non-zero elements is at the same quantity level with 'm_RNum*m_CNum',the time consuming is O(m_RNum*(m_CNum^2)),so this algorithm apply to such condition:m_NonZeroElemNum << m_RNum * m_CNum */
			CSparseMat Temp{*this};
			std::swap(m_RNum,m_CNum);
			if(m_NonZeroElemNum != 0)
			{
				int Index{1};
				for(int Col{1}; Col <= Temp.m_CNum; Col++)
				{
					for(int Index1{1}; Index1 <= Temp.m_NonZeroElemNum; Index1++)
					{
						if(Temp.m_pElems[Index1].CF == Col)
						{
							m_pElems[Index].RF=Temp.m_pElems[Index1].CF;
							m_pElems[Index].CF=Temp.m_pElems[Index1].RF;
							m_pElems[Index].Payload=Temp.m_pElems[Index1].Payload;
							++Index;
						}
					}
				}
			}
			/* Another more efficient algorithm named quick transpose, add two vector:Num[] and Cpot[],Num[] stores the number of non-zero elements of each column,and the vector Cpot[] store the index of the first non-zero element of each column in m_pElems,because i don't use the first location in m_pElems,so Cpot[1]=1.Time consuming of this algorithm is O(m_CNum+m_NonZeroElemNum),when the number of non-zero elements is at the same quantity level with 'm_RNum * m_CNum',the time consuming is O(m_RNum*m_CNum) */
#ifdef QUICK_TRANSPOSE
			CSparseMat Temp{*this};
			int Num[m_CNum+1];
			int Cpot[m_CNum+1];
			int Col{};
			int ColIndex{};
			std::swap(m_RNum,m_CNum);
			if(m_NonZeroElemNum != 0)
			{
				//First,clear the vector Num[]
				for(int i{1}; i <= Temp.m_CNum; i++)
					Num[i]=0;

				//Calculate the number of non-zero elements of each column
				for(int j{1}; j <= Temp.m_NonZeroElemNum; j++)
					++Num[Temp.m_pElems[j].CF];

				//Obtain the index of the first element of each column
				Cpot[1]=1;
				for(int k{2}; k <= Temp.m_CNum; k++)
					Cpot[k]=Cpot[k-1]+Num[k-1];

				//Finally,transpose the matrix
				for(int i{1}; i <= Temp.m_NonZeroElemNum; i++)
				{
					Col=Temp.m_pElems[i].CF;
					ColIndex=Cpot[Col];
					m_pElems[ColIndex].RF=Temp.m_pElems[i].CF;
					m_pElems[ColIndex].CF=Temp.m_pElems[i].RF;
					m_pElems[ColIndex].Payload=Temp.m_pElems[i].Payload;
					++Cpot[Col];
				}
			}
#endif
			return *this;
		}
		//Method to implement multiply operation using row-logical-linked storing representation
		CSparseMat operator*(const CSparseMat& SparseMat)
		{
			CSparseMat Temp{this->m_RNum,SparseMat.m_CNum,this->m_RNum*SparseMat.m_CNum};
			int RowFlag{1};
			int ColumnFlag0{1};
			int ColumnFlag1{1};
			int CTemp[SparseMat.m_CNum+1]{};
			int RowBound0{};
			int RowBound1{};
			int NonZeroElemNum{1};

			if(this->m_NonZeroElemNum * SparseMat.m_NonZeroElemNum != 0)
			{
				//Handle each row in turn
				for(;RowFlag <= (this->m_RNum);RowFlag++)	
				{	
					//Clear the 'CTemp' array
					for(int i{1};i <= SparseMat.m_CNum;i++)
					{
						CTemp[i]=0;
					}
					//Temp.m_pRpos[RowFlag]=NonZeroElemNum+1;
					//Calculate the bound of current row
					if(RowFlag < (this->m_RNum))	//It is not the last row
					{
						RowBound0=this->m_pRpos[RowFlag+1];
					}
					else							//It is the last row
					{
						RowBound0=this->m_NonZeroElemNum+1;
					}
					//Handle each element in current row
					for(int j{this->m_pRpos[RowFlag]};j < RowBound0;j++)
					{
						//Obtain the column number of current element
						ColumnFlag0=this->m_pElems[j].CF;
						//Calculate the bound of corresponding row in the second matrix
						if(ColumnFlag0 < (SparseMat.m_RNum))
						{
							RowBound1=SparseMat.m_pRpos[ColumnFlag0+1];
						}
						else
						{
							RowBound1=SparseMat.m_NonZeroElemNum+1;
						}
						for(int k{SparseMat.m_pRpos[ColumnFlag0]};k < RowBound1;k++)
						{
							ColumnFlag1=SparseMat.m_pElems[k].CF;
							CTemp[ColumnFlag1] += this->m_pElems[j].Payload*SparseMat.m_pElems[k].Payload;
						}
					}
					for(ColumnFlag1=1;ColumnFlag1 <= Temp.m_CNum;ColumnFlag1++)
					{
						if(CTemp[ColumnFlag1] != 0)
						{
							Temp.m_pElems[NonZeroElemNum].RF=RowFlag;
							Temp.m_pElems[NonZeroElemNum].CF=ColumnFlag1;
							Temp.m_pElems[NonZeroElemNum].Payload=CTemp[ColumnFlag1];
							NonZeroElemNum++;
						}
					}
				}
			}
			Temp.m_NonZeroElemNum=NonZeroElemNum-1;
			Temp.CalcuRpos();
			return Temp;
		}

		//Debug function
		void PrintInfo()
		{
			std::cout<<"m_RNum:"<<m_RNum<<"\t"<<"m_CNum:"<<m_CNum<<"\t"<<"m_NonZeroElemNum:"<<m_NonZeroElemNum<<"\t"<<"m_pElems:"<<m_pElems<<std::endl;
			for(int i{1};i < m_NonZeroElemNum+1;i++)
			{
				std::cout<<m_pElems[i].RF<<"\t"<<m_pElems[i].CF<<"\t"<<m_pElems[i].Payload<<std::endl;
			}
#ifdef ROW_LOGICAL_LINKED
			std::cout<<"m_pRpos:"<<std::endl;
			for(int j{1};j <= m_RNum;j++)
			{
				std::cout<<m_pRpos[j]<<"\t";
			}
			std::cout<<std::endl;
#endif
		}
};
}

#endif
