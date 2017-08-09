#include "GList.h"
#include "QueueAsArr.h"
#include "StaticStack.h"

#include <iostream>
using namespace std;

int** GList::getNeighborsMatrix()
{
	QAsArr* que = new QAsArr(this->countNodes);

	int** t = new int*[this->countNodes];

	for (int i = 0; i < this->countNodes; i++)
	{
		t[i] = new int[countNodes];
	}
	
	for (int i = 0; i < this->countNodes; i++)
	{
		for (int j = 0; j < this->countNodes;j++)
			t[i][j] = 0;
	}

	LNode* ptr = this->start;
	Edge* curr = ptr->izlGrana;
	//Breadth First!

	que->enq(ptr);
	
	
	//i zavisi koji je cvor u pitanju!

	int i;
	int j = 0;

	while (!que->isEmpty())
	{
		i = 0;
		ptr = que->deq();

		LNode* s = this->start;
		
		while (s != ptr)
		{
			i++;
			s = s->next;
		}

		if (!ptr->visited)
		{
			ptr->visited = true;
			curr = ptr->izlGrana;
			//j prolazi kroz sve grane
			//da nadje susede
			while (curr != nullptr)
			{
				j = 0;
				que->enq(curr->dstNode);

				LNode* s = this->start;

				//nadje koji je po redu cvor!
				while (s != curr->dstNode)
				{
					j++;
					s = s->next;
				}

				t[i][j] = 1;


				cout << "\n";
				this->printMatrix(t, countNodes, countNodes);
				cout << "\n";
				
				curr = curr->nextBranch;

			}
		}
	}

	return t;
}

void GList::printMatrix(int** mat,int i,int j)
{
	for (int k = 0; k < i; k++)
	{
		for (int l = 0; l < j; l++)
			cout << mat[k][l] << " ";
		cout << "\n";
	}
}

void GList::topologicalSort()
{
	QAsArr* que = new QAsArr(this->countNodes);

	LNode* ptr = this->start;
	
	/*
	* Obidje sve cvorove sa 
	* inDegree == 0
	*/
	while (ptr != nullptr)
	{
		if (ptr->inDegree == 0)
			que->enq(ptr);

		ptr = ptr->next;
	}
	//ako ima ciklusa u grafu 
	// topOrdNum != this->countNodes!
	//tj nemoguc je topOrder

	int topOrderNumOfVisited = 0;

	while (!que->isEmpty())
	{
		
		
		ptr = que->deq();
		topOrderNumOfVisited++;
		cout << ptr->symbol << " ";

		/*
		* prodji kroz sve susede ptr
		* smanji im inDegree za 1;
		*
		*/

		Edge* tmp = ptr->izlGrana;
		
		while (tmp != nullptr)
		{
			tmp->dstNode->inDegree--;
			
			//ubaci ga u que ako je inDegree
			//== 0
			
			if (tmp->dstNode->inDegree == 0)
				que->enq(tmp->dstNode);

			tmp = tmp->nextBranch;
		}




	}
	//que is empty!

	if (topOrderNumOfVisited != this->countNodes)
		cout << "nije moguce topoloski sort!";
	else
		return;
}

bool GList::deleteEdge(char a, char b)
{
	LNode* previous = nullptr;

	Edge* ptr = findEdge(a, b);
	//da nadjemo taj poteg i da prelancamo!
	if (ptr == nullptr)
		return false;

	LNode* ptra = findNode(a, previous);
	
	Edge* prev = ptra->izlGrana;
	//sigurno postoji grana
		while (prev != ptr)
		{
			prev = prev->nextBranch;
		}


	prev->nextBranch = ptr->nextBranch;
	
	ptr->dstNode->inDegree--;
	ptra->outDegree--;


	delete ptr;
	ptr = nullptr;

	return true;
}


Edge* GList::findEdge(char a, char b)
{
	LNode* previous = nullptr;
	LNode* ptra = findNode(a,previous);
	LNode* ptrb = findNode(b,previous);

	if (ptra == nullptr || ptrb == nullptr)

	{
		cout << "not added";
		return nullptr;
	}
	Edge* ptr = ptra->izlGrana;

	while (ptr->dstNode != ptrb)
	{
		ptr = ptr->nextBranch;
	}

	if (ptr->dstNode == ptrb)
		return ptr;
	else
		return nullptr;


}

