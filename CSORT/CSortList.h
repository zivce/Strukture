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



	CSortList() {
		head = tail = nullptr;
	}
	Node<T>* getHead() {
		return head;
	}

	void selSort();
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
	void insertSort();

};



template <class T>
void CSortList<T>::insertSort() {


	Node<T>* tPtr1Previous = nullptr;

	Node<T>* tPtr1 = head;

	Node<T>* tPtr2Previous = head;

	Node<T>* tPtr2 = head->link;

	while (tPtr2 != nullptr)
	/*
	+	tPtr2 ide ispred tPtr1 
	+	oznacava kraj sortiranja.
	+	
	+	tPtr1 ide do njega
	+	i trazi manji/veci
	+	od njega.
	+
	+	Ako nadje odradi promenu
	+	ako ne onda pomeri tPtr2
	+	na sledeci.
	+
	*/
	
	{
		tPtr1Previous = nullptr;
		tPtr1 = head;
		while (tPtr1 != tPtr2 && tPtr1->info < tPtr2->info)
		{
			/*
			+ Trazi prvo mesto gde treba da menja
			*/
			tPtr1Previous = tPtr1;
			tPtr1 = tPtr1->link;

		}

		if (tPtr1 != tPtr2)
			/*
			+	Naso je negde iza tPtr2
			+	veci i sad ih zameni.
			+	ako nije naso tPtr2
			+	se pomera.
			+
			*/
		{

			this->swap(tPtr1Previous, tPtr1, tPtr2Previous, tPtr2);
			tPtr2 = tPtr2Previous->link;

		}
		else
		{
			/*
			+	Nije naso jer tPtr2 == tPtr1
			+	Predje na sledeci tPtr2
			+	tPtr1 < RESET na HEAD
			*/


			tPtr2Previous = tPtr2;
			tPtr2 = tPtr2->link;
			}


	}//end_while_ptr2





}




template <class T>
void CSortList<T>::swap(Node<T>* previousA, Node<T>* a, Node<T>* previousB, Node<T>* b) {
	if (a == b)
		return;

	
	
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
	Node<T>* tmp1 = tail;


	/*|||            |||
	vvv outer   loop vvv */

	while(tmp1 != head)
	{

		Node<T>* tmpPeak = head;
		Node<T>* tmpPeakPrevious = nullptr;
		/*|||            |||
		  vvv inner loop vvv */


		while (tmpPeak->link != tmp1)
			/*
			*
			* PEAK DODJE NA PRETPOSLEDNJE MESTO
			* TAD IZADJE IZ PETLJE I ODRADI JOS
			* JEDNU ZAMENU!
			* 
			* IDE DOK NE DODJE DO PRETPOSLEDNJEG U
			* LISTI TAD IZADJE U OUTER PETLJU
			*/
		{
			if (tmpPeak->info > tmpPeak->link->info)
			{
				this->swap(tmpPeakPrevious, tmpPeak, tmpPeak, tmpPeak->link);

				if (tmpPeakPrevious == nullptr)
				{
					tmpPeakPrevious = head;
				}
				else
				{
					tmpPeakPrevious = tmpPeakPrevious->link;
				}
			}
			else
			{
				tmpPeakPrevious = tmpPeak;

				tmpPeak = tmpPeak->link;
			}
		}
			// tmp1 < pretposlednje mesto = novi pretail
			tmp1 = tmpPeak;

			if (tmpPeak->info > tmpPeak->link->info)
			{
				this->swap(tmpPeakPrevious, tmpPeak, tmpPeak, tmpPeak->link);
			}



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


template <class T>
void CSortList<T>::selSort()
{
	Node<T>* xcgFirstPrevious = nullptr;
	Node<T>* xcgFirst = this->head;
	Node<T>* innerTmp = this->head->link;
	Node<T>* innerTmpPrevious = this->head;
	 

	while (xcgFirst != tail)
	
	
	{

		Node<T>* min = xcgFirst;
		Node<T>* minPrev = xcgFirstPrevious;
		
		innerTmp = xcgFirst->link;
		innerTmpPrevious = xcgFirst;

		while (innerTmp != nullptr)
		


		{
			if (innerTmp->info > min->info)

			{


				minPrev = innerTmpPrevious;

				min = innerTmp;
			}

			innerTmpPrevious = innerTmp;
			innerTmp = innerTmp->link;
		}


			if(min != xcgFirst)
			{
				swap(xcgFirstPrevious, xcgFirst, minPrev,min);
				xcgFirst = min;
				cout << *this <<"\n";
			}
		


		xcgFirstPrevious = xcgFirst;
		xcgFirst = xcgFirst->link;

	}
	
	
}