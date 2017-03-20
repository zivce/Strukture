#include "MatrixList.h"

void main() {

	MatrixList<int> T(3, 3);

	T.insertValNode(1,2,4);

	T.insertValNode(2,2,1);
	


	cout << T;




	T.insertValNode(2, 1, 4);

	cout << T;


	T.insertValNode(1, 3, 1);
	T.insertValNode(2, 3, 1);
	T.insertValNode(1, 1, 2);


	cout << T;
}