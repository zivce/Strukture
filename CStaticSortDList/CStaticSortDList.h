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
	void addToTail(T elem);

	T deleteFromHead();
	T deleteFromTail();

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


		for (int i = 1; i <= this->size; i++)
		{
			arrData[i].next = i + 1;
			arrData[i].previous = i - 1;

		}

		arrData[size].next = 0;
		arrData[size].previous = size - 1;


	}

	friend ostream& operator<<(ostream& izlaz, CStaticSortDList& btmp)
	{
		int i = btmp.head;
		while (i != btmp.tail)
		{
			izlaz << btmp.arrData[btmp.arrData[i].previous] << " < " << btmp.arrData[i] << " > " << btmp.arrData[btmp.arrData[i].next] << "  ";
			i = btmp.arrData[i].next;
		}
		/*
		+ odstampa i tail;
		*/
		izlaz << btmp.arrData[btmp.arrData[i].previous] << " < " << btmp.arrData[i] << " > " << btmp.arrData[btmp.arrData[i].next] << "  ";

		return izlaz;
	}

	void bubbleSort();

};


template <class T>
void CStaticSortDList<T>::bubbleSort()
{
	/*
	+ Rastuci 
	*/

	int tmpHead = head;

	while (tmpHead != tmpTail)
	{
		/*
		+
		+
		+
		+
		*/



	}


}

template <class T>
T CStaticSortDList<T>::deleteFromHead()
{

	if (head == 0)
		return T();

	/*
	+ Vratimo u LRMP memorijski prostor tail-a
	*/

	int tmp = head;
	/*
	+  return data[tmp]
	*/




	if (head == tail)
	{
		head = tail = 0;
	}
	else
	{

		head = arrData[head].next;
		arrData[head].previous = 0 ;
	}

	T el = arrData[tmp].info;
	arrData[tmp].previous = 0;
	arrData[tmp].next = lrmp;
	lrmp = tmp;

	return el;

}

template <class T>
T CStaticSortDList<T>::deleteFromTail()
{
	if (tail == 0)
		return T();
	
	/*
	+ Vratimo u LRMP memorijski prostor tail-a
	*/


	arrData[tail].info = 0;
	arrData[tail].next = lrmp;

	this->lrmp = tail;



	T el = arrData[tail].info;

	tail = arrData[tail].previous;
	arrData[tail].next = 0;
	
	if (head == tail)
	{
		head = tail = 0;
	}


	return el;
}



template <class T>
void CStaticSortDList<T>::addToTail(T elem)
{
	if (lrmp == 0)
		return;


	int tmp = lrmp;
	lrmp = arrData[lrmp].next;

	arrData[tmp].info = elem;
	arrData[tmp].next = 0;
	arrData[tmp].previous = tail;

	if (tail == 0)
	{
		head = tail = tmp;

	}
	else {

		arrData[tail].next = tmp;
		tail = tmp;

	}

}



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