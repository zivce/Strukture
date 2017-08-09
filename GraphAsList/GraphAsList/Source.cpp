#include "GList.h"
#include <iostream>
using namespace std;

void main()
{
	GList* Graph1 = new GList();
	
	Graph1->addNode('A');
	Graph1->addNode('B');
	Graph1->addNode('C');
	Graph1->addNode('D');
	
	Graph1->insertEdge('A', 'B', 2);
	Graph1->insertEdge('A', 'C', 4);
	
	//Graph1->insertEdge('B', 'C', 5);

	Graph1->insertEdge('D', 'A', 4);
	Graph1->insertEdge('D', 'B', 2);



	/*Graph1->isCyclic();

	Graph1->getNeighbMatrix();


	Graph1->breadthFirstSrch();

	Graph1->depthFirstSrch();
	Graph1->delNode('A');*/


	//Graph1->deleteEdge('D', 'A');


	//Graph1->topologicalSort();
	//0 - in
	//1- out
	cout << "\nMax inDegree nodes\n";

	cout << Graph1->maxDegree(0);
	
	cout << "\nMax outDegree nodes\n";

	cout << Graph1->maxDegree(1);

	cout << "\n!Transposed\n";

	Graph1->depthFirstSearch();

	cout << "\nTransposed\n";

	GList* a = Graph1->transpose();

	a->depthFirstSearch();

	Graph1->isWeaklyConnected();

	Graph1->isStronglyConnected();


	/*
	* Provera 
	* isStronglyConnected!
	*/


	GList* Graph2 = new GList();

	Graph2->addNode('A');
	Graph2->addNode('B');
	Graph2->addNode('C');
	Graph2->addNode('D');

	Graph2->insertEdge('A', 'B', 2);
	Graph2->insertEdge('A', 'C', 4);

	Graph2->insertEdge('B', 'C', 5);

	Graph2->insertEdge('D', 'A', 4);
	
	Graph2->insertEdge('C', 'D', 4);
	
	cout << "\n";

	//cout << Graph2->isStronglyConnected();
	

	//Graph2->getNeighborsMatrix();

	Graph2->isWeaklyConnected();
	Graph2->isStronglyConnected();

}

