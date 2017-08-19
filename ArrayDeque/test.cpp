#include"arraydeque.h"

using namespace ArrayDeque;

int main(int argc,char **argv)
{
	CArrayDeque<int> ArrayDequeA;
//	ArrayDequeA.PrintInfo();
	//Test for function 'EnqueueE()'
	for(int i=0;i<5;i++)
	{
		ArrayDequeA.EnqueueE(i+100);
	}
	ArrayDequeA.EnqueueF(234);
	ArrayDequeA.PrintInfo();
}


