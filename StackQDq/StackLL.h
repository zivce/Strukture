#pragma once
#include "Node.h"
class StekLL
{
private:
	Node* head;
	Node* tail;
public:

	bool isEmpty() {
		return (head == nullptr);
	}
	~StekLL()
	{
		
	}

	StekLL()
	{
		head = tail = nullptr;
	} 
	int deleteFromHead() {
		if (this->isEmpty())
			return 0;

		int e = head->info;
		
		Node* tmp = head;
		
		head = head->next;
		
		delete tmp;

		return e;
	}


	void addToHead(int a)
	{
		Node* tmp = new Node(a);
		if (head == nullptr)
		{
			head = tmp;
			tail = tmp;
		}
		
		else
		{
			tmp->next = head;
			head = tmp;
		}

	}


	
};