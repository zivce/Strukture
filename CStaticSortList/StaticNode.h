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
	NodeStatic(NodeStatic& tmp)
	{
		this->info = tmp.info;
		this->link = tmp.link;

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

	bool operator>(NodeStatic& tmp)
	{
		return this->info > tmp.info;

	}


	void operator=(NodeStatic& a) {
		this->info = a.info;
		//this->link = a->link;

	}


	bool operator!=(NodeStatic& tmp)
	{
		return this->info != tmp.info;

	}

	

};