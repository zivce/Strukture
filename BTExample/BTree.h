#pragma once
#include "BNode.h"
class BTree
{
private:
	BNode* root;
	int countNodes;
public:
	BNode* getR()
	{
		return root;
	}
	BTree()
	{
		root = nullptr;
		countNodes = 0;
	}
	~BTree() {
		deleteTree(root);
		
	}
	void deleteTree(BNode* ptr)
	{
		if (ptr != nullptr)
		{
			deleteTree(ptr->left);
			deleteTree(ptr->right);
			delete ptr;
		}
	};


	void insert(int elem);
	BNode* search(int elem);
	void inOrder(BNode* ptr);
	void postOrder(BNode* ptr);
	void preOrder(BNode* ptr);

	void itPostOrder();//iterativni postOrder!

	void breadthFirst();

	void itPreOrder();

};