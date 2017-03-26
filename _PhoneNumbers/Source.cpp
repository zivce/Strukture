#include "ChainedScatterTable.h"
#include <math.h>

void main()
{	CScatterTable ktmp(1249);
	// 1000/0.8 ~ 1249

	int* b = new int[1000];
	
	for (int i = 0; i < 1000; i++)
	{
		b[i] = (abs(rand()*100))+3453220;
		ktmp.insert(b[i]);
	}


	ktmp.print(0, 1249);
}