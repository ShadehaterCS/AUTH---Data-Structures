#pragma once
#include "Node.h"
#include "Capsule.h"
class AVLTree
{
private:
	int nodes;

public:
	Node* root;
	AVLTree();
	~AVLTree() {

	}

	bool rotateRight(Node* n);
	bool rotateLeft(Node* n);

	bool insert(Node* node, string *word);

	int max(int a, int b) {
		return (a > b) ? a : b;
	}
	int getBalance(Node* n) {
		if (n == nullptr)
			return 0;
		return height(n->left) - height(n->right);
	}
	int height(Node* n) {
		if (n == nullptr)
			return 0;
		return n->height;
	}

	void printPreOrder(Node* root);
	void printInOrder(Node* root);
	void printPostOrder(Node* root);

	Capsule* find(Node* root, string* word);
};

