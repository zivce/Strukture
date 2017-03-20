#include "MatrixList.h"

void main() {

	MatrixList<int> T(2, 2);

	T.insertValNode(1,1,4);

	T.insertValNode(1,2,1);

	T.insertValNode(2,2,4);


	cout << T;
}