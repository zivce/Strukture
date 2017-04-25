#pragma once
#include "HeapNode.h"
#include <iostream>
using namespace std;

class QAsArr
{
protected:
	HeapNode** niz;
	int sizeOfNiz;
	int first;
	int last;
public:

	~QAsArr()
	{
		if (niz != nullptr)
		{
			
			for (int i = 0; i < this->sizeOfNiz; i++)
			{
				if(niz[i]!=nullptr)
					delete niz[i];
			}

			delete[] niz;
		}
	}

	int getNumOfElems()
	{
		return (this->sizeOfNiz - first + last);

	}
	


	QAsArr(int a)
	{
		sizeOfNiz = a;
		niz = new HeapNode*[a];
		for (int i = 0; i < sizeOfNiz; i++)
			niz[i] = nullptr;

		first = last = -1;
		//indexi idu od 0

	}

	bool isFull() {
		return (first == (last + 1) % sizeOfNiz);
	}

	void enq(HeapNode* a)
	{
		if (isFull())
			throw "pun niz";

		if (first == last)
		{
			niz[0] = a;
			first = 0;
			last = 1;
			
		}
		else 
		{
			this->niz[last] = a;
			last = (last+1) % sizeOfNiz;

		}

	}

	bool isEmpty()
	{
		return (first == last);

	}
	HeapNode* deq() {
		if (isEmpty())
			throw "Prazan niz";

		HeapNode* tmp = niz[first];
		niz[first] = new HeapNode();


		if ( first + 1 == last) 
		{
			first = last = -1;
		}
		else {
			first = (first + 1) % sizeOfNiz;
		}
		

		return tmp;

	}//skida first
	
	
	

};