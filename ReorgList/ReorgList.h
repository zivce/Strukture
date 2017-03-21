#pragma once
#include "CReorgNode.h"

class ReorgList {
private:
	RNode* head;
	RNode* tail;
public:
	ReorgList()
	{
		head = tail = nullptr;
	}
	void swap(RNode* prev1, RNode* t1, RNode* prev2, RNode* t2);
	struct node* GetToStart(int key);

	struct node* GetTransp(int key);

	void addToTail(node n)
	{

		RNode* tmp = new RNode(n);

		if (head == nullptr)
		{
			head = tail = tmp;
		}
		else
		{
			tail->link = tmp;
			tail = tmp;

		}


	}
		

	friend ostream& operator<<(ostream& izlaz, ReorgList& tmp)
	{
		RNode* tmpHead = tmp.head;

		while (tmpHead != nullptr)
		{

			izlaz << *tmpHead;
				
			tmpHead = tmpHead->link;
		}
		return izlaz;
	}


};


