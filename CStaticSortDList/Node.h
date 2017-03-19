#pragma once
#include <iostream>
using namespace std;


template <class T>
class StaticNodeDLL {
public:

	T info;
	int previous;
	int next;


	StaticNodeDLL() {
		info = T();
		previous = 0;
		next = 0;
	}

	StaticNodeDLL(T elem, int a, int b) {
		info = elem;
		previous = a;
		next = b;

	}



};