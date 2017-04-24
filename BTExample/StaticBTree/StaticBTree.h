#pragma once
#include <math.h>
#include <iostream>
using namespace std;
#define NEVALIDNA (-42)

class SBTree
{
private:
	int* arr;
	int len;
	int countNodes = 0;
public:
	~SBTree()
	{
		if (arr)
			delete[] arr;
	}
	SBTree()
	{
		arr = nullptr;
	}

	SBTree(int leng)
	{
		//za 1 vise jer od 1 krece!
		this->len = leng+1;
		arr = new int[this->len];
		for (int i = 0; i < this->len; i++)
			arr[i] = NEVALIDNA;
	}

	void print()
	{
		for (int i = 1; i < len; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}


	int parent(int i)
	{
		return i / 2;
	}
	int left(int i)
	{
		return 2 * i;
	}
		

	int right(int i)
	{
		return 2 * i + 1;	
	}

	void insert(int a)
	{
		if (a == NEVALIDNA)
			return;

		int i = 1;

		while (arr[i] != NEVALIDNA && 
			i < this->len)

			if (arr[i] < a)
				i = right(i);
			else
				i = left(i);

		if (i < this->len)
		{
			arr[i] = a;
			countNodes++;
		}
		else
			return;

	}

	int diffNodes();

	void mirrorTree()
	{
		if (arr[1] == NEVALIDNA)
			throw "prazno";
		if (arr[2] == NEVALIDNA && arr[3] == NEVALIDNA)
			throw "already mirror!";
		
		mirror(1);


	}


	int  maxLvl()
	{
		int countNodes = 0;
		int currLvl = 1;

		//default
		int maxLvl = 0;
		int maxNodes = 1;

		//dokle se broje cvorovi!
		int upperBoundary = pow((double)2, (double)(this->heightTree() + 1));

		int i = 2;

		int j = 2;

		while (i < upperBoundary)
		{

			int endOfLvl = pow((double)2, (double)(currLvl+1));
			
			while (j < endOfLvl)
			{
				if (arr[j] != NEVALIDNA)
					countNodes++;
				j++;
			}

			if (maxNodes < countNodes)
			{
				maxNodes = countNodes;
				maxLvl = currLvl;
			}

			//j predje u novi nivo
			countNodes = 0;
			currLvl++;
			
			i = j;

		}

		return maxLvl;
	}

	void merge(SBTree& a)
	{
		int upperBoundary = pow((double)2, (double)(a.heightTree() + 1));

		for (int i = 1; i < upperBoundary;i++)
		{
			this->insert(a.arr[i]);
		}

	}

	void mirror(int a)
	{
		if (arr[a] != NEVALIDNA)
		{
			mirror(left(a));
			mirror(right(a));

			int tmp = arr[left(a)];
			arr[left(a)] = arr[right(a)];
			arr[right(a)] = tmp;
		}
	}

	void deleteAllLeaves()
	{
		if (arr[1] == NEVALIDNA)
			throw "prazno stablo";

		int height = this->heightTree();
		deleteLeaves(1);

	}

	void deleteLeaves(int a)
	{
		if (a < this->len)
		{

			if (arr[left(a)] == NEVALIDNA && arr[right(a)] == NEVALIDNA)
			{
				arr[a] = NEVALIDNA;
			}
			else
			{
				deleteLeaves(left(a));
				deleteLeaves(right(a));
			}

		}

	}

	
	int heightTree()
	{
		return height(1);

	}
	int height(int a)
	{
		if (a < this->len)
		{
			if (arr[a] == NEVALIDNA)
				return -1;
			else
			{
				//nadje max!
				if (height(left(a)) > height(right(a)))

					return 1 + height(left(a));
				else
					return 1 + height(right(a));
			}
		}

		else
		{
			return -1;
		}
		
	}


	int size()
	{
		return countNodes;
	}

	int leavesTree()//tezina
	{

	}



};