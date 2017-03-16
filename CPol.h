#pragma once
#include "Node.h"

class CPolynomLL {
	Node* head;
	Node* tail;
public:
	~CPolynomLL() {
		if (head) {
			delete[] head;
		}


	}
	CPolynomLL() {
		head = tail = nullptr;
	}
	void addToTail(Node* A);
	void addToHead(Node* A);
	void addToList(int exp, double coef);

	void addToTMPList(int exp, double coef);

	CPolynomLL* addPol(CPolynomLL& B);

	void printPolynom();
	void copyList(CPolynomLL* T);
};
