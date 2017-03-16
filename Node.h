#pragma once


class Node {
	int exp;
	double koef;
	Node* next;
public:
	double getKoef() {
		return koef;
	}
	void setKoef(double a) {
		koef = a;
	}
	void setNext(Node* A) {
		next = A;

	}

	void setExp(int e) {
		exp = e;

	}
	int getExp() {
		return exp;
	}
	Node* getNext() {
		return next;

	}
	Node() {
		exp = 0;
		koef = 0;
		next = nullptr;
	}
	
	Node(int e, double k) {
		exp = e;
		koef = k;
		next = nullptr;
	}

	



};