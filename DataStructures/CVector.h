#pragma once
#include <string>
#include <iostream>
#include "UtilityFunctions.h"
//This class is meant to act as a dynamic array to hold a tokenized string.
//In other words, a container or a vector
//Hmm there already exists a vector. But we can't use it because reasons????
//STL is bad and we can't use vector<T> okkokkok

using namespace std;
class CVector 
{
private:
	string* arr;
	int length;
	int size;
	int current;
public:
	CVector() {
		arr = new string[50];
		size = 50;
		length = current = 0;
	}

	bool tokenize(string t) {
		string buffer = "";
		char c = ' ';
		for (auto n : t) {
			if (n != c) buffer += n;
			else if (n == c && buffer != ""){
				addWord(buffer);
				buffer = "";
			}

		}
		if (buffer != "" && buffer != " ")
			addWord(buffer);
		return true;
	}
	bool addWord(string t) {
		if (length < size) {
			arr[length] = t;
			length++;
			return true;
		}
		return false;
	}
	bool hasNext() {
		return (current <= length);	
	}
	string getWord() {
		string temp = arr[current];
		current++;
		return temp;
	}
	int getLength() { return length; }

	void clear() {
		delete[] arr;
		arr = new string[50];
		current = length = 0;
		
	}

};

