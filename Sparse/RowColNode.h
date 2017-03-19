#pragma once
#include "ValNode.h"

template <class T>
class RowColNode {
	/*
	+ Pointer for Matrix Nodes
	*/
public:
	int rowOrCol;
	ValNode<T>* matNodes;
	RowColNode<T>* nextRowCol;

	RowColNode() {
		rowOrCol = -1;
		this->matNodes = nullptr;
		this->nextRowCol = nullptr;
	}
	RowColNode(int r,ValNode<T>* a,RowColNode<T>* b) {
		this->rowOrCol = r;
		this->matNodes = a;
		this->nextRowCol = b;
	
	}

};
