#pragma once
#include <iostream>
using namespace std;

class QAsArr
{
protected:
	int* niz;
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
		niz = new int[a];
		for (int i = 0; i < sizeOfNiz; i++)
			niz[i] = 0;

		first = last = -1;
		//indexi idu od 0

	}

	bool isFull() {
		return (first == (last + 1) % sizeOfNiz);
	}

	void enq(int a)
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
	int deq() {
		if (isEmpty())
			throw "Prazan niz";

		int tmp = niz[first];
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
	int firstElem();//cita first
	
	
	friend ostream& operator<<(ostream& iz, QAsArr& a)
	{
		for (int i = 0; i < a.sizeOfNiz; i++)
		{
			int tmp = a.niz[i];
			iz << tmp << " ";
		}
		return iz;
	}

};