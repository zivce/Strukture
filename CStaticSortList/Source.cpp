#include "StaticList.h"

void main() {

	//SLList<int> t(3);

	//t.addToHead(3);
	//t.addToHead(4);
	//t.addToHead(5);
	////poslednji ne treba
	//// da doda
	//
	//cout << t;
	//
	//t.bubbleSort();
	//
	//cout << t;

	SLList<int> m(9);
	m.addToHead(5);
	m.addToHead(10);
	m.addToHead(6);
	m.addToHead(4);
	m.addToHead(3);
	m.addToHead(1);
	m.addToHead(2);
	m.addToHead(178);

	cout << m;
	m.bubbleSort();

	cout << m;

}