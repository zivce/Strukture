#include "StaticBTree.h"

void main()
{
	try 
	{
		SBTree T(20);

		T.insert(2);
		T.insert(4);
		T.insert(1);
		T.insert(10);
		T.insert(3);

		cout << "\n";
		T.print();

		cout << "\n";
		T.maxLvl();

		cout << "\n";
		T.print();
		T.mirrorTree();
		cout << "\n";
		T.print();
		
		SBTree M(10);
		M.insert(5);
		M.insert(2);
		M.insert(6);

		T.merge(M);
		cout << "\n";
		T.print();

		

	}
	catch (char* p)
	{
		cout << p;
	}
}