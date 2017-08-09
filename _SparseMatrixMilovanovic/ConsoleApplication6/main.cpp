#include "Matrix.h"


int main()
{

	Matrix<int> mat(5, 5);

	mat.Set(1, 1, 1);
	mat.Set(3, 2, 1);
	mat.Set(3, 0, 1);
	mat.Set(3, 4, 1);
	mat.Set(2, 2, 1);
	mat.Print();



	return 0;
}