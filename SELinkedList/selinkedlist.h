/*
 * filename:selinkedlist.h
 * created at:2017-08-26
 * author:VincentHwuang
 */

#ifndef SELINKEDLIST_H
#define SELINKEDLIST_H

#include"arraydeque.h"
#include"array.h"
#include"assert.h"

namespace ds
{
template<typename T>
class CSELinkedList
{
protected:
	int Count;
	int BlockVolume;
	class CBDeque : public CArrayDeque<T>
	{
		using CArrayDeque<T>::Array;
		using CArrayDeque<T>::IndexFlag;
		using CArrayDeque<T>::Count;

		public:
			//Constructor function
			CBDeque(int BlockVolume)
			{
				Count=0;
				IndexFlag=0;
				CArray<int> Temp(BlockVolume+1);
				Array=Temp;
			}
			//Destructor function
			virtual ~CBDeque() {}
			//Method to add an element at specified location
			virtual void Add(int Index,T NewElem)
			{
				CArrayDeque<T>::Add(Index,NewElem);
			}
			//Method to add an element at the end
			virtual bool Add(T NewElem)
			{
				CArrayDeque<T>::Add(Size(),NewElem);					
				return true;
			}
			//Method to resize the queue
			void Resize() {}
	};

	class CNode
	{
		public:
			CBDeque Deque;
			CNode *pPrev;
			CNode *pNext;
			CNode(int BlockVolume) : Deque(BlockVolume) {}
			//Debug function
			void PrintInfo()
			{
				std::cout<<"[CNode]:----->"<<std::endl<<"Deque:"<<std::endl;
				Deque.PrintInfo();
				std::cout<<"[CNode]:<-----"<<std::endl;
				std::cout<<"pPrev:"<<pPrev<<"\t"<<"pNext:"<<pNext<<std::endl;
			}
	};

	CNode Dummy;

	class CLocation
	{
		public:
			CNode *pNode;
			int    Index;
			//Constructor function
			CLocation() {}
			CLocation(CNode *pNode,int Index)
			{
				this->pNode=pNode;
				this->Index=Index;
			}
	};

