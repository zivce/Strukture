#pragma once
#include <iostream>


//   [SPARSE  MATRIX  NODE]


template <class T>
class Node {

public:

	int i;//		[ROW]
	int j;//		[COL]
	T info;
	Node<T> * nextRow;
	Node<T> * nextColumn;

public:

	Node(int, int, T, Node<T> *, Node<T> *);
	Node(int, int, T);
};

template<class T>
inline Node<T>::Node(int ind_i, int ind_j, T el, Node<T>* rowPtr, Node<T>* colPtr)
{
	i = ind_i;
	j = ind_j;
	info = el;
	nextRow = rowPtr;
	nextColumn = colPtr;
}

template<class T>
inline Node<T>::Node(int ind_i, int ind_j, T el)
{
	i = ind_i;
	j = ind_j;
	info = el;
	nextRow = NULL;
	nextColumn = NULL;
}
