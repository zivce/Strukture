#include "CStaticSortDList.h"


void main() {
	CStaticSortDList<int> A();


	CStaticSortDList<int> B(5);

	B.addToHead(2);


	B.addToHead(1);


	B.addToHead(3);


	B.addToHead(120);


	B.addToTail(2);

	cout << B << "\n";


	B.deleteFromTail();
	B.deleteFromTail();

	B.deleteFromTail();
	
	cout << B << "\n";
	
	B.addToHead(312);
	
	cout << B << "\n";
	
	B.addToHead(89);
	
	cout << B << "\n";
	
	B.addToTail(54);
	
	cout << B << "\n";
	/*
	+ Ovaj deo ne dodaje u listu LRMP pun!
	*/
	B.addToHead(1);
	B.addToHead(62);
	B.addToTail(646);

	cout << B << "\n";


	B.deleteFromHead();
	B.deleteFromHead();
	cout << B << "\n";

	B.bubbleSort();



}