	//Method to add a node before specified node
	//and return the new-added node
	CNode *AddBefore(CNode *pNode)
	{
		CNode *pNewNode=new CNode(BlockVolume);
		pNewNode->pPrev=pNode->pPrev;
		pNewNode->pNext=pNode;
		pNewNode->pNext->pPrev=pNewNode;
		pNewNode->pPrev->pNext=pNewNode;

		return pNewNode;
	}
	//Method to remove a node
	void Remove(CNode *pNode)
	{
		pNode->pPrev->pNext=pNode->pNext;
		pNode->pNext->pPrev=pNode->pPrev;
		delete pNode;
	}
	//Method to get location from an index 
	void GetLocation(int Index,CLocation &Effl)
	{
		//Check if the index is valid
//		assert(Index >= 0 && Index < Count);

		if(Index < Count/2)
		{
			CNode *pCurrentNode=Dummy.pNext;
			while(Index >= (pCurrentNode->Deque.Size()))
			{
				Index-=(pCurrentNode->Deque.Size());
				pCurrentNode=pCurrentNode->pNext;
			}
			Effl.pNode=pCurrentNode;
			Effl.Index=Index;
		}
		else
		{
			CNode *pCurrentNode=&Dummy;
			int    Idx=Count;
			while(Index < Idx)
			{
				pCurrentNode=pCurrentNode->pPrev;
				Idx-=pCurrentNode->Deque.Size();
			}
			Effl.pNode=pCurrentNode;
			Effl.Index=Index-Idx;
		}
	}
	//Method to spread a node when the node and its b-1 successors
	//all contains b+1 items.This add a new node so that the node and
	//its b successors each contains b items.
	void Spread(CNode *pNode)
	{
		CNode *pTemp=pNode;
		for(int i=0;i<BlockVolume;i++)
		{
			pTemp=pTemp->pNext;
		}
		pTemp=AddBefore(pTemp);
		while(pTemp != pNode)
		{
			while(pTemp->Deque.Size() < BlockVolume)
			{
				pTemp->Deque.Add(0,pTemp->pPrev->Deque.Remove(pTemp->pPrev->Deque.Size()-1));
			}
			pTemp=pTemp->pPrev;
		}
	}
	//Method to gather elements.Call this function on a node 'pNode' such that 'pNode' and its 'BlockVolume-1' successors all contains 'BlockVolume-1' items.This removes a node so that 'pNode' and its  'BlockVolume-2' each contains 'BlockVolume' items.
	void Gather(CNode *pNode)
	{
		CNode *pTemp=pNode;
		for(int i=0;i < (BlockVolume-1);i++)
		{
			while(pTemp->Deque.Size() < BlockVolume)
			{
				pTemp->Deque.Add(pTemp->pNext->Deque.Remove(0));
			}
			pTemp=pTemp->pNext;
		}
		Remove(pTemp);
	}
	//Method to add an element at the end of list
	void Add(T NewElem)
	{
		CNode *pLast=Dummy.pPrev;

		//if the list is empty or the last node is full
		//then add a new node at the end
		if(pLast == &Dummy || pLast->Deque.Size() == (BlockVolume+1))
		{
			pLast=AddBefore(&Dummy);
		}
		pLast->Deque.Add(NewElem);
		Count++; 
	}
	
public:
	//Constructor function
	CSELinkedList(int BlockVolume) : Dummy(BlockVolume)
	{
		this->BlockVolume=BlockVolume;
		Dummy.pNext=&Dummy;
		Dummy.pPrev=&Dummy;
		Count=0;
	}
	//Destructor function
	virtual ~CSELinkedList()
	{
		Clear();
	}
	//Method to clear the list
	virtual void Clear()
	{
		CNode *pCurrentNode=Dummy.pNext;
		while(pCurrentNode != &Dummy)
		{
			CNode *pTemp=pCurrentNode->pNext;
			delete pCurrentNode;
			pCurrentNode=pTemp;
		}
		Count=0;
	}
	//Method to get element of specified location
	T Get(int Index)
	{
		CLocation L;
		GetLocation(Index,L);
		return (L.pNode->Deque.Get(L.Index));
	}
	//Method to modify element of specified location
	//and return its original element value
	T Set(int Index,T NewElem)
	{
		CLocation L;
		GetLocation(Index,L);
		T Temp=L.pNode->Deque.Get(L.Index);
		L.pNode->Deque.Set(L.Index,NewElem);
		
		return Temp;
	}
	//Method to get the size of the list
	int Size()
	{
		return Count;
	}
	//Method to add an element at specified location
	void Add(int Index,T NewElem)
	{
		if(Index == Count)
		{
			Add(NewElem);
			return;
		}

		CLocation L;
		GetLocation(Index,L);
		CNode *pNode=L.pNode;
		int    r=0;
		while(r < BlockVolume && pNode != &Dummy && pNode->Deque.Size() == (BlockVolume+1))
		{
			pNode=pNode->pNext;
			r++;
		}
		if(r == BlockVolume)//L.pNode,L.pNode->pNext,L.pNode->pNext->pNext,...,total 'BlockVolume' blocks each contains BlockVolume+1 elements
		{
			Spread(L.pNode);
			pNode=L.pNode;
		}
		if(pNode == &Dummy)	//Run off the end,add a new node
		{
			pNode=AddBefore(pNode);
		}
		while(pNode != L.pNode)//and then work backwards,shifting elements
		{
			pNode->Deque.Add(0,pNode->pPrev->Deque.Remove(pNode->pPrev->Deque.Size()-1));
			pNode=pNode->pPrev;
		}
		//if 'pNode->Deque.Size() != (BlockVolume+1)',current block is not full
		pNode->Deque.Add(L.Index,NewElem);
		Count++;
	}
	//Method to remove an element of specified location 
	//and return its original payload
	T Remove(int Index)
	{
		CLocation L;
		GetLocation(Index,L);
		T Temp=L.pNode->Deque.Get(L.Index);

		CNode* pTempNode=L.pNode;
		int    r=0;
		while(r < BlockVolume && pTempNode != &Dummy && pTempNode->Deque.Size() == (BlockVolume-1))
		{
			pTempNode=pTempNode->pNext;
			r++;
		}
		if(r == BlockVolume)//Found 'BlockVolume' blocks each contains 'BlockVolume-1' elements
		{
			Gather(L.pNode);
		}
		pTempNode=L.pNode;
		pTempNode->Deque.Remove(L.Index);
		//else if 'r != BlockVolume',then here pTempNode->Deque.Size() < (BlockVolume-1)
		while(pTempNode->Deque.Size() < (BlockVolume-1) && pTempNode->pNext != &Dummy)
		{
			pTempNode->Deque.Add(pTempNode->pNext->Deque.Remove(0));
			pTempNode=pTempNode->pNext;
		}
		if(pTempNode->Deque.Size() == 0)
		{
			Remove(pTempNode);
		}
		Count--;

		return Temp;
	}

	//Debug function
	void PrintInfo()
	{
		std::cout<<"[CSELinkedList]:"<<std::endl;
		std::cout<<"BlockVolume:"<<BlockVolume<<"\t"<<"Count:"<<Count<<std::endl;
		std::cout<<"Dummy:"<<std::endl<<"Address:"<<"\t"<<&Dummy<<std::endl;
		Dummy.PrintInfo();
		CNode *pCurrentNode=Dummy.pNext;
		std::cout<<"========================================================================================================="<<std::endl;
		while(pCurrentNode != &Dummy)
		{
			std::cout<<"========================================"<<std::endl;
			std::cout<<"Address:"<<pCurrentNode<<std::endl;
			pCurrentNode->PrintInfo();
			pCurrentNode=pCurrentNode->pNext;
		}
	}
	



};

}

#endif
