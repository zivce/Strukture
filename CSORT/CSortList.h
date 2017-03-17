#pragma once
#include "CSortNode.h"

template <class T>
class CSortList {
private:
	Node<T>* head;
	Node<T>* tail;
public:

	friend ostream& operator<<(ostream& izlaz, CSortList& A)
	{
		Node<T>* tmp = A.getHead();
		while (tmp != nullptr) {
			izlaz << *tmp;

			tmp = tmp->link;
		}

		return izlaz;
	}


	void xchangeInfo(Node<T>* a, Node<T>* b)
	{
		//ako su susedi
		T infoTmp = T();
		infoTmp = a->info;
		a->info = b->info;
		b->info = infoTmp;

	}

	CSortList() {
		head = tail = nullptr;
	}
	Node<T>* getHead() {
		return head;
	}


	Node<T>* getTail() {
		return tail;
	}


	void swap(Node<T>* previousA,Node<T>* a, Node<T>* previousB, Node<T>* b);

	void bubbleSort();
	void addToHead(T A);

	void deleteFromHead();

	bool isEmpty() {
		return (head == nullptr);
	}

	~CSortList() {

		while (!isEmpty()) {

			deleteFromHead();

		}

	}

	void sortList(bool arg);

};

template <class T>
void CSortList<T>::swap(Node<T>* previousA, Node<T>* a, Node<T>* previousB, Node<T>* b) {
	if (a == b)
		return;

	if (a->link == b || b->link == a)
	{
		this->xchangeInfo(a, b);
		return;
	}
	
	if (previousA == nullptr)
	{
		head = b;
	
	}
	else
	{
		previousA->link = b;
	}

	if (previousB == nullptr)
	{
		head = a;
		
	}
	else
	{
		previousB->link = a;
 
	}

	Node<T>* tmp = a->link;
	a->link = b->link;
	b->link = tmp;

	while (tail->link != nullptr)
	{
		tail = tail->link;
	}
}


template <class T>
void CSortList<T>::bubbleSort() {
	Node<T>* tmp1 = this->tail;
	
	Node<T>* tmp0 = head;
	Node<T>* tmpHd = head->getLink();

	while(tmp0 != nullptr)
	{

		while (tmpHd != tmp1)
		{
			//unutrasnja petlja



		}

	}

}


template <class T>
void CSortList<T>::sortList(bool arg)
{
	T** arr;
	int n = 0;
	Node<T>* TMP = this->head;

	while (TMP != nullptr)
	{
		n++;
		TMP = TMP->getLink();
	}

	arr = new T*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new T();


	TMP = this->head;
	int i = 0;
	while (TMP != nullptr) {

		arr[i] = new T(TMP->getInfo());

		i++;
		TMP = TMP->getLink();
	}


	if (arg)
		//arg == true rastuci
	{
		for (int i = 0; i < n; i++){
			for (int j = n - 1; j > i; j--)
			{
				T* tmp = nullptr;
				if(*arr[j] < *arr[j-1])
				{
					tmp = arr[j];
					arr[j] = arr[j-1];
					arr[j-1] = tmp;

				}

			}//end_for_j

		}//end_for_i
	}


}


template <class T>
void CSortList<T>::deleteFromHead() {
	if (isEmpty())
		throw "PRAZNA LISTA!";

	Node<T>* TMP = head;

	head = head->getLink();

	delete TMP;


}

template <class T>
void CSortList<T>::addToHead(T A) {

	head = new Node<T>(A, head);

	if (tail == nullptr)
		tail = head;
}