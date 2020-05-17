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
	bool open;

public:
	Capsule() {
		open = true;
		word = "";
		num = 0;
	}
	Capsule(string word) {
		open = false;
		this->word = word;
		num = 1; //Since it's the first time it is seen
		cout <<"Created capsule" <<endl;
	}
	~Capsule(){}

	string getWord() { return word; }
	void setWord(string s) { word = s; }
	void setNumber(int n) { num = n; }
	void increment() { num++; }
	bool getStatus() { return open; }
	int getTimesFound() { return num; }
};

