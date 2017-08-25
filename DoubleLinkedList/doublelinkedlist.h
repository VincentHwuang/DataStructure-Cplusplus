/*
 * filename:doublelinkedlist.h
 * created at:2017-08-24
 * author:VincentHwuang
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINkEDLIST_H

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
        }
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
        virtual ˜CDoubleLinkedList();
        //Method to get the size of the list
        int Size() {return Length;}
        //Method to get data of specified location
        T Get(int Index);
        //Method to add an element at specified location
        virtual void Add(int Index,T NewElem);
        
      
    };
    template<typename T>
    CDoubleLinkedList<T>::CDoubleLinkedList()
    {
        Dummy.pPrev=&Dummy;
        Dummy.pNext=&Dummy;
        Length=0;        
    }
    
    template<typename T>
    CDoubleLinkedList<T>::˜CDoubleLinkedList()
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
        
    }
    
    template<typename T>
    void CDoubleLinkedList<T>::Add(int Index,T NewElem)
    {
        //Check if the index is valid
        assert(Index>=0 && Index<Size());
        
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
}





#endif