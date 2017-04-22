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
		a += key / 1000;
		a += (key / 100) % 100;
		a += (key % 100) ;
		//metod presavijanja
		return a;
	}

	virtual unsigned int h(HashObj& t)
	{
		return f(t.getKey()) % length;
	}
	virtual unsigned int h(int key)
	{
		return f(key) % length;
	}

	unsigned int g(unsigned int a)
	{
		return (a + 1) % length;
	}



};