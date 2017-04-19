#pragma once
#include "BNode.h"
#include <iostream>
using namespace std;

class QAsArr
{
protected:
	BNode** niz;
	int sizeOfNiz;
	int first;
	int last;
public:
	int getNumOfElems()
	{
		return (this->sizeOfNiz - first + last);

	}
	


	QAsArr(int a)
	{
		sizeOfNiz = a;
		niz = new BNode*[a];
		for (int i = 0; i < sizeOfNiz; i++)
			niz[i] = nullptr;

		first = last = -1;
		//indexi idu od 0

	}

	bool isFull() {
		return (first == (last + 1) % sizeOfNiz);
	}

	void enq(BNode* a)
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
	BNode* deq() {
		if (isEmpty())
			throw "Prazan niz";

		BNode* tmp = niz[first];
		niz[first] = 0;


		if ( first + 1 == last) 
		{
			first = last = -1;
		}
		else {
			first = (first + 1) % sizeOfNiz;
		}
		

		return tmp;

	}//skida first
	
	
	friend ostream& operator<<(ostream& iz, QAsArr& a)
	{
		for (int i = 0; i < a.sizeOfNiz; i++)
		{
			BNode* tmp = a.niz[i];
			iz << *tmp << " ";
		}
		return iz;
	}

};