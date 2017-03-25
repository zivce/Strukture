#pragma once
#include "HashObj.h"
class HashTable{
protected:

	unsigned int length;
	unsigned int count;
public:
	
	unsigned int f(int key)
	{
		unsigned int a = 0;
		a += key / 10000;
		a += (key / 100) % 100;
		a += key % 10;
		//metod presavijanja
		return a;
	}

	unsigned int h(HashObj& t)
	{
		return f(t.getKey()) % length;
	}

	unsigned int g(unsigned int a)
	{
		return (a + 1) % length;
	}



};