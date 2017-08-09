

#include <random>
#include <vector>
using namespace std;


/*
* count = broj elemenata u niz
* start = index start niz
* a = niz

* p = upper to je index prvog pre pivot 
* elementa
* q = lower , to je index prvog elementa 
* posle pivot elementa
* x = pivot element
* j = obilazak kroz niz sve do q 

* rekurzivni pozivi:  
* za levi deo koji krece od start
* i duzine je p-start + 1  

* za desni deo koji krece od q 
* posle pivot elementa
* i duzine je count - (q-start) 
* count je duzina niza a q je index!!!

*/
void quickSort(int a[], int start, int count)
{
	if (count <= 1) 
		return;//izlaz iz rekurzije!

	default_random_engine gen;
	uniform_int_distribution<int> dist(start, start+count-1);

	int x = a[dist(gen)];

	int p = start - 1;
	int j = start;
	int q = start + count;


	while (j < q)
	{
		int comp = (a[j] - x);

		if (comp > 0)
		{
			int tmp = a[j];
			
			q--;
			
			a[j] = a[q];

			a[q] = tmp;
		
		}
		else if (comp < 0)
		{
			int tmp = a[j];
			p++;

			a[j] = a[p];

			a[p] = tmp;

			j++;
		}
		else
			j++;
	}
	quickSort(a, start, p - start + 1);
	quickSort(a, q, count - (q - start));
}




void merge(int* a, int first, int last)
{
	int len = last - first + 1;
	int* tmp = new int[len];
	int mid = (first +last) / 2;
	int i = 0;
	int i0 = first;
	int i1 = mid + 1;

	while (i0 <= mid && i1 <= last)
	{
		if (a[i0] < a[i1])
		{
			tmp[i++] = a[i0++];
		}
		else
		{
			tmp[i++] = a[i1++];
		}

	}

	while (i0 <= mid)
		tmp[i++] = a[i0++];

	while (i1 <= last)
		tmp[i++] = a[i1++];

	copy(tmp, tmp + len, a+first);

}

void mergeSort1(int* a, int first, int last)
{
	int len = last - first + 1;

	if (len == 1)
		return;
	
	if (len == 2)
	{
		if (a[first] > a[last])
		{
			int tmp = a[first];
			a[first] = a[last];
			a[last] = tmp;
		}
		return;
	}

	int mid = (first + last) / 2;

	mergeSort1(a, first, mid);
	mergeSort1(a, mid + 1, last);

	merge(a, first, last);

}

void mergesort(int* niz, int dim)
{
	mergeSort1(niz, 0, dim - 1);
}






void main()
{
	
	int niz[] = {1, 2, 23, 4, 5, 6, 2, 1};
	

	//copy(niz + 1, niz + 2, nizCopyDst);

	mergesort(niz, 8);

	//quickSort(niz, 0, 8);

	return;

}