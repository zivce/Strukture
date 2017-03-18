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


	void bubbleSort(bool rastuciOpadajuci);

	SLList();
	SLList(int n);

	~SLList() {
		if (data != nullptr)
			delete[] data;
	}
	void swap(NodeStatic<T> a, NodeStatic<T> b)
	{
		T tmp; int tmplink;
		tmp = a.info;
		tmplink = a.link;
		
		a.info = b.info;
		a.link = b.link;

		b.info = tmp;
		b.link = tmplink;
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
void SLList<T>::bubbleSort(bool p)

{
	if (p)
	{
		NodeStatic<T> tmp1;
		tmp1.link = tail;

		while (tmp1.info != this->data[head].info)

		{
			/*
			+ peak se update
			+ ako nadje nekog koji
			+ je veci od 
			+ od njega ako 
			+ ne nastavlja do
			+ pretposlednjeg
			+ i onda se swap sa
			+ njim
			+
			*/
			NodeStatic<T> tmpPeak(this->data[head]);
			//nullptr
			NodeStatic<T> tmpPeakPrevious(0);

			while (tmpPeak.link != tmp1)
			{
				if (tmpPeak.info > data[tmpPeak.link].info)
				{
					this->swap(tmpPeak, data[tmpPeak.link]);

					if (tmpPeakPrevious.link == 0)
					{
						tmpPeakPrevious.link = head;
					}
					else
					{
						tmpPeakPrevious = this->data[tmpPeakPrevious.link];
					}

				}
				else
				{
					tmpPeakPrevious = tmpPeak;
					tmpPeak = this->data[tmpPeak.link];
				}


			}
			tmp1 = tmpPeak;

			if (tmpPeak.info > data[tmpPeak.link].info)
			{
				this->swap(tmpPeak, data[tmpPeak.link]);
			}


		}





	}





}

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
