#pragma once
#include "Node.h"
#include "Capsule.h"
class AVLTree
{
private:

public:
	int nodes;
	int getHeight(Node* n) { return (n == nullptr ? -1 : n->height); }
	int max(int left, int right){ return (left >= right) ? left : right; }

	Node* root;
	AVLTree();
	~AVLTree() {}
	Node* find(Node* root, string* word);
	Node* insert(string *word, Node* n);
	Node* deleteNode(string* word, Node* n);
	Node* singleRightRotate(Node* n);
	Node* singleLeftRotate(Node* n);

	int getBalance(Node* n) {
		if (n == nullptr)
			return 0;
		return getHeight(n->left) - getHeight(n->right);
	}
	Node* findMin(Node* n);
	Node* findMax(Node* n);

	void printPreOrder(Node* root);
	void printInOrder(Node* root);
	void printPostOrder(Node* root);
};

