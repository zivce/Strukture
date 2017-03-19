#pragma once
#include "Node.h"


template <class T>
class CStaticSortDList {
private :
	int lrmp;
	int size;
	int head, tail;
	StaticNodeDLL<T>* arrData;

public:
	CStaticSortDList() {
		lrmp = 0;
		size = 0;
		head = tail = 0;
		arrData = nullptr;

	}

	CStaticSortDList(int maxSize)
	{
		size = maxSize;
		lrmp = 1;
		/*
		+ nullptr je 0
		*/
		head = tail = 0;

		for (int i = 1; i < this->size; i++)
		{
			arrData[i].next = i + 1;
			arrData[i].previous = i - 1;

		}

		arrData[size].next = 0;
		arrData[size].previous = size - 1;


	}




};