#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class HObj {
private:
	char* keyword;

public:
	int next;
	int status;// 2 -active 1-obrisana 0-prazna

	void deleteR() {
		delete keyword;
	}
	char* getKey()
	{
		return keyword;
	}
	HObj(char* t){
		next = -1;
		status = 0;

		int strln = 1;
		strln += strlen(t);
		keyword = new char[strln];
		strcpy(keyword, t);
	}

	HObj()
	{
		next = -1;
		status = 0;
		keyword = nullptr;
	}

	HObj& operator=(HObj& a)
	{
		int strln = 1;
		if(a.keyword != nullptr)
		{
			strln += strlen(a.keyword);
			this->keyword = new char[strln];
			strcpy(this->keyword, a.keyword);
		}
		else
		{
			this->keyword = nullptr;
		}
		this->next = a.next;

		return *this;
	}


};