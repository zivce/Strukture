#include "BTree.h"
#include <iostream>
using namespace std;

void main()
{
	try {
		BTree T;
		T.insert(2);
		T.insert(5);
		T.insert(6);
		T.insert(4);
		T.insert(3);

		T.search(3);

		/*T.inOrder(T.getR());
		T.postOrder(T.getR());
		*/

		//T.preOrder(T.getR());

		//T.itPostOrder();


		//T.breadthFirst();
		
		T.itPreOrder();

	}
	catch (char* p)
	{
		cout << p;
	}
}