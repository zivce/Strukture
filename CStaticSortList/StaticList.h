#pragma once
#include "StaticNode.h"


template <class T>
class SLList {
private:
	int size;	
	int head, tail;
	int lrmp;
	NodeStatic<T>* data;
public:
	SLList();
	SLList(int n);

	~SLList() {
		if (data != nullptr)
			delete[] data;
	}

	void addToHead(T info);
	friend ostream& operator<<(ostream& izlaz, SLList& tmpList) {
		for (int i = tmpList.head; i != 0; i = tmpList.data[i].link)
		/*
		+	Krene od head
		+	pomera se za po link 
		+	dok ne dodje do i == 0
		+	tj nullptr
		*/
		
		
		{
			izlaz << tmpList.data[i];

		}
		return izlaz;

	}
};


template <class T>
void SLList<T>::addToHead(T elem) {
	if (lrmp == 0)
		return;

	/*
	+ New node vv
	+
	+ ako lrmp dobije 
	+ 0 == nullptr
	+ kraj return;
	*/

	int tmp = lrmp;
	lrmp = data[lrmp].link;

	/*
	+ dodajemo novi na head
	*/
	data[tmp].info = elem;
	data[tmp].link = head;

	/*
	+ ako nema elemenata u listi
	+ i head i tail ukazuju na novi
	+ tmp 
	+ ako ima onda head ukazuje na tmp
	+
	*/

	if (head == 0)
	{
		head = tail = tmp;
	}
	else 
	{
		head = tmp;

	}
}

template <class T>
SLList<T>::SLList() {
	size = 0;
	head = tail = 0;
	lrmp = 0;
	data = nullptr;

}


template <class T>
SLList<T>::SLList(int n) {
	size = n;
	head = tail = 0;
	
	lrmp = 1;

	//od jedan krece zauzimanje prostora
	data = new NodeStatic<T>[size + 1];
	
	for (int i = 0; i < size; i++)
		data[i].link = i + 1; 

	this->data[size].link = 0;
}
