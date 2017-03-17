#include "CSortList.h"
#include <iostream>
using namespace std;

void main() {
	try {
		CSortList<int>* A = new CSortList<int>();
	
		A->isEmpty();
		A->addToHead(3);
		A->addToHead(4);
		A->addToHead(2);

		// 2-->4-->3


		Node<int>* TMP0 = A->getHead();
		
		Node<int>* TMP1 = A->getHead()->link;
		
		Node<int>* TailPrev = A->getHead();

		cout << *A << "\n";

		A->swap(nullptr,TMP0, TMP0,TMP1);

		cout << *A;

	
	//	A->bubbleSort();


	}
	catch (char* p)
	{
		cout << p;
	}
}