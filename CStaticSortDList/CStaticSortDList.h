#pragma once
#include "Node.h"


template <class T>
class CStaticSortDList {
private :
	int lrmp;
	int size;
	int head, tail;
	StaticNodeDLL<T>* arrData;

public:
	void addToHead(T elem);
	
	CStaticSortDList() {
		lrmp = 0;
		size = 0;
		head = tail = 0;
		arrData = nullptr;

	}

	CStaticSortDList(int maxSize)
	{
		size = maxSize;
		lrmp = 1;
		/*
		+ nullptr je 0
		*/
		head = tail = 0;
		

		arrData = new StaticNodeDLL<T>[size + 1];


		for (int i = 1; i < this->size; i++)
		{
			arrData[i].next = i + 1;
			arrData[i].previous = i - 1;

		}

		arrData[size].next = 0;
		arrData[size].previous = size - 1;


	}

	friend ostream& operator<<(ostream& izlaz, CStaticSortDList& btmp)
	{
		for (int i = btmp.head; i != btmp.tail; i--)
		{
			
			izlaz << btmp.arrData[btmp.arrData[i].previous]<< " < " << btmp.arrData[i] << " > " <<btmp.arrData[btmp.arrData[i].next] << "  ";
		}
		return izlaz;
	}


};

template <class T>
void CStaticSortDList<T>::addToHead(T elem)
{
	if (lrmp == 0)
		return;
	/*
	+ Napunjen rezervisan prostor
	*/

	int tmp = lrmp;
	lrmp = arrData[lrmp].next;


	arrData[tmp].info = elem;
	arrData[tmp].next = head;
	arrData[tmp].previous = 0;
	
	if (head == 0)
	{

		head = tail = tmp;
	}

	else
	{
		arrData[head].previous = tmp;

		head = tmp;
	}

}