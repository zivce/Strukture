#pragma once
#include "RowColNode.h"
#include "ValNode.h"


template <class T>
class MatrixList{
	

	RowColNode<T>* masterRowHead;
	RowColNode<T>* masterColHead;

	int totalRows, totalCols;
public:

	void insertValNode(int i, int j, T val);
	
	void insertMatrix(T** Matrix);
	
	MatrixList() {
		masterRowHead = nullptr;
		masterColHead = nullptr;
		totalCols = totalRows = 0;
	}
	void addToColHead(RowColNode<T>* b)
	{
		if (masterColHead == nullptr)
		{
			masterColHead = b;
			return;
		}

		b->nextRowCol = this->masterColHead;
		masterColHead = b;


	}
	void addToRowHead(RowColNode<T>* a)
	{
		if (masterRowHead == nullptr)
		{
			/*
			+ prazna lista;
			*/
			masterRowHead = a;
			return;
		}
		
		
		a->nextRowCol = masterRowHead;
		masterRowHead = a;
		
	}


	MatrixList(int milan, int nikola)
	{
		this->totalCols = nikola;
		this->totalRows = milan;

		masterRowHead = new RowColNode<T>();
		masterColHead = new RowColNode<T>();

		/*
		+	masterRowHead je head liste za pointere
		+	na elemente redova
		+	masterColHead je head liste za pointere
		+	na elemente kolona
		*/

		for (int i = milan; i >0; i--)
		{
			RowColNode<T>* slaveRowHead = new RowColNode<T>(i, nullptr, nullptr);
			this->addToRowHead(slaveRowHead);
		}

		for (int i = nikola; i > 0; i--)
		{
			RowColNode<T>* slaveColHead = new RowColNode<T>(i, nullptr, nullptr);
			this->addToColHead(slaveColHead);
		}
		


	}

};

//template <class T>
//void MatNod<T>::insertValNode(int m, int n, T val)
//{
//	
//
//	ValNode<T>* NoviCvor = new ValNode<T>(m,n,val);
//
//	/*
//	+ rowsNodes[m] = header m-tog reda
//	+ colsNodes[n] = header n-te kolone
//	*/
//
//	rowsNodes[m]->matNode = NoviCvor;
//	colsNodes[n]->matNode = NoviCvor;
//
//}