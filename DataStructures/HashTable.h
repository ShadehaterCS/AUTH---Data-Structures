#pragma once
#include <iostream>
#include <string>
#include "Capsule.h"
//This class represents a HashTable for strings using the open address technique
using namespace std;
class HashTable
{
private :
	int tableSize;
	double loadFactor;
	Capsule* table;
	void calculateLoadFactor();
public:

	HashTable();
	HashTable(int size);
	long long hash(string s);

	bool addWord(string s);
	bool resizeTable();
};

