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
	int deqTail() {
		if (this->isEmpty())
			throw "Prazan dek";

		//brisanje jedinog elementa
		int a = niz[last-1];
		niz[last - 1] = 0;

		if (last == 0)
		{
			last = sizeOfNiz - 1;
		}
		else
		{
			last = (last - 1) % sizeOfNiz;
		}
		return a;
	}
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
			if (first == 0)
			{
				first = sizeOfNiz - 1;
			}
			else
			{
				first = (first - 1) % sizeOfNiz;
			}
			
			niz[first] = a;
		}
	}

	friend ostream& operator<<(ostream& iz, DeqAsArr& a)
	{
		for (int i = 0; i < a.sizeOfNiz; i++)
		{
			int tmp = a.niz[i];
			iz << tmp << " ";
		}
		return iz;
	}


};