#pragma once
#include <iostream>
#include <string>
using namespace std;
//This class represents a capsule of data, specifically for this project a string (word) and a number to count the times that (word) appeared in the text file
class Capsule
{
private:
	string word; //The word
	int num; //Number of times the word is found in the text
	bool open; //Marks if the capsule was initialized or created

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
	}

	~Capsule() {
		;
	}

	string getWord() { return word; }
	void setWord(string s) { word = s; }
	void setNumber(int n) { num = n; }
	void increment() { num++; }

	bool getStatus() { return open; }
	int getTimesFound() { return num; }
	void show() {
		if (this == nullptr) //Handles the never to happen time that a capsule pointer tries to use this function while it's a nullpointer
			return;
		cout << "|Word: " << word << " " << "|Times found: " << num << " " << "|Status: " << open << endl;
	}
};

