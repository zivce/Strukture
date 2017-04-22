#pragma once
#include "BNode.h"
#include "QueueAsArr.h"
#include <math.h>
using namespace std;
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


	void balance(int* arr, int first, int last)
	{
		if (first < last)
		{
			int mid = (first + last) / 2;
			this->insert(arr[mid]);
			balance(arr, first, mid);
			balance(arr, mid + 1, last);
		}


	}
	void insert(int elem);
	
	BNode* search(int elem);
	
	void inOrderArr(BNode* ptr,int* data,int* i);
	///inorder data, counter
	void inOrder(BNode* ptr);
	void postOrder(BNode* ptr);
	void preOrder(BNode* ptr);

	void itPostOrder();//iterativni postOrder!
	void breadthFirst();
	void itPreOrder();
	void inItOrder();

	void findAndDeleteMerge(int elem);
	void delByMerge(BNode* t);
	void delByCopy(BNode* t);

	/*
	*	Lab5 metode!
	*
	*/
	void breadthFirstArr(int* arr)
	{
		int i = 1;

		QAsArr T(2*(int)pow((double)2, (double)this->heightTree()+1));

		BNode* tmp = this->root;

		if (tmp != nullptr)
		{
			T.enq(tmp);

			while (i < (int)pow((double)2, (double)this->heightTree()+1))
			{
				tmp = T.deq();

				arr[i++] = tmp->info;

				if (tmp->left && tmp)
					T.enq(tmp->left);
				else
					T.enq(new BNode(0));

				if (tmp->right && tmp)
					T.enq(tmp->right);
				else
					T.enq(new BNode(0));
			}
		}
	}

	void maxLvl()
	{

		int maxSize = (int)pow((double)2, (double)this->heightTree()+1);
		int* data = new int[maxSize];

		this->breadthFirstArr(data);
		
		int maxLvl = 0; int maxNodes = 1;

		//i je granica dokle ide j
		int i = 4;
		//krece od nivoa 1
		int currLvl = 1;
		//j se seta po nivoima
		int j = 2;

		while (j < maxSize)
		{
			
			int count = 0;
			while (j < i)
			{
				if (data[j]>0)
					count++;
				j++;
			}

			if (count > maxNodes)
			{
				maxNodes = count;
				maxLvl = currLvl;
			}

			//prelazi na sledeci nivo
			currLvl++;
			//counter se prebaci na sl nivo
			i = (int)pow((double)2, ((double)currLvl+1));
		}
		cout << "max level: " << maxLvl << " num of nodes: " << maxNodes;
	}
	
	
	void mergeTrees(BTree& a, BTree b)
	{
		int m = a.treeSize();
		int n = b.treeSize();
		int* arr = new int[m+n];
		int i = 0;
		a.inOrderArr(a.root, arr, &i);
		b.inOrderArr(b.root, arr, &i);

		for (int i = 0; i < m + n - 1; i++)
			for (int j = m + n - 1; j > i;j--)
				if (arr[j] < arr[j - 1])
				{
					int tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}


		this->balance(arr, 0, m + n - 1);


	}
	


	void mirrorTree() {
		if (!root)
		{
			cout << "empty";
			return;
		}

		if (!root->left && !root->right)
		{
			cout << "nothing to mirror!";
			return;
		}
		mirror(this->root);
	
	}

	void mirror(BNode* t)
	{
		if (t != nullptr)
		{
			mirror(t->left);
			mirror(t->right);

			BNode* tmp = t->left;
			t->left = t->right;
			t->right = tmp;

		}


	}

	void deleteAllLeaves()
	{
		if (root->left == nullptr && root->right == nullptr)
			delete root;

		deleteLeaves(nullptr,root);
	}

	void deleteLeaves(BNode* pre,BNode* t) {
		
		//ground case obrada lista

		if(t != nullptr && t->right == nullptr && t->left == nullptr)
		{
			
			if(pre!=nullptr)
			{
				if (pre->right == t)
				{
					delete t;
					pre->right = nullptr;
					
				}
				else if (pre->left == t)
				{
					delete t;
					pre->left = nullptr;	
				}
				countNodes--;
			}
		}
		else
		{
			if (t != nullptr)
			{
				deleteLeaves(t, t->left);
				deleteLeaves(t, t->right);

			}
		}
	}


	int weightTree()
	{
		return weight(this->root);
	}

	int weight(BNode* t)
	{
		if (t != nullptr)
			if (!t->left && !t->right)
			{
				//Ground case t->left == null && t->righ == null
				return 1;
			}

			else
			{
				return weight(t->left) + weight(t->right);
			}
		else
			//nullptr nema decu :/
			return 0;
	}

	int diffNodesTree()
	{
		int i = 0;
		int count = size(this->root);
		int* data = new int[count];

		inOrderArr(this->root, data, &i);

		int rez = 1;


		for (int i = 0; i < count; i++)
		{

			int j = i + 1;
			//preskoci sve jednake
			while (data[i] == data[j])
				j++;

			if (j != i + 1)
				i = j;

			rez++;

		}

		return rez;
	}



	int size(BNode* t);

	int treeSize() {
		return size(this->root);
	}

	int heightTree()
	{
		return height(this->root);
	}

	int height(BNode* tmp)
	{
		if (tmp == nullptr)
			return -1;
		else
		{
			int leftH = height(tmp->left);
			int rightH = height(tmp->right);

			if (leftH > rightH)
				return 1 + leftH;
			else
				return 1 + rightH;
		}
	}


};