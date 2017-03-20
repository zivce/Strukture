#pragma once
#include <iostream>
using namespace std;

template <class T>
class ValNode {
	/*
	+Informacije o poziciji,
	+value
	+2 pointera jedan na rNextMNode jedan na cNextMNode
	*/

public:
	T value; int currRow;
	int currCol;
	ValNode<T>* rNextMNode;
	ValNode<T>* cNextMNode;
	

	bool operator!=(ValNode<T>& tmpk)
	{
		bool p = (this->currCol != tmpk.currCol && this->currRow != tmpk.currRow);
		return p;


	}

	ValNode() {
		value = T();
		currCol = -1;
		currRow = -1;
		rNextMNode = nullptr;
		cNextMNode = nullptr;
	}

	ValNode(int i, int j, T val)
	{
		this->currRow = i;
		this->currCol = j;
		this->value = val;
		this->cNextMNode = nullptr;
		this->rNextMNode = nullptr;
	}


	friend ostream& operator<<(ostream& izlaz, ValNode<T>& b)
	{
		izlaz << b.currRow << " " << b.currCol << " " << b.value ;

		return izlaz;
	}
};