#include "CStaticSortDList.h"


void main() {
	CStaticSortDList<int> A();


	CStaticSortDList<int> B(5);

	B.addToHead(2);


	B.addToHead(1);


	B.addToHead(3);


	B.addToHead(120);


	B.addToTail(2);



	cout << B;

}