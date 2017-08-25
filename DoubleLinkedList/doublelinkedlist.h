/*
 * filename:doublelinkedlist.h
 * created at:2017-08-24
 * author:VincentHwuang
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINkEDLIST_H

#include<iostream>	//For debug purpose
#include<assert.h>

using namespace std;

namespace ds
{
template<typename T>
class CDoubleLinkedList
    {
        protected:
        struct Node
        {
            T Data;
            Node *pPrev;
            Node *pNext;
			void PrintNodeInfo()
			{
				std::cout<<"[NodeInfo]:"<<std::endl;
				std::cout<<"Data:"<<Data<<"\t"<<"pPrev:"<<pPrev<<"\t"<<"pNext:"<<pNext<<std::endl;	
			}
        };
		//We need a node to help us to ease the processing of
		//some special cases.For example,to add or delete 
		//element at the end or at the last,the 'pPrev' field 
		//of this node points to the last node of the list 
		//and the 'pNext' field points to the first node of the list
        Node Dummy;
        int Length;
        //Method to get a node of specified location
        Node *GetNode(int Index);
        //Method to add new element before specified node
        //and return the new added node
        Node *AddBefore(Node* pNode,T NewData);
        
        public:
        //Constructor function
        CDoubleLinkedList();
        //Destructor function
        virtual ~CDoubleLinkedList();
        //Method to get the size of the list
        int Size() {return Length;}
        //Method to get data of specified location
        T Get(int Index);
        //Method to add an element at specified location
        virtual void Add(int Index,T NewElem);
		//Method to clear the list
		virtual void Clear();
		//Debug function
        void PrintListInfo();
		//Debug function
		Node *TestGetNode(int Index)
		{
			return GetNode(Index);
		}
    };
    template<typename T>
    CDoubleLinkedList<T>::CDoubleLinkedList()
    {
        Dummy.pPrev=&Dummy;
        Dummy.pNext=&Dummy;
        Length=0;        
    }
    
    template<typename T>
    CDoubleLinkedList<T>::~CDoubleLinkedList()
    {
        Clear();
    }
    
    template<typename T>
    T CDoubleLinkedList<T>::Get(int Index)
    {
        //Check if the index is valid
        assert(Index>=0 && Index<Size());
        return GetNode(Index)->Data;
    }
    
    template<typename T>
    typename CDoubleLinkedList<T>::Node* CDoubleLinkedList<T>::GetNode(int Index)
    {
		//Check if the index is valid
		//assert(Index>=0 && Index<Size());

		Node *pCurrentNode;
		//To seek for a specified node,we have two approaches
		//we check the index to save time consuming
		if(Index<Length/2)
		{
			pCurrentNode=Dummy.pNext;
			for(int i=0;i<Index;i++)
			{
				pCurrentNode=pCurrentNode->pNext;
			}
		}
		else
		{
			pCurrentNode=&Dummy;
			for(int i=Length;i>Index;i--)
			{
				pCurrentNode=pCurrentNode->pPrev;
			}
		}

		return pCurrentNode;
    }
    
    template<typename T>
    void CDoubleLinkedList<T>::Add(int Index,T NewElem)
    {
        //Check if the index is valid
        //assert(Index>=0 && Index<Size());
        
        AddBefore(GetNode(Index),NewElem);
    } 
    
    template<typename T>
    typename CDoubleLinkedList<T>::Node* CDoubleLinkedList<T>::AddBefore(Node *pNode,T NewData)
    {
        Node *pTemp=new Node;
        pTemp->Data=NewData;
        pTemp->pNext=pNode;
        pTemp->pPrev=pNode->pPrev;
        pTemp->pNext->pPrev=pTemp;
        pTemp->pPrev->pNext=pTemp;
        Length++;
        
        return pTemp;
    } 

	template<typename T>
	void CDoubleLinkedList<T>::Clear()
	{
		Node *pCurrentNode=Dummy.pNext;
		while(pCurrentNode != &Dummy)
		{
			Node *pTemp=pCurrentNode->pNext;
			delete pCurrentNode;
			pCurrentNode=pTemp;
		}
	}

	template<typename T>
	void CDoubleLinkedList<T>::PrintListInfo()
	{
		std::cout<<"[ListInfo]:"<<std::endl;
		std::cout<<"Length:"<<Length<<std::endl;
		std::cout<<"Dummy:"<<std::endl<<"Address:"<<&Dummy<<"\t"<<"pPrev:"<<Dummy.pPrev<<"\t"<<"pNext:"<<Dummy.pNext<<std::endl;
		Node *pCurrentNode=Dummy.pNext;
		for(int i=0;i<Length;i++)
		{
			std::cout<<"Address:"<<pCurrentNode<<std::endl;
		//	std::cout<<"Data:"<<pCurrentNode->Data<<"\t"<<"pPrev:"<<pCurrentNode->pPrev<<"\t"<<"pNext:"<<pCurrentNode->pNext<<std::endl;
			pCurrentNode->PrintNodeInfo();
			pCurrentNode=pCurrentNode->pNext;
		}
		
	}

	
}

#endif
