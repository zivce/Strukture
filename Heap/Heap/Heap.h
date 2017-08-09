#pragma once
#include <iostream>
using namespace std;
#include <climits>

class Heap
{
protected:
	int* arr;
	int length;
	
public:

	/*
	* Heap - nearly complete binary tree
	* leaves: arr[n/2->n-1]
	* non-terminal nodes: 0 -> n/2
	*/
	
	int* getArr()
	{
		return arr;
	}
	void print()
	{

		for (int i = 1; i <= length; i++)
			cout << this->arr[i] << " ";
	}

	void heapSort() {
		//sortira u nerastuci redosled
		
		buildMinHeap(this->arr);
		
		int tmpLen = length;

		
		while (length > 0)
		{
			//dole se smanji length za 1 
			//kad izvlaci!
			this->arr[this->length + 1 ] = minHeapExtract();
		}

		this->length = tmpLen;


	}

	void findNode(int val, int i,int* k)
	{
		if (arr[i] == val)
			*k = i;
		else 
			if (arr[i] < val)
			{
				findNode(val, 2 * i + 1,k);
				findNode(val, 2 * i,k);
			}

	}



	void update(int val, int add)
	{
		
		int k = 0;
		findNode(val, 1, &k);
		
		if (k > 0 && k<=length)
		{
			this->arr[k] += add;
				
			if (arr[k / 2] > arr[k])
			{
				//upheap
				while (k > 0 && arr[k/2] > arr[k])
				{
					int tmp = arr[k / 2];
					arr[k / 2] = arr[k];
					arr[k] = tmp;
				}

			}
			else
			   Min_Heapify(arr, k);


		}
	}


	int minHeapExtract()
	{
		int min = this->arr[1];
		this->arr[1] = this->arr[length];
		length--;
		Min_Heapify(this->arr, 1);
		return min;
	}

	/*
	* min of subtree is in root of subtree
	* data - arr of integers
	* i - index elem of arr
	*/

	void buildMinHeap(int* d)
	{
		for (int i = this->length / 2; i > 0; i--)
			Min_Heapify(d, i);
	}

	void Min_Heapify(int* arr, int i)
	{

		int l = this->left(i);
		int r = this->right(i);
		int smallest = i;

		if (arr[l] < arr[i] && l <= length)
			smallest = l;

		if (arr[r] < arr[smallest] && r <= length)
			smallest = r;

		if (smallest != i)
		{
			int tmp = arr[i];
			arr[i] = arr[smallest];
			arr[smallest] = tmp;
			Min_Heapify(arr, smallest);
		}

	}

	int parent(int i)
	{
		if (i / 2 > 1)
			return i / 2;
	}


	int left(int i)
	{
		if (2 * i <= length)
			return 2 * i;
		
	}

	int right(int i)
	{
		if (2 * i + 1 <= length)
			return 2 * i + 1;
		
	}

	void operator=(Heap& a)
	{
		this->arr = new int[a.length+1];
		this->arr[0] = INT_MIN;
		for (int i = 1; i <= a.length; i++)
			this->arr[i] = a.arr[i];

	}

	Heap(int len)
	{
		this->length = len;
		this->arr = new int[len];
	}

	Heap()
	{
		arr = nullptr;
		length = 0;
	}

	
	Heap(int a,int* data)
	{
		length = a;
		this->arr = new int[length];
		for (int i = 1; i <= this->length; i++)
			this->arr[i] = data[i - 1];
	}

	

	void buildMaxHeap(int* d)
	{
		for (int i = this->length / 2; i > 1; i--)
			Max_Heapify(d, i);
	}


	void Max_Heapify(int* data, int i)
	{
		
			int l = this->left(i);
			int r = this->right(i);
			int largest = i;

			if (data[l] > data[i] && l <= this->length)
				largest = l;

			if (data[r] > data[largest] && l <= this->length )
				largest = r;

			if (largest != i)
			{
				int tmp = data[i];
				data[i] = data[largest];
				data[largest] = tmp;

				//vraca se u roditelja
				Max_Heapify(data, largest);
			}
	
	}


	

	
	/*
	*	MaxHeapInsert O(lg N), MaxHeapExtract O(lg N),MaxHeapMoveUp O(lg N)
	*
	*/
	

	void maxHeapMvUp(int* d,int index, int key)
	{
		d[index] = key;
		
		int p = parent(index);
		
		while (index > 1 && d[p] < d[index])
		{
			int tmp = d[p];
			d[p] = d[index];
			d[index] = tmp;

			//roditelj ubacenog elementa
			index = parent(index);
			//p >> 0!
			p = parent(index);
		}
	}

	int maxHeapExtract()
	{
		int m = this->arr[1];
		this->arr[1] = this->arr[length];
		
		Max_Heapify(this->arr, 1);
		this->length--;
		return m;
	}

	void maxHeapInsert(int a)
	{
		this->extend(1);
		arr[length] = INT_MIN;
		maxHeapMvUp(this->arr, length, a);
	}

	/*
	*	Merge two maxHeap
	*
	*/
	void extend(int b)
	{
		int* d = new int[b + this->length + 1];
		
		for (int i = 1; i <= this->length; i++)
			d[i] = this->arr[i];


		this->length = b + this->length;
		//delete[] arr; 
		// upisivanje nakon zauzete memorije?

		arr = d;


	}

	friend Heap& mergeMaxHeaps(Heap& a, Heap& b)
	{
		Heap tmp = a;

		for (int i = 1; i <= b.length; i++)
			tmp.maxHeapInsert(b.arr[i]);



		return tmp;
	}

};