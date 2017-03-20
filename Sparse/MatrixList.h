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
		ValNode<T>* tmpColVal;
		
		int i = 1;
		int j = 1;
		while (tmpRow->rowOrCol != -1)
		{	//prolazi po redovima row next node se menja
			tmpColVal = tmpRow->matNodes;

			while (tmpColVal)
			{
				
					cout << *tmpColVal << "\n";
				
				tmpColVal = tmpColVal->rNextMNode;
				j++;
			}
			i++;
			j = 1;
			tmpRow = tmpRow->nextRowCol;
		}
		return izlaz;
	}
};


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
				+	Linkuj ako ima jos neki cvor u
				+	istom redu/koloni!
				*/


				RowColNode<T>* tmpColHeadTmp = tmpColHead;

				tmpColHead = masterColHead;

				while (tmpColHead->rowOrCol != -1)
				{
					if (tmpColHead->matNodes != nullptr && tmpRowHead->matNodes != nullptr)
					{
						/*
						+	Ako je noviCvor current column manji od
						+	nekog koji je vec u listi onda NoviCvor
						+	row Next Node ukazuje na taj Node
						+	a pointer na taj cvor se preusmeri na
						+	noviCvor
						+	u suprotnom taj cvor ukazuje na NoviCvor
						+	row next mode od tmpColHead
						*/
						if (NoviCvor->currRow < tmpColHead->matNodes->currRow)
						{
							NoviCvor->rNextMNode = tmpColHead->matNodes;
							tmpColHead->matNodes->rNextMNode = NoviCvor;
							
						}

						else
						{
							tmpColHead->matNodes->rNextMNode = NoviCvor;
						}
					}

					tmpColHead = tmpColHead->nextRowCol;
					//fixiran red prodje po koloni da vidi 
					//da li ima jos neki element u vrsti!
				}

				tmpColHead = tmpColHeadTmp;

				RowColNode<T>* tmpRowHeadTmp = tmpRowHead;
				tmpRowHead = masterRowHead;

				while (tmpRowHead->rowOrCol != -1)
				{
					if (tmpRowHead->matNodes != nullptr && tmpColHead->matNodes != nullptr)
					{
						if (NoviCvor->currCol < tmpColHead->matNodes->currCol)
						{
							NoviCvor->cNextMNode = tmpColHead->matNodes;
							tmpColHead->matNodes->cNextMNode = NoviCvor;
							
						}

						else
							tmpColHead->matNodes->cNextMNode = NoviCvor;

					}

					tmpRowHead = tmpRowHead->nextRowCol;
				}

				tmpRowHead = tmpRowHeadTmp;

			
				/*
				+	Dodavanje cvora na poziciju 
				+			  m,n
				+	vvvvvvvvvvvvvvvvvvvvvvvvvv
				*/

				if(tmpRowHead->matNodes == nullptr)
					tmpRowHead->matNodes = NoviCvor;
				else
				{
					/*
					+	Pokusaj lancanja po redu!
					+
					*/
					ValNode<T>* tmpTraverseRow = tmpRowHead->matNodes;

					while (tmpTraverseRow->rNextMNode != nullptr)
					{
						tmpTraverseRow = tmpTraverseRow->rNextMNode;
					}

					tmpTraverseRow = NoviCvor;


				}
				if(tmpColHead->matNodes == nullptr)
					tmpColHead->matNodes = NoviCvor;
				else
				{
					/*
					+	Pokusaj lancanja po koloni!
					+	vvvvvvvvvvvvvvvvvvvvvvvvvv
					*/

					ValNode<T>* tmpTraverseColumn = tmpColHead->matNodes;

					while (tmpTraverseColumn->cNextMNode != nullptr)
					{
						tmpTraverseColumn = tmpTraverseColumn->cNextMNode;
					}

					tmpTraverseColumn = NoviCvor;


				}

				return;

			}
			
			
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