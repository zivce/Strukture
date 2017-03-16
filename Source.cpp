#include "CPol.h"

void main() {

	CPolynomLL* T = new CPolynomLL();
	
	
	T->addToList(1,3);

	T->addToList(0, 1);
	
	T->addToList(0, 2);
	
	T->addToList(2, 2);


	CPolynomLL* P = new CPolynomLL();

	P->addToList(1, 3);
	
	P->addToList(0, 1);
	
	P->addToList(3, 1);
	
	P->addToList(4, 1);

	P->addToList(2, 2);

	CPolynomLL* Res = P->addPol(*T);

	Res->printPolynom();
	cout << "\n________\n";

	CPolynomLL* MULTI = new CPolynomLL();

	MULTI = MULTI->mulPol(*T, *P);

	MULTI->printPolynom();

}