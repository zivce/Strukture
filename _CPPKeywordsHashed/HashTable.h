#pragma once
#include "HObj.h"

class HashTable
{
protected:
	unsigned int length;
	unsigned int count;

public:
	unsigned int h(char* key)
	{

		return f(key) % length;
	}

	unsigned int h(HObj& t)
	{

		return f(t.getKey()) % length;
	}


	unsigned int f(char* key)
	{
		char* s = key;
		unsigned int res = 0;
		int a = 7;
		for (int i = 0; s[i] != 0; i++)
			res = res << a^s[i];

		return res;
	}

	unsigned int g(unsigned int n)
	{//sekundarna transformacija
		return (n + 1) % length;
	}
};