#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree()
{
	root = nullptr;
	nodes = 0;
}

//Inserts a node at the tree
//Performs single or double rotates appropriately to maintain the balance
Node* AVLTree::insert(string *word, Node* n)
{
	if (n == nullptr) {
		nodes++;
		return (new Node(*word));
	}
	if (*word < n->getKey())
		n->left = insert(word, n->left);
	else if (*word > n->getKey())
		n->right = insert(word, n->right);
	else { //Word already in tree, update times found int
		n->getCapsule()->increment();
		return nullptr;
	}
	//Update height of parent node
	n->height = 1 + max(getHeight(n->left), getHeight(n->right));

	int b = getBalance(n);

	//Left left
	if (b > 1 && *word < n->left->getKey())
		return singleRightRotate(n);
	//Right right
	if (b < -1 && *word > n->right->getKey())
		return singleLeftRotate(n);

	//Left Right
	if (b > 1 && *word > n->left->getKey()) {
		n->left = singleLeftRotate(n->left);
		return singleRightRotate(n);
	}
	//Right Left
	if (b < -1 && *word < n->right->getKey()) {
		n->right = singleRightRotate(n->right);
		return singleLeftRotate(n);
	}
	//Return unchanged
	return n;
}

Node* AVLTree::deleteNode(string* word, Node* n)
{
	if (n == nullptr)
		return n;
	if (*word < n->getKey())
		deleteNode(word, n->left);
	else if (*word > n->getKey())
		deleteNode(word, n->right);
	else {
		//Node with one child or none
		if (n->left == nullptr || n->right == nullptr) {
			Node* temp = n->left ? n->left : n->right;
			//No children
			if (temp == nullptr) {
				temp = n;
				n = nullptr;
			}
			else { //One child
				*n = *temp;
				delete temp;
			}
		}
		//Node has two children, get minimum in right subtree
		else { 
			Node* temp = findMin(n->right);

			n->key = temp->getCapsule();
			n->right = deleteNode(word, n->right);
		}
	}

	if (n == nullptr)
		return n;

	//Update height of current node
	n->height = 1 + max(getHeight(n->left), getHeight(n->right));
	//Check balance for current node after deletion
	int b = getBalance(n);

	if (b > 1 && getBalance(n->left) >= 0)
		return singleRightRotate(n);
	if (b > 1 && getBalance(n->left) < 0) {
		n->left = singleLeftRotate(n->left);
		return singleRightRotate(n);
	}
	if (b < -1 && getBalance(n->right) <= 0)
		return singleLeftRotate(n);
	if (b < -1 && getBalance(n->right) > 0) {
		n->right = singleRightRotate(n->right);
		return singleLeftRotate(n);
	}
	nodes--;
	return n;
}

//Rotate right a subtree with root n
Node* AVLTree::singleRightRotate(Node* n)
{
	Node* temp = nullptr;
	Node* temp2 = nullptr;
	if (n->left != nullptr)
		temp = n->left;
	if (temp != nullptr)
		temp2 = temp->right;
	if (!temp || !temp2)
		return nullptr;
	//Rotate
	temp->right = n;
	n->left = temp2;
	//Update Heights
	n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
	temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
	//Return new root
	return temp;
}

//Rotate left a subtree with root n
Node* AVLTree::singleLeftRotate(Node* n)
{
	Node* temp = nullptr;
	Node* temp2 = nullptr;
	if(n->right != nullptr)
		temp = n->right;
	if (temp !=nullptr)
		temp2 = temp->left;
	if (!temp || !temp2)
		return nullptr;
	//Rotate
	temp->left = n;
	n->right = temp2;
	//
	n->height = max(getHeight(n->right),getHeight(n->left)) + 1;
	temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
	//Return new root
	return temp;
}

//Returns minimum value in a tree or subtree
Node* AVLTree::findMin(Node* n)
{
	if (n == nullptr)
		return nullptr;
	else if (n->left == nullptr)
		return n;
	else
		findMin(n->left);
	return nullptr;
}
// Returns maximum value in a tree or subtree
Node* AVLTree::findMax(Node* n)
{
	if (n == nullptr)
		return nullptr;
	else if (n->right == nullptr)
		return n;
	else
		findMax(n->right);
	return nullptr;
}

void AVLTree::printPreOrder(Node* root)
{
	if (root == nullptr)
		return;
	cout << root->getKey() << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void AVLTree::printInOrder(Node* root)
{
	if (root == nullptr)
		return;
	printInOrder(root->left);
	cout << root->getKey() << " ";
	printInOrder(root->right);
	return;
}

void AVLTree::printPostOrder(Node* root)
{
	if (root == nullptr)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->getKey() << " ";
	return;
}
//Traverses the tree sequentially
//returns nullptr if word is not found
Node* AVLTree::find(Node *root, string *word)
{
	if (root == nullptr)
		return nullptr;

	if (*word == root->getKey())
		return root;

	if (*word < root->getKey())
		return find(root->left, word);

	if (*word < root->getKey())
		return find(root->right, word);

	return nullptr;
}
