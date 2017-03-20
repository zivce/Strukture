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

	ValNode<T>& getElem(int i, int j);


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
	friend ostream& operator<<(ostream& izlaz, MatrixList& tmpM)
	{
		cout << "i j Mat[i][j]\n";

		RowColNode<T>* tmpRow = tmpM.masterRowHead;
		RowColNode<T>* tmpCol = tmpM.masterColHead;

		
		int i = 1;
		int j = 1;
		while (tmpRow->rowOrCol != -1)
		{	//prolazi po redovima row next node se menja
			

			while (tmpCol->rowOrCol != -1)
			{
				
					cout << tmpM.getElem(i,j) << "\n";
				
				tmpCol = tmpCol->nextRowCol;
				j++;
			}

			tmpCol = tmpM.masterColHead;
			i++;
			j = 1;
			tmpRow = tmpRow->nextRowCol;
		}
		return izlaz;
	}
};

template <class T>
ValNode<T>& MatrixList<T>::getElem(int i, int j)
{
	RowColNode<T>* tmpRowHead = masterRowHead;
	RowColNode<T>* tmpColHead = masterColHead;

	ValNode<T>* tmpColValNode;
	ValNode<T>* returnThis;

	while (tmpRowHead->rowOrCol != -1)
	{
			tmpColValNode = tmpRowHead->matNodes;

			while(tmpColValNode)
			{

				if (tmpColValNode->currRow == i && 
					tmpColValNode->currCol == j)
				{
					returnThis = tmpColValNode;
					return *returnThis;
				}

				tmpColHead = tmpColHead->nextRowCol;
				
				tmpColValNode = tmpColValNode->rNextMNode;
			}
			

			tmpRowHead = tmpRowHead->nextRowCol;
	}
		

	//nije nadjen

	return ValNode<T>(i,j, 0);


}

template <class T>
void MatrixList<T>::insertValNode(int m, int n, T val)
{


	ValNode<T>* NoviCvor = new ValNode<T>(m, n, val);

	/*
	+	Traverse to find spot for ValNode
	*/

	RowColNode<T>* tmpColHead = this->masterColHead;
	RowColNode<T>* tmpRowHead = this->masterRowHead;

	while (tmpRowHead->rowOrCol != -1) {

		while (tmpColHead->rowOrCol != -1)
		{

			if (tmpRowHead->rowOrCol == m && tmpColHead->rowOrCol == n)
			{

				/*
				+	Naso je mesto m,n
				+	ako nema elementa na m n dodaj
				+	NoviCvor
				*/
				if (tmpColHead->matNodes == nullptr &&
					tmpRowHead->matNodes == nullptr)
				{
					tmpColHead->matNodes = NoviCvor;
					tmpRowHead->matNodes = NoviCvor;
					return;
				}

				/*
				+	Linkuj ako ima jos neki cvor u
				+	istom redu/koloni!
				*/

				if (tmpColHead->matNodes != nullptr)
				{
					//Znaci da postoji neki element
					//u tmpColHead koloni


					ValNode<T>* tmpColHeadTmp = tmpColHead->matNodes;
					
					//Ima vise elemenata u koloni 
					while (tmpColHeadTmp->cNextMNode != nullptr &&
						tmpColHeadTmp != nullptr)
					{
						tmpColHeadTmp = tmpColHeadTmp->cNextMNode;
					}


					if (tmpColHeadTmp->currRow > NoviCvor->currRow)
					{
						// NoviCvor je ispred onog na koji ukazuje
						//tmpColHead->matNodes
						// => swap

						ValNode<T>* tmpSwap = tmpColHeadTmp;
						tmpColHeadTmp = NoviCvor;
						tmpColHeadTmp->cNextMNode = tmpSwap;
					}
					else
					{
						//NoviCvor je iza onog na koji ukazuje
						// tmpColHead->matNodes
						// => nadovezemo na tmpColHeadTmp < noviCvor
						tmpColHeadTmp->cNextMNode = NoviCvor;

					}

				}

				else
				{
					//samo nadovezemo
					tmpColHead->matNodes = NoviCvor;

				}

				if (tmpRowHead->matNodes != nullptr)
				{
					//Znaci da postoji neki element
					//u tmpRowHead redu


					ValNode<T>* tmpRowHeadTmp = tmpRowHead->matNodes;
					//Ima vise elemenata u koloni 
					// ako je !tmpRowHeadTmp 
					//nema elemenata u tom redu

					while (tmpRowHeadTmp->rNextMNode != nullptr
						&& tmpRowHeadTmp != nullptr)
					{
						tmpRowHeadTmp = tmpRowHeadTmp->rNextMNode;
					}


					if (tmpRowHeadTmp->currCol > NoviCvor->currCol)
					{
						// NoviCvor je ispred onog na koji ukazuje
						//tmpRowHead->matNodes
						// => swap

						ValNode<T>* tmpSwap = tmpRowHeadTmp;
						tmpRowHeadTmp = NoviCvor;
						tmpRowHeadTmp->rNextMNode = tmpSwap;
					}
					else
					{
						//NoviCvor je iza onog na koji ukazuje
						// tmpRowHead->matNodes
						// => nadovezemo na tmpRowHeadTmp < noviCvor
						tmpRowHeadTmp->rNextMNode = NoviCvor;

					}

				}

				else
				{
					//samo nadovezemo
					tmpRowHead->matNodes = NoviCvor;

				}

				return;
				
			}//end nasao je poziciju m i n 

			/*
			+ Spoljna while petlja!
			+
			*/
			tmpColHead = tmpColHead->nextRowCol;
		}

		tmpColHead = masterColHead;
		tmpRowHead = tmpRowHead->nextRowCol;
	}

}



//tmpColTmp = tmpCol;
//tmpColVal = tmpCol->matNodes;
//
//while (tmpCol->rowOrCol != -1)
//{
//
//	//prolazi po kolonama row next node se menja
//	//krene od prvog u koloni 
//
//	if (tmpColVal != nullptr)
//	{
//		izlaz << *tmpColVal << "\n";
//	}
//	else {
//
//		izlaz << tmpRow->rowOrCol << " " << tmpCol->rowOrCol << " " << 0 << "\n";
//
//	}
//	//pomera pointer dalje po redu
//
//	tmpColVal = tmpCol->matNodes->rNextMNode;
//
//	//sledeci head pointer na kolonu
//	tmpCol = tmpCol->nextRowCol;
//	j++;
//}
//i++;
//j = 1;
//tmpCol = tmpM.masterColHead;
//tmpRow = tmpRow->nextRowCol;



/*
+	Ako je noviCvor current column manji od
+	nekog koji je vec u listi onda NoviCvor
+	row Next Node ukazuje na taj Node
+	a pointer na taj cvor se preusmeri na
+	noviCvor
+	u suprotnom taj cvor ukazuje na NoviCvor
+	row next mode od tmpColHead
*/

//if (NoviCvor->currRow < tmpColHeadTmp->matNodes->currRow)
//{
//	NoviCvor->rNextMNode = tmpColHead->matNodes;
//	tmpColHead->matNodes->rNextMNode = NoviCvor;
//
//}
//
//else
//{
//	tmpColHead->matNodes->rNextMNode = NoviCvor;
//}
//
//						}
//
//						tmpColHead = tmpColHead->nextRowCol;
//						//fixiran red prodje po koloni da vidi 
//						//da li ima jos neki element u vrsti!
//
