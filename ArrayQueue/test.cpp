/*
 * filename:test.cpp
 * created at:2017-08-19
 * author:VincentHwuang
 * description:this is a test file 
 */

#include"arrayqueue.h"

using ArrayQueue::CArrayQueue;

int main(int argc,char **argv)
{
	CArrayQueue<int> ArrayQueueA;
//	ArrayQueueA.PrintInfo();
	//Test for function 'Enqueue()'
	for(int i=0;i<5;i++)
	{
		ArrayQueueA.Enqueue(i);
	}
//	ArrayQueueA.PrintInfo();
	//Test for function 'Dequeue()'
//	int BackCarrier=ArrayQueueA.Dequeue();
//	std::cout<<BackCarrier<<std::endl;
//	ArrayQueueA.PrintInfo();
	std::cout<<"Size:"<<ArrayQueueA.Size()<<std::endl;
}
