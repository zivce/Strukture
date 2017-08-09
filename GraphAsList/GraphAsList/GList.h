#pragma once
#include "Elements.h"

#include <string>
struct elemNodesList
{
	char sym;
	int index;

};


class GList
{
protected:
	LNode* start;
	int countNodes;
public:
	
	int intFindMaxDegree(bool in0out1);



	GList()
	{
		start = nullptr;
		countNodes = 1;
	}

	~GList()
	{

	}

	LNode* findNode(char a,LNode* prev);
	void addNode(char k);
	void insertEdge(char a, char b,int weight);
	Edge* findEdge(char a, char b);
	bool deleteEdge(char a, char b);
	
	//vrati simbole cvorova koji imaju max 
	// ulazni stepen
	
	string maxDegree(bool);


	void topologicalSort();

	int depthFirstSearch();
	
	//new try here! 
	void depthFirstSrch();
	void breadthFirstSrch();
	int** getNeighbMatrix();
	//new try!
	


	bool isCyclic();


	GList* transpose();

	bool checkIfAllVisited();

	bool isWeaklyConnected();
	
	bool isStronglyConnected();
	
	void setUnvisited();

	void setStatus0();
	bool thruAdjNodesTilBackEdge(LNode* tmp);
	
	int** getNeighborsMatrix();
	
	void delNode(char a);
protected:
	void printMatrix(int** a, int i,int j);

};