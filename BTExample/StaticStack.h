#pragma once
#include "BNode.h"

class Stek {
	int top;
	BNode** stackElems;
	int size;
public:

	~Stek() {
		delete[] stackElems;
	}


	bool isEmpty() {
		return (this->top < 0);
	}

	BNode* topElem()
	{
		//ne brise ga
		if (this->top < 0)
			throw "Underflow";

		BNode* tmp = stackElems[top];
		return tmp;

	}

	Stek(int asize)
	{
		top = -1;
		stackElems = new BNode*[asize];
		for (int i = 0; i < asize; i++)
			stackElems[i] = nullptr;

		this->size = asize;

	}

	void push(BNode* a)
	{
		if (top == size-1)
			throw "Overflow!";
		top = top + 1;
		stackElems[top] = a;
	}

	BNode* pop()
	{
		if (top < 0)
			throw "Underflow";
		BNode* tmp = stackElems[top];
		top = top - 1;
		return tmp;
	}


};