#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
	int info;
	Node* next;
	Node() {
		info = 0;
		next = nullptr;
	}

	Node(int a)
	{
		info = a;
		next = nullptr;
	}

	friend ostream& operator<<(ostream& iz, Node& a)
	{
		iz << a.info;
		return iz;
	}
};