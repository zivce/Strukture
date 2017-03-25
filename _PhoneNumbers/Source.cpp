#include "ChainedScatterTable.h"
void main()
{
	int b1 = 5641234;
	int b2 = 7777888;
	int b3 = 3553333;
	int b4 = 1514333;
	int b5 = 4564333;


	CScatterTable ktmp(1249);
	ktmp.insert(b1);
	ktmp.insert(b2);
	ktmp.insert(b3);
	ktmp.insert(b4);
	ktmp.insert(b5);


	ktmp.print(500, 900);
}