#include <iostream>
#include <fstream>
#include <iterator>
//Custom classes
#include "HashTable.h"
#include "BinaryTree.h"
#include "AVLTree.h"
#include "CVector.h"
#include "UtilityFunctions.h"

using  namespace std;
int main() {
	ifstream file("small-file.txt");
	if (!file.good()) { //Checks if the file exists
		cerr << "Error while loading file" << endl;
		return 679;
	}

	string linestr;
	string result;

	string token;

	CVector currentLine; //Check documentation for CVector class
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

	string* random;
	random = chooseRandomWords(allWords, ammountOfWords);

	HashTable* hashtable = new HashTable(100000);
	BinaryTree* bst = new BinaryTree();
	AVLTree* avl = new AVLTree();

	testHashTable(hashtable, ammountOfWords, allWords, random);
	testBST(bst, ammountOfWords, allWords, random);
	testAVL(avl, ammountOfWords, allWords, random);

	return 0;
}