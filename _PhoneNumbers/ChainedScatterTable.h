#pragma once
#include "HashTable.h"
#include <iostream>
using namespace std;

class CScatterTable : public HashTable
{
private:
	HashObj** arr;
public:
	CScatterTable(int len)
	{
		length = len;
		count = 0;
		arr = new HashObj*[length];

		for (int i = 0; i < length; i++)
		{
			arr[i] = new HashObj();
		}

	}

	void print(int a, int b) {
		for (int i = a; i < b; i++)
		{
			cout << "[" << i << "]" <<
				arr[i]->getKey();
			HashObj* tmp = arr[i]->next;
			while (tmp != nullptr)
			{
				cout << "-->" << arr[i]->next->getKey();
				tmp = tmp->next;
			}
			cout << "\n";

			delete tmp;
		}

	}

	unsigned int find(int key)
	{
		unsigned int p = h(key);
		if (arr[p]->status == 2)
		{
			return p;
		}
		else if(arr[p]->status == 1)
		{//ako je brisan element ostaju sinonimi
			return p;
		}
		else
		{
			return 0U;
		}
	}
	void addToTail(unsigned int a, HashObj* t)
	{
		HashObj* tail = arr[a];
		while (tail->next != nullptr)
			tail = tail->next;

		t->next = nullptr;
		tail->next = t;
	}

	void removeFromHead(unsigned int a) {
		HashObj* tmp = this->arr[a];
		
		if (arr[a]->next != nullptr)
		{
			arr[a] = arr[a]->next;
			arr[a]->status = 1;
			delete tmp;
		}
		else
		{
			arr[a]->setKey(0);
			arr[a]->status = 0;
			//nema elementa samo je jedan

		}

		
	}

	void remove(int key) {
		unsigned int removeThis = h(key);
		if (arr[removeThis]->status == 2 ||
			arr[removeThis]->status == 1)
			{
				this->removeFromHead(removeThis);
			}

	}
	void insert(int key)
	{
		HashObj* t = new HashObj(key);
		unsigned int indx = h(*t);
		
		if (arr[indx]->status == 2 ||
			arr[indx]->status == 1)
		{
			//sinonim dodamo na tail
			this->addToTail(indx,t);
			return;
		}
			//ako je status = 0
			cout << indx << "\n";	
			arr[indx]->setKey(key);
			arr[indx]->next = nullptr;
			arr[indx]->status = 2;
		
	}
};