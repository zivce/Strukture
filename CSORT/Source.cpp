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


		A->swap(nullptr,TMP0, TMP0,TMP1);


		A->addToHead(8);
		A->addToHead(10);
		A->addToHead(114);


		cout << *A << "\n";;


		A->selSort();

		cout << *A << "\n";




	/*	A->bubbleSort();

		cout << *A << "\n";*/


		

	}
	catch (char* p)
	{
		cout << p;
	}
}