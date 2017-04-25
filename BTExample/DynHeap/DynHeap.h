#pragma once
#include "HeapNode.h"
#include <iostream>
#include "QueueAsArr.h"
using namespace std;

class DynHeap
{
private:
	HeapNode* root;
	int size;
public:
	DynHeap()
	{
		root = nullptr;
		size = 0;
	}

	void minHeapify(HeapNode* curr)
	{
		if (curr->parent == nullptr)
			return;
		else
		{
			if (curr->info < curr->parent->info)
			{
				int tmp = curr->info;
				curr->info = curr->parent->info;
				curr->parent->info = tmp;
			}

			minHeapify(curr->parent);
		}


	}

	void maxHeapify(HeapNode* curr)
	{
		if (curr->parent == nullptr)
			return;
		else
		{
			if (curr->info > curr->parent->info)
			{
				int tmp = curr->info;
				curr->info = curr->parent->info;
				curr->parent->info = tmp;
			}

			maxHeapify(curr->parent);
		}


	}

	void mergeWith(DynHeap& a)
	{
		this->merge(a.root,a);

	}
	void merge(HeapNode* t,DynHeap& a)
	{
		if (t != nullptr)
		{
			this->insert(t->info, 0);

			merge(t->left, a);
			merge(t->right, a);
		}
	}



	void print()
	{
		HeapNode* tmp = this->root;
		QAsArr* p = new QAsArr(2 * this->size + 1);

		p->enq(tmp);

		while (tmp != nullptr && !p->isEmpty())
		{

			tmp = p->deq();
			
			cout << tmp->info << " ";

			if (tmp->left != nullptr)
				p->enq(tmp->left);
			if (tmp->right != nullptr)
				p->enq(tmp->right);

		}


	}


	void insert(int a,bool max1OrMin0)
	{
		HeapNode* tmp = this->root;
		QAsArr* t = new QAsArr(10*this->size + 1);
		t->enq(tmp);
		HeapNode* checkFlag = nullptr;

		while (tmp != nullptr)
		{

			//breadthFirst obici za node
			//prvi koji ima 0 flag dodati mu 
			//HeapNode levo ili desno!

			checkFlag = t->deq();
			if (checkFlag->flag == 0)
			{
				tmp = checkFlag;
				break;
			}

			if (tmp->left != nullptr)
				t->enq(checkFlag->left);
			if (tmp->right != nullptr)
				t->enq(checkFlag->right);

		}

		if (tmp == nullptr)
		{
			root = new HeapNode(a);
			root->parent = nullptr;
		}
		else
		{
			if (tmp->left == nullptr)
			{

				tmp->left = new HeapNode(a);
				tmp->left->parent = tmp;
				this->size++;

				if (tmp->right != nullptr && tmp->left != nullptr)
					tmp->flag = 1;

				//min_heapify
				if (max1OrMin0)
					maxHeapify(tmp->left);
				else
					minHeapify(tmp->left);

			}
			else
			{
				tmp->right = new HeapNode(a);
				tmp->right->parent = tmp;
				//flag 1 znaci da njegov bratanac 
				//treba da se proveri 
				//tj po sirini jer je tmp popunjen!
				//da bi heap bio gotovo kompletan

				if (tmp->right != nullptr && tmp->left != nullptr)
					tmp->flag = 1;

				this->size++;
				//min_max_heapify
				if (max1OrMin0)
					maxHeapify(tmp->right);
				else
					minHeapify(tmp->right);
			}
		}
	}


};