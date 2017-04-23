#pragma once
#include <iostream>
using namespace std;
#include <climits>

class Heap
{
protected:
	int* array;
	int length;
	
public:

	/*
	* Heap - nearly complete binary tree
	* leaves: array[n/2->n-1]
	* non-terminal nodes: 0 -> n/2
	*/
	
	int* getArr()
	{
		return array;
	}
	void print()
	{

		for (int i = 1; i <= length; i++)
			cout << this->array[i] << " ";
	}

	void heapSort() {

		buildMinHeap(this->array);
		int tmpLen = this->length;

		for (int i = this->length; i >= 2; i--)
		{
			//extracting min >> a[i]
			int tmp = this->array[i];
			this->array[i] = this->array[1];
			this->array[1] = tmp;

			this->length--;

			//na kraju je min na prvom mestu 
			//poslednja iteracija je visak
			
			if(i!=2)
				this->Min_Heapify(this->array, 1);
			//samo prvi nije minimum!
		}
		this->length = tmpLen;
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
		this->array = new int[a.length+1];
		this->array[0] = INT_MIN;
		for (int i = 1; i <= a.length; i++)
			this->array[i] = a.array[i];

	}

	Heap(int len)
	{
		this->length = len;
		this->array = new int[len];
	}

	Heap()
	{
		array = nullptr;
		length = 0;
	}

	
	Heap(int a,int* data)
	{
		length = a;
		this->array = new int[length];
		for (int i = 1; i <= this->length; i++)
			this->array[i] = data[i - 1];
	}

	/*
	* Min_Heapify - fix of one violation
	* recursively bottom up.
	* min of subtree is in root of subtree
	* data - array of integers
	* i - index elem of array
	*/

	void Min_Heapify(int* data, int i)
	{
		if (i > 0)
		{
			int l = this->left(i);
			int r = this->right(i);
			int smallest = i;

			if (data[l] < data[i])
				smallest = l;

			if (data[r] < data[smallest])
				smallest = r;

			if (smallest != i)
			{
				int tmp = data[i];
				data[i] = data[smallest];
				data[smallest] = tmp;

			}
			//vraca se u roditelja
			Min_Heapify(data,i/2);
		}
	}

	void buildMaxHeap(int* d)
	{
		for (int i = this->length / 2; i > 1; i--)
			Max_Heapify(d, i);
	}


	void Max_Heapify(int* data, int i)
	{
		if (i > 0)
		{
			int l = this->left(i);
			int r = this->right(i);
			int largest = i;

			if (data[l] > data[i])
				largest = l;

			if (data[r] > data[largest])
				largest = r;

			if (largest != i)
			{
				int tmp = data[i];
				data[i] = data[largest];
				data[largest] = tmp;

			}
			//vraca se u roditelja
			Max_Heapify(data, i / 2);
		}
	}


	void buildMinHeap(int* d)
	{
		for (int i = this->length / 2; i > 1;i--)
			Min_Heapify(d, i);
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
		int m = this->array[1];
		this->array[1] = this->array[length];
		this->length--;
		Max_Heapify(this->array, 1);
		return m;
	}

	void maxHeapInsert(int a)
	{
		this->extend(1);
		array[length] = INT_MIN;
		maxHeapMvUp(this->array, length, a);
	}

	/*
	*	Merge two maxHeap
	*
	*/
	void extend(int b)
	{
		int* d = new int[b + this->length + 1];
		
		for (int i = 1; i <= this->length; i++)
			d[i] = this->array[i];


		this->length = b + this->length;
		//delete[] array; 
		// upisivanje nakon zauzete memorije?

		array = d;


	}

	friend Heap& mergeMaxHeaps(Heap& a, Heap& b)
	{
		Heap tmp = a;

		for (int i = 1; i <= b.length; i++)
			tmp.maxHeapInsert(b.array[i]);



		return tmp;
	}

};