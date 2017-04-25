#pragma once
class HeapNode {
public:
	int info;
	int flag = 0;
	HeapNode* left;
	HeapNode* right;
	HeapNode* parent;
public:

	HeapNode()
	{
		left = right = parent = nullptr;
		info = 0;
	}


	HeapNode(int a)
	{
		left=nullptr;
		right = nullptr;
		parent = nullptr;
		info = a;
	}

};