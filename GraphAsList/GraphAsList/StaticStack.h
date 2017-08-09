#pragma once
#include "Elements.h"

class Stek {
	int top;
	LNode** stackElems;
	int size;
public:

	~Stek() {
		delete[] stackElems;
	}


	bool isEmpty() {
		return (this->top < 0);
	}

	LNode* topElem()
	{
		//ne brise ga
		if (this->top < 0)
			throw "Underflow";

		LNode* tmp = stackElems[top];
		return tmp;

	}

	Stek(int asize)
	{
		top = -1;
		stackElems = new LNode*[asize];
		for (int i = 0; i < asize; i++)
			stackElems[i] = nullptr;

		this->size = asize;

	}

	void push(LNode* a)
	{
		if (top == size-1)
			throw "Overflow!";
		top = top + 1;
		stackElems[top] = a;
	}

	LNode* pop()
	{
		if (top < 0)
			throw "Underflow";
		LNode* tmp = stackElems[top];
		top = top - 1;
		return tmp;
	}


};