#pragma once
#include "Elements.h"
#include <iostream>
using namespace std;

class QAsArr
{
protected:
	LNode** niz;
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
		niz = new LNode*[a];
		for (int i = 0; i < sizeOfNiz; i++)
			niz[i] = nullptr;

		first = last = -1;
		//indexi idu od 0

	}

	bool isFull() {
		return (first == (last + 1) % sizeOfNiz);
	}

	void enq(LNode* a)
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
	LNode* deq() {
		if (isEmpty())
			throw "Prazan niz";

		LNode* tmp = niz[first];
		niz[first] = new LNode();


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