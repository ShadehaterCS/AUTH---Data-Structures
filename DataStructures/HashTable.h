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
	void calculateLoadFactor() { loadFactor = uniqueWords / tableSize; }

public:
	int uniqueWords;
	int operationsDone;
	HashTable();
	HashTable(int size);
	~HashTable();
	long long hash(string s);

	bool exists();
	bool insert(string s);
	bool resizeTable();

	Capsule find(string word);

	bool getAndFindRandomWords(string* allWords, int words) {
		return true;
	}
	void show() {
		std::cout << "Unique words: " << uniqueWords << endl;
		std::cout << "Total words: " << operationsDone<< endl;
	}
	void evaluate() {
		string temp;
		for (int i = 0; i < tableSize; i++) {
			temp = table[i].getWord();
			if (!temp.empty())
				std::cout << temp << " "<< table[i].getTimesFound() << endl;
		}
	}
};

