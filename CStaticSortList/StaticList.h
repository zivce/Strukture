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
		for (int i = 1; i < tmpList.size; i++)
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

	int tmp = lrmp;
	lrmp = data[lrmp].link;
	data[tmp].info = elem;
	data[tmp].link = head;

	if (head == 0)
	{
		head = tail = 0;
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
	
	for (int i = 1; i < size; i++)
		data[i].link = i + 1;
}
