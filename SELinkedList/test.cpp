#include"selinkedlist.h"

using ds::CSELinkedList;

int main(void)
{
	CSELinkedList<int> SELList(3);
//	SELList.PrintInfo();
	//Test for method 'Add(int Index,T NewElem)'
	for(int i=0;i<10;i++)
	{
		SELList.Add(i,i);
	}
//	SELList.PrintInfo();
	//Test for method 'Get()'
//	int Item0=SELList.Get(0);
//	int Item1=SELList.Get(5);
//	std::cout<<"Item0:"<<Item0<<"\t"<<"Item1:"<<Item1<<std::endl;
	//Test for method 'Set()'
//	SELList.Set(0,123);
//	SELList.Set(5,234);
//	SELList.PrintInfo();
	//Test for method 'Size()'
//	std::cout<<"Size:"<<SELList.Size()<<std::endl;
	//Test for method 'Remove()'
	for(int i=0;i<6;i++)
	{
		SELList.Remove(i);
	}
	SELList.PrintInfo();

	return 0;
}
