#include "DynHeap.h"
void main()
{
	try {

	DynHeap T;
	T.insert(45, 0);
	T.insert(2, 0);
	T.insert(4, 0);
	T.insert(1, 0);
	T.insert(3, 0);
	T.insert(5, 0);

	T.print();

	DynHeap P;
	P.insert(30, 0);
	P.insert(10, 0);
	P.insert(11, 0);
	P.insert(100, 0);
	P.insert(40, 0);
	P.insert(70, 0);

	cout << "\n\n";
	P.print();

	T.mergeWith(P);
	cout << "\n\n";
	T.print();


	}

	catch (char* p)
	{
		cout << p;
	}
}