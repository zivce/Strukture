#pragma once
#include <iostream>
using namespace std;

template <class T>
class NodeStatic {
public: 
	T info;
	int link;

	NodeStatic() {
		info = T();
		link = 0;
	}
	NodeStatic(T tmp) {
		info = tmp;
		link = 0;
	}

	NodeStatic(T tmp,int tmpNext) {
		info = tmp;
		link = tmpNext;
	}

	~NodeStatic() {

	}
	friend ostream& operator<<(ostream& izlaz, NodeStatic& tmpNode) {
		izlaz << tmpNode.info;
		if (tmpNode.link != 0)
			izlaz << "/-->";
		else
			izlaz << "^\n";
		return izlaz;
	}

	bool operator==(NodeStatic& tmp)
	{
		return this->info == tmp.info;

	}
};