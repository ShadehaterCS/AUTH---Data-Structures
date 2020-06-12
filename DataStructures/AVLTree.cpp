#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree()
{
	root = nullptr;
	nodes = 0;
}

Node* AVLTree::rotateRight(Node* n)
{
	Node* a = n->left;
	Node* b = n->right;

	//Rotate
	a->right = n;
	b->left = b;

	n->height = max(height(n->left), height(n->right)) + 1;
	a->height = max(height(a->left), height(a->right)) + 1;

	return a;
}

Node* AVLTree::rotateLeft(Node* n)
{
	Node* a = n->right;
	Node* b = a->left;

	//Rotate
	a->left = n;
	n->right = b;

	n->height = max(height(n->left), height(n->right)) + 1;
	b->height = max(height(b->left), height(b->right)) + 1;

	return b;
}

//This is something
Node* AVLTree::insert(Node* n, string *word)
{
	if (root == nullptr)
		root = new Node(*word);
	if (n == nullptr)
		return new Node(*word);
	
	if (*word < n->getKey())
		n->left = insert(n->left, word);
	else if (*word > n->getKey())
		n->right = insert(n->right, word);
	else
		n->getCapsule()->increment();

	n->height = 1 + max(height(n->left), height(n->right));

	int balance = getBalance(n);

	if (balance > 1 && *word < n->left->getKey())
		return rotateRight(n);

	if (balance < -1 && *word > n->right->getKey())
		return rotateLeft(n);

	if (balance > 1 && *word > n->left->getKey()) {
		n->left = rotateLeft(n->left);
		return rotateRight(n);
	}

	if (balance < -1 && *word < n->right->getKey()) {
		n->right = rotateRight(n->right);
		return rotateLeft(n);
	}

	return n;
}

void AVLTree::printPreOrder(Node* root)
{
	if (root != nullptr) {
		cout << root->getKey() << " ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void AVLTree::printInOrder(Node* root)
{
}

void AVLTree::printPostOrder(Node* root)
{
}

Capsule* AVLTree::find(Node *root, string *word)
{
	if (root == nullptr)
		return nullptr;
	if (*word == root->getKey())
		return root->getCapsule();

	if (*word < root->getKey())
		return find(root->left, word);

	if (*word < root->getKey())
		return find(root->right, word);

	return nullptr;
}
