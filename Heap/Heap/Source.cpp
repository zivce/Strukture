#include "Heap.h"


void main()
{
	int data[7] = { 32,45,66,22,33,100,200 };
	Heap T(7,data);
	T.buildMinHeap(T.getArr());
	
	T.print();


	T.update(32, 100);

	T.print();

	int arr[6] = { 33,45,66,77,22,11 };
	Heap R(6, arr);

	//iz minHeap > opadajuci sortiran
	R.heapSort();
	//R => maxHeap
	cout << "\n";
	R.print();

	//insertion of elements;
	R.maxHeapInsert(99);
	R.maxHeapInsert(100);
	cout << "\n";
	R.print();
	cout << "\n";

	//extraction
	cout << R.maxHeapExtract();
	cout << "\n";
	//R.buildMaxHeap(R.getArr());
	R.print();

	//minHeap >> maxHeap
	R.buildMinHeap(R.getArr());

	cout << "\n";
	R.print();

	//MergeTwoHeaps
	int arr1[6] = { 33,45,66,77,22,11 };
	Heap R1(6, arr1);
	R1.buildMaxHeap(R1.getArr());



	int data1[5] = { 32,45,66,22,33 };
	Heap T1(5, data1);
	T1.buildMaxHeap(T1.getArr());

	Heap K = mergeMaxHeaps(R1, T1);


	cout << "\n";
	K.print();


}