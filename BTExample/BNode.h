#pragma once
#include <iostream>
using namespace std;

class BNode
{
public:
	int info;
	BNode* left;
	BNode* right;

	BNode(int elem)
	{
		info = elem;
		left = right = nullptr;
	}

	BNode()
	{
		info = 0;
		left = right = nullptr;
	}

	bool operator<(int el)
	{
		return (info < el);
	}

	bool operator>(int el)
	{
		return (info > el);
	}

	bool operator==(int el)
	{
		return (info == el);
	}

	friend ostream& operator<<(ostream& iz, BNode& k)
	{
		iz << k.info << " ";
		return iz;
	}

};