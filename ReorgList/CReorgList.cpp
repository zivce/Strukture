#include "ReorgList.h"
void ReorgList::swap(RNode* prev1, RNode* t1, RNode* prev2, RNode* t2)
{
	if (t2 == nullptr || t1 == nullptr)
		throw "los unos";

	if (prev1 == nullptr)
	{
		//dodajemo na head
		head = t2;
	}
	else {
		prev1->link = t2;
	}


	if (prev2 == nullptr)
	{
		//dodajemo na head

		head = t1;

	}
	else {
		prev2->link = t1;
	}

	RNode* tmp = t1->link;
	t1->link = t2->link;
	t2->link = tmp;


	while (tail->link != nullptr)
	{
		tail = tail->link;
	}
}
struct node* ReorgList::GetToStart(int aKey)
{
	node* tmp = new node();

	RNode* tmpNode = this->head;
	RNode* tmpNodePrev = nullptr;

	while (tmpNode != nullptr)
	{

		if (tmpNode->t.key == aKey)
		{
			tmp = &tmpNode->t;
			this->swap(nullptr,head, tmpNodePrev, tmpNode);
			return tmp;
		}
		tmpNodePrev = tmpNode;
		tmpNode = tmpNode->link;
	}
	

}

struct node* ReorgList::GetTransp(int aKey)
{
	node* tmp = new node();

	RNode* t1 = this->head;
	RNode* t1Prev = nullptr;

	RNode* t2Prev = nullptr;
	// posto su susedi t2 = t1Prev
	//
	while (t1 != nullptr)
	{

		if (t1->t.key == aKey)
		{
			tmp = &t1->t;
			this->swap(t2Prev, t1Prev, t1Prev, t1);
			return tmp;
		}

		t2Prev = t1Prev;
		t1Prev = t1;
		t1 = t1->link;
	}


}