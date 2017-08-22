#include"dualarraydeque.h"

using DualArrayDeque::CDualArrayDeque;

int main(int argc,char **argv)
{
	CDualArrayDeque<int> DualArrayDeque;
	//Test for method 'Add()'
	for(int i=0;i<10;i++)
	{
		DualArrayDeque.Add(i,i);
	}
	//Test for method 'Size()'
//	std::cout<<"Size:"<<DualArrayDeque.Size()<<std::endl;
	//Test for method 'Get()'
//	int Value0=DualArrayDeque.Get(2);
//	int Value1=DualArrayDeque.Get(DualArrayDeque.Size()-1);
//	std::cout<<"Value0:"<<Value0<<std::endl<<"Value1:"<<Value1<<std::endl;
	//Test for method 'Set()'
//	for(int i=0;i<DualArrayDeque.Size();i++)
//	{
//		std::cout<<DualArrayDeque.Set(i,i+100)<<std::endl;
//	}
	//Test for method 'Remove()'
//	int Value0=DualArrayDeque.Remove(0);
//	int Value1=DualArrayDeque.Remove(DualArrayDeque.Size()-1);
//	std::cout<<"Value0:"<<Value0<<std::endl<<"Value1:"<<Value1<<std::endl;
	//Test for method 'Clear()'
	DualArrayDeque.Clear();
	DualArrayDeque.PrintInfo();

	return 0;
}
