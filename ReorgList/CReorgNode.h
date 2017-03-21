#pragma once
#include <iostream>
using namespace std;

struct node {
	int key;
	int info;

	void print()
	{
		cout << "key: " << key << " " << info;
	}
	node()
	{
		key = 0;
		info = 0;
	}


	node(int a, int b)
	{
		key = a;
		info = b;
	}
};

class RNode {
public:
	node t;
	RNode* link;

	RNode()
	{
		t = node();
		link = nullptr;
	}

	RNode(node a, RNode* ptr)
	{
		this->t = a;
		this->link = ptr;

	}

	bool operator==(RNode& tmpA)
	{
		return t.info == tmpA.t.info;

	}
	RNode(node a)
	{
		this->t = a;
		this->link = nullptr;
	}
	
	friend ostream& operator<<(ostream& izlaz,RNode& a)

	{
		izlaz << "\ninfo:" << a.t.info << " key:" << a.t.key <<"\n";
		return izlaz;
	}
};