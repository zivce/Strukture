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

	//void remove(int key)
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