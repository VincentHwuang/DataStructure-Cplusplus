#include"rootisharraystack.h"

using RootishArrayStack::CRootishArrayStack;

int main(int argc,char **argv)
{
	CRootishArrayStack<int> RootishArrayStack;
	//Test for method 'Add()'
	for(int i=0;i<10;i++)
	{
		RootishArrayStack.Add(i,i);
	}
//	RootishArrayStack.PrintInfo();
	//Test for method 'Size()'
//	std::cout<<RootishArrayStack.Size()<<std::endl;
	//Test for method 'Get()'
//	int Value0=RootishArrayStack.Get(0);
//	int Value1=RootishArrayStack.Get(RootishArrayStack.Size()-1);
//	std::cout<<Value0<<std::endl<<Value1<<std::endl;
	//Test for method 'Set()'
	RootishArrayStack.Set(0,100);
	RootishArrayStack.Set(RootishArrayStack.Size()-1,200);
	//Test for method 'Remove()'
//	int Value0=RootishArrayStack.Remove(0);
//	int Value1=RootishArrayStack.Remove(RootishArrayStack.Size()-1);
//	std::cout<<Value0<<std::endl<<Value1<<std::endl;
	//Test for method 'Clear()'
	RootishArrayStack.Clear();
	RootishArrayStack.PrintInfo();

	return 0;
}
