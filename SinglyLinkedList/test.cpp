#include"singlylinkedlist.h"

using ds::CSinglyLinkedList;

int main(void)
{
    CSinglyLinkedList<int> SLList;
//  SLList.PrintInfo();
    //Test for method 'Add()'
    for(int i=0;i<10;i++)
    {
        SLList.Add(i);
    }   
//  SLList.PrintInfo();
//  //Test for method 'Size()'
//  int Length=SLList.Size();
//  std::cout<<"Length:"<<Length<<std::endl;
//  //Test for method 'Push()'
    SLList.Push(100);
    SLList.Push(200);
//  SLList.PrintInfo();
//  //Test for method 'Peak()'
    int HeadData=SLList.Peak();
//	std::cout<<HeadData<<std::endl;
//  //Test for method 'Pop()'
//  int Data2=SLList.Pop();
//  int Data3=SLList.Pop();
//  std::cout<<Data2<<std::endl<<Data3<<std::endl;
//  SLList.PrintInfo();
    
    return 0;
}