string GList::maxDegree(bool in0out1)
{
	string a;
	
	LNode* ptr = this->start;
	

	//maxInDeg
	int maxDegree = intFindMaxDegree(in0out1);

	LNode** maxArr = new LNode*[countNodes];

	for (int i = 0; i < countNodes; i++)
		maxArr[i] = nullptr;

	//ako ima ciklus onda svi imaju maxDegree 1 
	//npr


	int i = 0;
	while (ptr != nullptr)
	{
		if (in0out1 == 0)
		{

			if (ptr->inDegree == maxDegree)
			{
				maxArr[i] = ptr;
				i++;
			}

		}
		else
		{
			if (ptr->outDegree == maxDegree)
			{
				maxArr[i] = ptr;
				i++;
			}


		}


		ptr = ptr->next;
	}

	i = 0;

	while (maxArr[i] != nullptr)
	{
		a += maxArr[i]->symbol;
		a += " ";

		i++;
	}


	return a;
}

int GList::intFindMaxDegree(bool in0out1)
{
	LNode* tmp = this->start;
	int maxDeg = 0;

	while (tmp != nullptr)
	{
		if(in0out1 == 0)
			if (tmp->inDegree > maxDeg)
				maxDeg = tmp->inDegree;
		
		if(in0out1 == 1)
			if (tmp->outDegree > maxDeg)
				maxDeg = tmp->outDegree;


		tmp = tmp->next;
	}
	return maxDeg;

}

//a srcNode 
//b dstNode 

void GList::insertEdge(char a, char b, int w)
{
	LNode* previous = nullptr;
	LNode* ptra = findNode(a, previous);
	LNode* ptrb = findNode(b, previous);

	if (ptra == nullptr || ptrb == nullptr)

	{
		cout << "not added";
		return;
	}
	

	Edge* newEdge = new Edge(w);
	
	//add to head
	newEdge->nextBranch = ptra->izlGrana;
	ptra->izlGrana = newEdge;

	newEdge->dstNode = ptrb;
	
	//dstNode inDeg ++ 
	ptrb->inDegree++;

	//srcNode outDeg++
	ptra->outDegree++;

}

