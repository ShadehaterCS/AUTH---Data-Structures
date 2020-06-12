#include <iostream>
#include <fstream>
#include <iterator>
#include <chrono>
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
	for (int i = 0; i < ammountOfWords; i++) {
		bst->insert(allWords[i]);
		hashtable->insert(allWords[i]);
		avl->insert(new Node(allWords[i]), &allWords[i]);
	}

	cout << "Hash: " << hashtable->uniqueWords << endl;
	cout << "BST: " << bst->ammountOfNodes() << endl;

	avl->printPreOrder(avl->root);
	return 0;
}