#pragma once
class Stek {
	int top;
	char* stackElems;
	int size;
public:

	~Stek() {
		delete[] stackElems;
	}


	bool isEmpty() {
		return (this->top < 0);
	}

	int topElem()
	{
		//ne brise ga
		if (this->top < 0)
			throw "Underflow";

		char tmp = stackElems[top];
		return tmp;

	}

	Stek(int asize)
	{
		top = -1;
		stackElems = new char[asize];
		this->size = asize;

	}

	void push(char a)
	{
		if (top == size-1)
			throw "Overflow!";
		top = top + 1;
		stackElems[top] = a;
	}

	char pop()
	{
		if (top < 0)
			throw "Underflow";
		char tmp = stackElems[top];
		stackElems[top] = 0;
		top = top - 1;
	}


};