#pragma once
class HashObj {
private:
	int phoneNumber;//key
	
public:
	int status;//2 - aktivna 1 - obrisana 0 - prazna
	HashObj* next;

	void setKey(int a)
	{
		phoneNumber = a;
	}
	int getKey()
	{
		return phoneNumber;
	}
	HashObj()
	{
		status = 0;
		next = nullptr;
		phoneNumber = 0;
	}
	HashObj(int key):HashObj()
	{
		phoneNumber = key;
		
	}

};