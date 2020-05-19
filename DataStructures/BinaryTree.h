#pragma once
#include "Node.h"
#include <iostream>
#include <string>
class BinaryTree
{
private:
	Node* root;

public:
	BinaryTree() {
		root = nullptr;
	}
	BinaryTree(std::string firstWord) {
		root = new Node(firstWord);
	}

	bool isEmpty() { return (root == nullptr); }
	Node* find();
	bool insert(Node n);
};

