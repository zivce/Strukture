#pragma once

template <class T>
class ValNode {
	/*
	+Informacije o poziciji,
	+value
	+2 pointera jedan na rNextMNode jedan na cNextMNode
	*/

public:
	T value;
	int currCol; int currRow;
	ValNode<T>* rNextMNode;
	ValNode<T>* cNextMNode;

	ValNode() {
		value = T();
		currCol = -1;
		currRow = -1;
		rNextMNode = nullptr;
		cNextMNode = nullptr;
	}

	ValNode(int i, int j, T val)
	{
		this->currCol = i;
		this->currRow = j;
		this->value = val;
		this->cNextMNode = nullptr;
		this->rNextMNode = nullptr;
	}



};