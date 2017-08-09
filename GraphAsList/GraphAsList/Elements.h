#pragma once
#include <iostream>
using namespace std;

class Edge;

class LNode
{
public:
	
	char symbol;
	
	LNode* next;

	//pokazivac na drugi cvor!

	Edge* izlGrana;

	//head za linked list
	//tj za grane!
	
	bool visited = false;
	//povecava se pri dodavanju grane
	// ako je this dstNode
	int inDegree = 0;

	//povecava se pri dodavanju grane ako 
	// je this srcNode;

	int outDegree = 0;

	int status = 0;


	~LNode()
	{
		delete next;
		next = nullptr;
		delete this->izlGrana;
		izlGrana = nullptr;
	}

	LNode(char b)
	{
		symbol = b;
		next = nullptr;
		izlGrana = nullptr;


	}


	LNode()
	{
		symbol = ' ';
		next = nullptr;
		izlGrana = nullptr;

	}

	void print()
	{
		cout << this->symbol;
	}


};

class Edge
{
public:
	int tezina;
	LNode* dstNode;
	//gde uvire grana! E = (u,v)
	//dstNode = v;
	Edge* nextBranch;
	//element lancane liste vezane za
	//odredjeni cvor
	//tj sve grane koje izviru iz tog cvora
	
	~Edge() {
		delete dstNode;
		dstNode = nullptr;
		delete nextBranch;

		nextBranch = nullptr;
	}
	
	Edge(int a)
	{
		this->tezina = a;
		this->dstNode = nullptr;
		this->nextBranch = nullptr;
	}
	Edge()
	{
		tezina = 0;
		dstNode = nullptr;
		nextBranch = nullptr;
	}

	void print()
	{
		cout << this->tezina;
	}

};