#include "StaticList.h"

void main() {
	SLList<int> A();

	SLList<int> t(3);

	t.addToHead(3);
	t.addToHead(4);
	t.addToHead(5);
	//poslednji ne treba
	// da doda
	t.addToHead(7);

	cout << t;
}