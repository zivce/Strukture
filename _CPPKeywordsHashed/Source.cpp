#include "InnerScatterTable.h"

void main()
{
	ISHashTable t(113);
	// 90/0.8 ~ 113 

 	// num of keywords / 0.8
	
	t.insert("default");
	t.insert("int");
	t.insert("long");
	t.insert("char");
	t.insert("while");
	t.insert("void");
	t.insert("double");
	t.insert("float");
	t.insert("break");
	t.insert("auto");
	t.insert("reinterpret_cast");
	t.insert("dynamic_cast");
	t.insert("else");
	t.insert("goto");
	t.insert("friend");
	t.insert("false");
	t.insert("enum");
	t.insert("extern");
	t.insert("explicit");
	//test sinonimi
	t.insert("export");
	
	t.print();
	cout << "-----\n\n";

	
	
	t.print();
	cout << "-----\n\n";
}