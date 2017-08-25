/* 
 * filename:SinglyLinkedList.cpp
 * created at:2017-08-24
 * author:VincentHwuant
 */

#include"singlylinkedlist.h"

namespace ds
{
template CSinglyLinkedList<int>::CSinglyLinkedList();
template CSinglyLinkedList<int>::~CSinglyLinkedList();
template bool CSinglyLinkedList<int>::Push(int NewValue);
template bool CSinglyLinkedList<int>::Add(int NewValue);
template int CSinglyLinkedList<int>::Size();
}
