#include"doublelinkedlist.h"

using ds::CDoubleLinkedList;

int main(int argc,char **argv)
{
	CDoubleLinkedList<int> DLList;
//	DLList.PrintInfo();
	//Test for method 'Size()'
//	std::cout<<DLList.Size()<<std::endl;
	//Test for method 'GetNode()'
//	DLList.TestGetNode(0)->PrintNodeInfo();	
	//Test for method 'Add()'
	for(int i=0;i<10;i++)
	{
		DLList.Add(i,i);
	}
//	DLList.PrintListInfo();	
	//Test for method 'AddBefore()'
	CDouble
}
