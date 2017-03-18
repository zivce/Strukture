#pragma once

#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	T info;
	Node<T>* link;
public:
	//operator < i > predefinisi za sort

	Node<T>* getLink() {
		return link;
	}
	T getInfo() {
		return info;
	}
	~Node() {

	}

	Node() {
		info = T();
		link = nullptr;
	}

	Node(T a, Node<T>* b) {
		info = a;
		link = b;
	}

	Node(Node<T>* B)
	{
		this->info = B->info;
		this->link = B->link;

	}


	friend ostream& operator<<(ostream& izlaz, Node& tmpA) {
		izlaz << tmpA.info << "|/";
		if (tmpA.link != nullptr)
			izlaz << "--->";
		else
			izlaz << "^";

		return izlaz;

	}
};