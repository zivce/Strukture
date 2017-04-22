#include "BTree.h"
#include <iostream>
using namespace std;

void main()
{
	try {
		BTree T;
		T.insert(2);
		T.insert(10);
		T.insert(10);
		T.insert(4);
		T.insert(3);
		T.insert(10);
		T.insert(1);
		T.insert(1);
		T.insert(5);



		BTree M;
		M.insert(2);
		M.insert(1);
		M.insert(50);
		M.insert(40);
		M.insert(30);

		M.maxLvl();


		BTree K;
		K.mergeTrees(T, M);




		/*

		T.mirrorTree();



		T.deleteAllLeaves();

		T.weightTree();


		T.diffNodesTree();


		T.treeSize();

		T.heightTree();

		T.findAndDeleteMerge(6);

		T.breadthFirst();

		 T.search(3);

		T.inOrder(T.getR());
		T.postOrder(T.getR());
		

		T.preOrder(T.getR());

		T.itPostOrder();


		T.breadthFirst();
		
		T.itPreOrder();
		T.inItOrder();
		*/



	}
	catch (char* p)
	{
		cout << p;
	}
}