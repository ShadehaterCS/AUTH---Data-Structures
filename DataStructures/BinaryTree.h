#pragma once
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;
class BinaryTree
{
private:
	Node* root;
	int leftNodes;
	int rightNodes;

public:
	BinaryTree() {
		root = nullptr;
		leftNodes = rightNodes = 0;
	}
	BinaryTree(string firstWord) {
		root = new Node(firstWord);
		leftNodes = rightNodes = 0;
	}
	~BinaryTree() {
	}
	bool isEmpty() { return (root == nullptr); }

	Node* getRoot() { return root; }

	bool insert(string word);
	bool insert(Node* n, string word);
	bool find(string word);
	bool find(Node* n, string *word);
	void printInOrder();
};

