#pragma once
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;
class BinaryTree
{
private:
	Node* root;
	int nodes;

public:
	BinaryTree() {
		root = nullptr;
		nodes = 0;
	}
	BinaryTree(string firstWord) {
		root = new Node(firstWord);
		nodes = 0;
	}
	~BinaryTree() {
	}
	bool isEmpty() { return (root == nullptr); }

	Node* getRoot() { return root; }

	bool insert(string word);
	bool insert(Node* n, string word);
	Node* find(string word);
	Node* find(Node* n, string *word);

	bool deleteWord(string word);
	int ammountOfNodes() { return nodes; }

	void printInOrder(Node* n);
	void printPostOrder(Node* n);
	void printPreOrder(Node* n);

	Node* getInOrderSuccessor(Node* n);
};

