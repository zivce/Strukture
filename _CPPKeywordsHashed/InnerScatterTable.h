#pragma once
#include "HashTable.h"
#include <iostream>
using namespace std;

class ISHashTable : public HashTable
{
private:
	HObj* arr;
public:
	void remove(char* key)
	{
		unsigned int tmp = h(key);

		if (arr[tmp].status == 2)
		{
			unsigned int prev = tmp;

			while (strcmp(arr[tmp].getKey(),key) &&
				arr[tmp].next != -1){
				prev = tmp;
				tmp = arr[tmp].next;

			}
			// ako je netacan uslov ne izvrsava se 
			//while jer je kljuc jednak 

			arr[prev].next = arr[tmp].next;
			arr[tmp].deleteR();
			arr[tmp].status = 1;
			

		}
		else if (arr[tmp].status == 1 && arr[tmp].next != -1)
		{//obrisan je element provere se sinonimi
			unsigned int prev = arr[tmp].next;
			
			while (strcmp(arr[tmp].getKey(), key) &&
				arr[tmp].next != -1) {

				prev = tmp;
				tmp = arr[tmp].next;

			}
			arr[prev].next = arr[tmp].next;
			arr[tmp].deleteR();
			arr[tmp].status = 1;

		}
		this->count--;
	}

	void insert(char* key)
	{
		HObj tmp(key);

		unsigned int index = h(tmp);

		if (arr[index].status == 0)
		{
			arr[index] = tmp;
			arr[index].status = 2;
			arr[index].next = -1;

		}
		else if (arr[index].status == 1 || 
			arr[index].status == 2)
		{
			unsigned int tmpindex = index;
			//prethodnik je tmpindex!
			//status 1 ili 0 moguc upis
			while (arr[index].status != 0 && 
				arr[index].status != 1)
			{
				tmpindex = index;
				index = g(index);
			}
			//nadje mesto za sledeci elem

			arr[tmpindex].next = index;
			arr[index] = tmp;
			arr[index].status = 2;
		}
		this->count++;

	}

	void print()
	{
		for (int i = 0; i < length; i++)
		{
			if (arr[i].getKey() != nullptr)
				cout << "[" << i << "]" << arr[i].getKey() 
				<< " " << arr[i].next << "\n";
			else
				cout << "[" << i << "]" << "\n";
		}

	}

	~ISHashTable()
	{
		if(arr)
			delete[] arr;
	}

	ISHashTable(int len)
	{
		length = len;
		count = 0;

		arr = new HObj[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = HObj();

		}

	}

};