#pragma once
#include "Node.h"



//			[LINKED  LIST  WITH  SPARSE  MATRIX  NODE]


template <class T>
class List {

private:

	Node<T> * head;

public:

	List();

};

template<class T>
inline List<T>::List()
{
	head = NULL;
}
