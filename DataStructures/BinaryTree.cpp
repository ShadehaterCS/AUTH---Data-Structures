#include "BinaryTree.h"

Node* BinaryTree::find()
{
	return nullptr;
}

//This function is only for the root word
bool BinaryTree::insert(string word)
{
	if (root == nullptr) {
		root = new Node(word);
		return true;
	}
	//Checking to see if the word is the root
	if (word == root->getKey()) {
		root->getCapsule().increment();
		return true;
	}
	
	//Recursive calls to the other insert function that can traverse the tree
	if (word < root->getKey())
		insert(root->left, word);
	else
		insert(root->right, word);

	return true;
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
		if (n->left == nullptr) {
			n->left = new Node(word);
		}
		//Recursion to go deeper
		else
			insert(n->left, word);
	}
	if (word > n->getKey()) {
		if (n->right == nullptr) {
			n->right = new Node(word);
		}
		else
			insert(n->right, word);
	}
	return true;
}

void BinaryTree::printInOrder()
{

}


