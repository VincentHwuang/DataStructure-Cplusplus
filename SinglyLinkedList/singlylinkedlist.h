/*
 * filename:singly-linkedlist.h
 * created at:2017-08-24
 * author:vincentHwunag
 */

#ifndef  SINGLYLINKEDLIST_H
#define  SINGLYLINKEDLIST_H

#include<stdlib.h>
#include<iostream> //For debug purpose
using namespace std;

namespace ds
{
template<typename T>
class CSinglyLinkedList
    {
		T null;
        protected:
        class CNode
        {
          public:
            T Data;
            CNode *pNext;
            CNode(T Value)
            {
                Data=Value;
                pNext=NULL;
            }  
        };
        CNode *pHead;
        CNode *pTail;
        int    Length;
        
        public:
        //Constructor function	
       	CSinglyLinkedList()
       	{
       		null=(T)NULL;
           	Length=0;
           	pHead=pTail=NULL;		  
       	}	
        //Destructor function        
   		virtual ~CSinglyLinkedList()
        {
            CNode *pCurrentNode=pHead;
            while(pCurrentNode != NULL)
            {
                CNode *pTemp=pCurrentNode;
                pCurrentNode=pCurrentNode->pNext;
                delete pTemp;
            }   
        }
        //Method to get the size of the list
        int Size()
        {
            return Length;
        }
        //Method to get the value of head node
        T Peak()
        {
            return pHead->Data;
        }
        //Method to add a element at the end of the list
        bool Add(T NewValue)
        {
            CNode *pNewNode=new CNode(NewValue);
            if(0 == Length)
            {
                pHead=pNewNode;
            }
            else
            {
                pTail->pNext=pNewNode;
            }
            pTail=pNewNode;
            Length++;
            
            return true;
        }
        //Method to push an element
        bool Push(T NewValue)
        {
            CNode *pNewNode=new CNode(NewValue);
            pNewNode->pNext=pHead;
            pHead=pNewNode;
            if(0 == Length)
            {
                pTail=pNewNode;
            }
            Length++;
            
            return true;
        }
        //Method to pop an element and return its data
        T Pop()
        {
            //Check if the list is empty
            if(0 == Length)
            {
                return null;
            }
            CNode *pTemp=pHead;
            T Temp=pHead->Data;
            pHead=pHead->pNext;
            delete pTemp;
            if(--Length == 0)
            {
                pTail=NULL;
            }
            
            return Temp;    
        }
        //Debug function
        void PrintInfo()
        {
            std::cout<<"[SinglyLinkedList]:"<<std::endl;
            std::cout<<"Length:"<<Length<<std::endl;
            CNode *pCurrentNode=pHead;
            while(pCurrentNode != NULL)
            {
				std::cout<<"Address:"<<pCurrentNode<<std::endl;
                std::cout<<"Data:"<<pCurrentNode->Data<<std::endl<<"pNext:"<<pCurrentNode->pNext<<std::endl;
                pCurrentNode=pCurrentNode->pNext;
            }
        }
    };
}
#endif
