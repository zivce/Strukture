#include "ReorgList.h"
void main()
{
	struct node a(2, 33);
	struct node b(222, 33);

	ReorgList* TMP = new ReorgList();

	TMP->addToTail(a);
	TMP->addToTail(a);
	TMP->addToTail(b);

	TMP->GetTransp(222)->print();

	cout << *TMP;
}