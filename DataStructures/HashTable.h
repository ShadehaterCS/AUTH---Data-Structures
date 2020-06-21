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
	
	void calculateLoadFactor() { loadFactor = uniqueWords / tableSize; }

public:
	Capsule* table;
	int uniqueWords;
	int operationsDone;
	HashTable();
	HashTable(int size);
	~HashTable();
	long long hash(string s);

	bool insert(string s);

	Capsule find(string word);

	void show() {
		std::cout << "Unique words: " << uniqueWords << endl;
		std::cout << "Total words: " << operationsDone<< endl;
	}
};

