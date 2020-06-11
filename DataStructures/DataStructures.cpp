#include <iostream>
#include <fstream>
#include <iterator>
#include <chrono>
//Custom classes
#include "HashTable.h"
#include "BinaryTree.h"
#include "CVector.h"
#include "UtilityFunctions.h"

using  namespace std;
int main() {
	//std::ifstream file("inputfile.txt"); //The testing file
	ifstream file("small-file og.txt");
	if (!file.good()) { //Checks if the file exists
		cerr << "Error while loading file" << endl;
		return 679;
	}

	string linestr;
	string result;

	string token;

	CVector currentLine; //Check documentation for CVector class
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
	cout << "File loaded, word count: "<< ammountOfWords << endl; 

	HashTable h(100000);
	BinaryTree bst;
	for (int i = 0; i < ammountOfWords; i++) {
		bst.insert(allWords[i]);
		h.insert(allWords[i]);
	}

	cout << "Hash: " << h->uniqueWords << endl;
	cout << "BST: " << bst.ammountOfNodes() << endl;
	return 0;
}