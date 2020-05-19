#include <iostream>
#include <fstream>
#include <iterator>
#include <chrono>
//Custom classes
#include "HashTable.h"
#include "CVector.h"
#include "UtilityFunctions.h"

using  namespace std;
int main() {
	//std::ifstream file("inputfile.txt"); //The testing file
	std::ifstream file("small-file.txt"); //The OG file
	std::string linestr;
	std::string result;

	HashTable hashtable(100000);
	string token;

	CVector currentLine;
	//TODO Change this to a string[] dynamic so it won't have to do it for each data structure and everything will be faster
	string* allWords = new string[500000];
	int ammountOfWords = 0;

	cout << "Starting file loading" << endl;
	while (std::getline(file, linestr)) {
		linestr = removePunctuation(linestr);

		currentLine.tokenize(linestr);

		while (currentLine.hasNext()) {
			token = currentLine.getWord();//This is where we get each word
			if (!token.empty()) {
				//hashtable.insert(token);
				allWords[ammountOfWords] = token;
				ammountOfWords++;
			}
		}
		currentLine.clear();
	}
	cout << "File loaded" << endl;

	auto start = chrono::steady_clock::now();
	for (int x = 0; x < ammountOfWords; x++)
		hashtable.insert(allWords[x]);
	auto end = chrono::steady_clock::now();
	cout << "Elapsed time in milliseconds : "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	string x;
	//hashtable.evaluate();
	start = chrono::steady_clock::now();
	hashtable.find("certainty");
	end = chrono::steady_clock::now();
	cout << "Elapsed time in microseconds : "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " micros" << endl;
	hashtable.show();
	cout << "Type any key to exit" << endl;

	cin >> x;
	return 0;
}