#pragma once
#include "QueueAsArr.h"
class DeqAsArr:public QAsArr {
public:
	DeqAsArr(int len) :QAsArr(len) {
	};
	//iz QAsArr imamo enq i deq 
	
	void enqDq(int a)
	{
		this->enq(a);
	}

	int deqDq() {
		return this->deq();
	}

	// enqHead i deqTail

	void enqHead(int a)
	{
		if (this->isFull())
			throw "full!";

		if (first == last)
		{
			niz[0] = a;
			first = 0;
			last = 1;
		}

		else
		{
			first = (first - 1) % sizeOfNiz;
			niz[first] = a;
		}
	}




};