#pragma once
#include "Node.h"
using std::cout;
using std::endl;


// [SPARSE  MATRIX  WITH  SINGLY  LINKED  LISTS]


template <class T>
class Matrix {

private:
	
	Node<T> ** rowLists;
	Node<T> ** colLists;
	int rows; // [number of rows]
	int columns; // [number of columns]

public:

	Matrix(int, int);
	~Matrix();
	void Set(int, int, T);
	T GetByRows(int, int);
	T GetByColumns(int, int);

	void Print();
	
};

template<class T>
inline Matrix<T>::Matrix(int n, int m)
{
	rows = n;
	columns = m;
	rowLists = new Node<T>*[n];
	colLists = new Node<T>*[m];

	for(int i = 0; i < n; i++) rowLists[i] = NULL;
	for(int i = 0; i < m; i++) colLists[i] = NULL;
}

template<class T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < this->rows; i++)
	{
		Node<T> * tmp1 = rowLists[i];
		Node<T> * forDel;

		while (tmp1 != NULL)
		{
			forDel = tmp1;
			tmp1 = tmp1->nextRow;
			delete forDel;
		}
	}

	delete[] rowLists;
	delete[] colLists;
}

template<class T>
inline void Matrix<T>::Set(int i, int j, T el)
{
	Node<T> * forSet = new Node<T>(i, j, el);
	Node<T> * tmp = rowLists[i];
	Node<T> * prev = NULL;

	// [ULANCAVANJE  U  RED]

	while (tmp != NULL && j > tmp->j)
	{
		prev = tmp;
		tmp = tmp->nextRow;
	}

	if (tmp != NULL && tmp->j == j)//[IZMENA POSTOJECEG CVORA]
	{
		tmp->info = el;
		delete forSet;
		return;
	}
	else //[DODAVANJE CVORA]
	{
		if (prev != NULL)
		{
			prev->nextRow = forSet;
		}
		else
		{
			rowLists[i] = forSet;
		}
		forSet->nextRow = tmp;
	}

	//[ULANCAVANJE U KOLONU]

	tmp = colLists[j];
	prev = NULL;

	while (tmp != NULL && i > tmp->i)
	{
		prev = tmp;
		tmp = tmp->nextColumn;
	}
	
	if (prev != NULL)
	{
		prev->nextColumn = forSet;
	}
	else
	{
		colLists[j] = forSet;
	}
	forSet->nextColumn = tmp;
}

template<class T>
inline T Matrix<T>::GetByRows(int i, int j)
{
	Node<T> * tmp = rowLists[i];

	while (tmp != NULL && tmp->j < j)
	{
		tmp = tmp->nextRow;
	}

	if (tmp == NULL || tmp->j != j) return 0;
	return tmp->info;
}

template<class T>
inline T Matrix<T>::GetByColumns(int i, int j)
{
	Node<T> * tmp = colLists[j];
	while (tmp != NULL && tmp->i < i)
	{
		tmp = tmp->nextColumn;
	}

	if (tmp != NULL && tmp->i == i) return  tmp->info;
	return 0;
}

template<class T>
inline void Matrix<T>::Print()
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {
			cout << this->GetByRows(i, j) << "  ";
		}

		cout << endl;
	}
}
