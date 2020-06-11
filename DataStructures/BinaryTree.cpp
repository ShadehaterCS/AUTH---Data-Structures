#include "BinaryTree.h"
#include <iostream>

using namespace std;

//This function is only for the root word
bool BinaryTree::insert(string word)
{
	if (root == nullptr) {
		root = new Node(word);
		nodes++;
		return true;
	}
	else {
		//Checking to see if the word is in the root
		if (word == root->getKey()) {
			root->getCapsule().increment();
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
			n->getCapsule().increment();
			return true;
		}
	//If left is open, we insert it there
	if (word < n->getKey()) {
		if (n->left == nullptr) { //Checks if node is open
			n->left = new Node(word);
			nodes++;
			return true;
		}
		//Recursion to go deeper
		else
			return insert(n->left, word);
	}
	//If right is open, we insert it there
	if (word > n->getKey()) {
		if (n->right == nullptr) {
			n->right = new Node(word);
			nodes++;
			return true;
		}
		//Recursion to go deeper
		else
			return insert(n->right, word);
	}
	return false;
}

bool BinaryTree::find(string word)
{
	Node* n = root;
	string* s = &word;
	//First, check root
	if (word == n->getKey())
		return true;
	else {
		if (word < root->getKey())
			return find(n->left, s);
		else
			return find(n->right, s);
	}
	return false;
}

bool BinaryTree::find(Node* n, string* s)
{
	//Check if the word is at the existing node
	if (*s == n->getKey())
		return true;
	//Check if this is the end of the path
	if (n->left == nullptr && n->right == nullptr)
		return false;
	else {
		if (*s < root->getKey())
			return find(n->left, s);
		else
			return find(n->right, s);
	}
	return false;
}

void BinaryTree::printInOrder()
{

}