void GList::addNode(char b)
{
	LNode* r = new LNode(b);
	
	if (this->start == nullptr)
	{
		this->start = r;
		return;
	}
	
	LNode* tmp = this->start;
	
	while (tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = r;
	this->countNodes++;
	return;

}


LNode* GList::findNode(char a,LNode* prev) {

	prev = nullptr;
	LNode* ptr = this->start;

	while (ptr != nullptr && ptr->symbol != a)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	return ptr;
}


int GList::depthFirstSearch()
{
	int r = 0;

	Stek* a = new Stek(this->countNodes);
	LNode* ptr = this->start;
	string b;

	a->push(ptr);

	while (!a->isEmpty())
	{
		ptr = a->pop();
		

		if (!ptr->visited)
		{
			ptr->visited = true;
		
			b += ptr->symbol;
			b += " ";
			r++;


			Edge* ptrNext = ptr->izlGrana;

			//nabacamo susede

			while (ptrNext != nullptr)
			{
				a->push(ptrNext->dstNode);
				
				ptrNext = ptrNext->nextBranch;
			}

		}
	}

	
	cout << b;
	return r;
}

/*
* Transpose a graph
* a -> b
* b -> a
*/
GList* GList::transpose()
{
	GList* transpThis = new GList();

	transpThis->countNodes = this->countNodes;

	LNode* tmp = this->start;

	while (tmp != nullptr)
	{
		//ako je vec dodat ne treba!
		LNode* previous = nullptr;
		if (!transpThis->findNode(tmp->symbol,previous))
		{
			transpThis->addNode(tmp->symbol);

		
		}
		//proveriti u svakom slucaju izlazne grane

			Edge* incidentBranch = tmp->izlGrana;
			

			while (incidentBranch)
			{
				LNode* previous = nullptr;
				if (!transpThis->findNode(incidentBranch->dstNode->symbol,previous))
					transpThis->addNode(incidentBranch->dstNode->symbol);
				
					
				transpThis->insertEdge(incidentBranch->dstNode->symbol, tmp->symbol, incidentBranch->tezina);
				
				
				incidentBranch = incidentBranch->nextBranch;
			}

		
		

		tmp = tmp->next;
	}

	

	return transpThis;
}




void GList::delNode(char a)
{
	LNode* prev = nullptr;
	LNode* tmp = findNode(a,prev);

	if (tmp == nullptr)
		return;

	//postoji cvor a
	Edge* prevEdge = nullptr;
	Edge* travEdge = nullptr;
	LNode* tmpNode = this->start;

	while (tmpNode != nullptr)
	{
		//obidji sve potege i obrisi dst
		//gde je dst = a;

		travEdge = tmpNode->izlGrana;
		prevEdge = nullptr;

		while (travEdge != nullptr)
		{
			if (travEdge->dstNode->symbol == a)
			{
				Edge* forDeletion = travEdge;

				if (prevEdge == nullptr)
				{
					//brisanje sa head lancane liste
					tmp->izlGrana = forDeletion->nextBranch;
				}
				else
				{
					prevEdge->nextBranch = forDeletion->nextBranch;
				}

				//delete forDeletion;
				//zasto ne brise!!



			}//if_matched_with_node

			prevEdge = travEdge;
			travEdge = travEdge->nextBranch;
		}//While_There_Are_OutEdges_For_This_Node

		tmpNode = tmpNode->next;
	}//For_Each_Node_In_Graph

	//prelancaj u listi cvorova!
	
	if (prev == nullptr)
	{
		this->start = tmp->next;

	}
	else
		prev->next = tmp->next;
	
	//delete tmp;


}

bool GList::checkIfAllVisited()
{
	LNode* tmp = this->start;
	
	while (tmp != nullptr)
	{
		if (tmp->visited == false)
			return false;
		tmp = tmp->next;
	
	}
	return true;
}

void GList::setUnvisited()
{
	LNode* t = this->start;
	while (t != nullptr)
	{
		t->visited = false;
		t = t->next;
	}
	return;

}
void GList::setStatus0()
{
	LNode* t = this->start;
	while (t != nullptr)
	{
		t->status = 0;
		t = t->next;
	}
	return;

}

bool GList::isStronglyConnected()
{
	//obidje za svaki cvor DFS
	//ako ne obidje sve nije 
	//Strongly Connected.

	LNode* t = this->start;
	int r;
	
	while (t != nullptr)
	{
		cout << "\n";
		r = this->depthFirstSearch();

		cout << "\n";

		if (r != this->countNodes)
		{
			return false;
		}

		this->setUnvisited();

		t = t->next;
	}

	return true;

}

bool GList::isCyclic()
{
	
	//ForEach go through adjacent til 
	// you get to the starting point !
	LNode* tmp = this->start;

	while (tmp != nullptr)
	{
		if (this->thruAdjNodesTilBackEdge(tmp))
			return true;


		this->setUnvisited();
		this->setStatus0();
		tmp = tmp->next;
	}

	return false;
}



bool GList::thruAdjNodesTilBackEdge(LNode* tmp)
{
	if (tmp->status == 2)
	{

		tmp->visited = true;

		tmp->status = 2;

		Edge * tmpEdge = tmp->izlGrana;

		while (tmpEdge != nullptr)
		{
			if (thruAdjNodesTilBackEdge(tmpEdge->dstNode))
			{
				return true;
			}
			else
				return false;

			tmpEdge = tmpEdge->nextBranch;
		}
	}
	else
		return true;
}
bool GList::isWeaklyConnected()
{
	//mozda samo grane da se doda i suprotan smer?

	this->depthFirstSrch();

	if (this->checkIfAllVisited())
	{
		cout << "Slabo povezan";
		return true;
	}
	else
		cout << "Nepovezan!";
	return false;
}


void GList::depthFirstSrch()
{
	

}


void GList::breadthFirstSrch()
{
	QAsArr* q = new QAsArr(this->countNodes);

	LNode* tmp = nullptr;
	Edge* edg = nullptr;
	tmp = this->start;
	q->enq(tmp);

	while (!q->isEmpty())
	{
		tmp = q->deq();

		if (!tmp->visited)
		{
			tmp->visited = true;

			cout << tmp->symbol << " ";
			edg = tmp->izlGrana;
			while (edg != nullptr)
			{

				q->enq(edg->dstNode);

				edg = edg->nextBranch;
			}
		}
	}
}

int** GList::getNeighbMatrix()
{
	//init neighb mat
	int** mat = nullptr;
	
	mat = new int*[this->countNodes];

	for (int i = 0; i < this->countNodes; i++)
		mat[i] = new int[this->countNodes];
	
	for (int i = 0; i < this->countNodes; i++)
		for (int j = 0; j < this->countNodes; j++)
			mat[i][j] = 0;
	
	//init nodes arr

	elemNodesList* niz = new elemNodesList[this->countNodes];

	LNode* tmp = this->start;
	
	int i = 0;

	while (tmp != nullptr)
	{
		
		niz[i].index = i;
		niz[i].sym = tmp->symbol;
		
		i++;
		tmp = tmp->next;
	}


	tmp = this->start;
	i = 0;
	while (tmp != nullptr)
	{
		Edge * tmpEdg = tmp->izlGrana;

		//find in elemsNodesList index!
		while (tmpEdg != nullptr)
		{
			int k = 0;
			
			while(tmpEdg->dstNode->symbol != niz[k].sym)
			{
				k++;
			}
			
			mat[i][k] = 1;

			tmpEdg = tmpEdg->nextBranch;
		}


		i++;
		tmp = tmp->next;
	}

	this->printMatrix(mat, this->countNodes, this->countNodes);
	return mat;
}