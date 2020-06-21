#include "BinaryTree.h"
#include <iostream>

using namespace std;

bool BinaryTree::insert(string word)
{
	if (root == nullptr) {
		root = new Node(word);
		root->parent = nullptr;
		nodes++;
		return true;
	}
	else {
		//Checking to see if the word is in the root
		if (word == root->getKey()) {
			root->getCapsule()->increment();
			return true;
		}

		//Handles insertion after root node, can't get arround it
		if (word < root->getKey() && root->left == nullptr)
			return insert(root, word);
		else if (word > root->getKey() && root->right == nullptr)
			return insert(root, word);
	}
	
	
	//Recursive calls to the other insert function that can traverse the tree

	if (word < root->getKey()) {
		return insert(root->left, word);
	}
	else {
		return insert(root->right, word);
	}

	return false;
}

bool BinaryTree::insert(Node* n, string word)
{
	//Check to see if the word is in the current node
	if (word == n->getKey()) {
			n->getCapsule()->increment();
			return true;
		}
	//If left is open, we insert it there
	if (word < n->getKey()) {
		if (n->left == nullptr) { //Checks if node is open
			n->left = new Node(word);
			n->left->parent = n;
			nodes++;
			return true;
		}
		//Recursion to go deeper
		else
			return insert(n->left, word);
	}
	//If right is open, we insert it there
	else
		if (word > n->getKey()) {
			if (n->right == nullptr) {
				n->right = new Node(word);
				n->right->parent = n;
				nodes++;
				return true;
			}
			//Recursion to go deeper
			else
				return insert(n->right, word);
		}
	return false;
}

Node* BinaryTree::find(string word)
{
	if (isEmpty())
		return nullptr;
	Node* n = root;
	string* s = &word;
	if (word == n->getKey())
		return n;
	else {
		if (word < root->getKey())
			return find(n->left, s);
		else
			return find(n->right, s);
	}
	return nullptr;
}

Node* BinaryTree::find(Node* n, string* s)
{
	if (n == nullptr)
		return nullptr;
	//Check if the word is at the existing node
	if (*s == n->getKey())
		return n;
	//Check if this is the end of the path
	if (n->left == nullptr && n->right == nullptr)
		return nullptr;
	else {
		if (*s < n->getKey())
			return find(n->left, s);
		else
			return find(n->right, s);
	}
	return nullptr;
}
//Prints the tree InOrder
void BinaryTree::printInOrder(Node* n)
{
	if (n == nullptr)
		return;

	printInOrder(n->left);

	cout << n->getKey() <<" ";

	printInOrder(n->right);

	return;
}
//Prints the tree PostOrder
//Always starts at root
void BinaryTree::printPostOrder(Node* n)
{
	if (n == nullptr)
		return;
	
	printPostOrder(n->left);
	printPostOrder(n->right);
	cout << n->getKey() << " ";
	return;
}
//Prints the tree PreOrder
void BinaryTree::printPreOrder(Node* n)
{
	if (n == nullptr)
		return;

	cout << n->getKey() << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
}

Node* BinaryTree::findMin(Node* root)
{
	if (root->left != nullptr)
		return findMin(root->left);
	else
		return root;

	return nullptr;
}
//Deletes a node from the tree
//If the node has a right child, that goes in its place and the left child becomes the left child of it
//If there is only a left child, that takes its place
bool BinaryTree::deleteWord(string word) {
	if (isEmpty())
		return false;
	Node* n = find(word); //will return nullptr if the word does not exist
	if (n == nullptr) {
		//cerr << "Word '" << word << "' not found." << endl;
		return false;
	}
	//Node is root
	if (n == root) {
		if (n->right != nullptr) {
			Node* changing = findMin(n->right);
			if (changing != nullptr) {
				root->key = changing->getCapsule();
				n = changing;
			}
		}
		else { //This means the node only has left children
				root = root->left;
				nodes--;
				return true;
			}
		}
	//Node contains 2 children
	//Finds minimum value of its right subtree
	//Copies the capsule to n
	//n's address is changed to the copied node which must be one of the 2 other cases
	//thus it's handled in the below code
	if (n->left != nullptr && n->right != nullptr) {
		Node* changing = findMin(n->right);
		if (changing != nullptr) {
			n->key = changing->getCapsule();
			n = changing;
		}
	}
	bool isLeft;
	if (n->parent != nullptr)
		isLeft = n->getKey() < n->parent->getKey();
	else
		isLeft = false;
	//Node containing word is leaf node
	//Severs the connection from its parent node and delete the node
	//bool isLeft determines if it's a left leaf or right
	if (n->left == nullptr && n->right == nullptr) {
		if (isLeft)
			n->parent->left = nullptr;
		else
			n->parent->right = nullptr;
		delete n;
		nodes--;
		return true;
	}
	//Node contains only one child
	//Delete node, set its parent to point to the child of the deleted node
	//childIsLeft determines if the node has left or right child
	if (n->left == nullptr || n->right == nullptr) {
		bool childIsLeft = n->left != nullptr;
		if (isLeft) {
			if (childIsLeft) {
				n->parent->left = n->left;
				n->left->parent = n->parent;
			}
			else {
				n->parent->left = n->right;
				n->right->parent = n->parent;
			}
		}
		else {
			if (childIsLeft) {
				n->parent->right = n->left;
				n->left->parent = n->parent;
			}
			else {
				n->parent->right = n->right;
				n->right->parent = n->parent;
			}
		}
		delete n;
		nodes--;
		return true;
	}
	

	return false;
}

