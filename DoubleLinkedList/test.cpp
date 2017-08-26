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
	//Test for method 'Add(int Index,T NewElem)'
	for(int i=0;i<10;i++)
	{
		DLList.Add(i,i);
	}
//	DLList.PrintListInfo();	
	//Test for method 'Get()'
//	std::cout<<DLList.Get(0)<<std::endl<<DLList.Get(DLList.Size()-1)<<std::endl;
	//Test for method 'Clear()'
//	DLList.Clear();
//	DLList.PrintListInfo();
	//Test for method 'Add(T NewElem)'
//	DLList.Add(234);
//	DLList.PrintListInfo();
	//Test for method 'Remove()'
//	DLList.Remove(0);
//	DLList.Remove(DLList.Size()-1);
//	DLList.PrintListInfo();
	//Test for method 'Set()'
	DLList.Set(0,123);
	DLList.Set(DLList.Size()-1,234);
	DLList.PrintListInfo();

	return 0;
}
