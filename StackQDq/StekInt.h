#pragma once
#pragma once
class StekI {
	int top;
	int* stackElems;
	int size;
public:

	~StekI() {
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

		int tmp = stackElems[top];
		return tmp;

	}

	StekI(int asize)
	{
		top = -1;
		stackElems = new int[asize];
		this->size = asize;

	}

	void push(int a)
	{
		if (top == size - 1)
			throw "Overflow!";
		top = top + 1;
		stackElems[top] = a;
	}

	int pop()
	{
		if (top < 0)
			throw "Underflow";
		int tmp = stackElems[top];
		stackElems[top] = 0;
		top = top - 1;
		return tmp;
	}


};