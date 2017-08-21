#include"arraydeque.h"

using namespace ArrayDeque;

int main(int argc,char **argv)
{
	CArrayDeque<int> ArrayDequeA;
//	ArrayDequeA.PrintInfo();
	//Test for method 'EnqueueE()'
	for(int i=0;i<5;i++)
	{
		ArrayDequeA.EnqueueE(i+100);
	}
	ArrayDequeA.EnqueueF(234);
	ArrayDequeA.EnqueueF(456);
	//Test for method 'Set()'
//	int BackCarrier0{ArrayDequeA.Set(0,200)};
//	int BackCarrier1{ArrayDequeA.Set(ArrayDequeA.Size()-1,300)};
//	std::cout<<BackCarrier0<<std::endl<<BackCarrier1<<std::endl;
	//Test for method 'DequeueF()'
//	int BackCarrier=ArrayDequeA.DequeueF();
//	std::cout<<BackCarrier<<std::endl;
	//Test for method 'DequeueE()'
	int BackCarrier=ArrayDequeA.DequeueE();
	std::cout<<BackCarrier<<std::endl;
	//Test for method 'Clear()'
	ArrayDequeA.Clear();
	ArrayDequeA.PrintInfo();

}


