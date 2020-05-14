#pragma once
#include <iostream>
#include <string>
using namespace std;
//This class represents a capsule of data, specifically for this project a string (word) and a number to count the times that (word) appeared in the text file
class Capsule
{
private:
	string word;
	int num;

public:
	Capsule() {
		word = "";
		num = 0;
	}
	Capsule(string word, int shows) {
		this->word = word;
		num = shows;
	}

	void setWord(string s) { word = s; }
	void setNumber(int n) { num = n; }
	void increment() { num++; }

	int getTimesFound() { return num; }
};

