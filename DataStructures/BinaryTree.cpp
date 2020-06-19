#include "BinaryTree.h"
#include <iostream>

using namespace std;

//This function is only for the root word
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
	//First, check root
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
	//Check if the word is at the existing node
	if (*s == n->getKey())
		return n;
	//Check if this is the end of the path
	if (n->left == nullptr && n->right == nullptr)
		return nullptr;
	else {
		if (*s < root->getKey())
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

void BinaryTree::printPreOrder(Node* n)
{
	if (n == nullptr)
		return;

	cout << n->getKey() << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
}

//Returns the minimum value of the right subtree
//First, we step into the right subtree and loop over all the left nodes of that until we hit a nullptr
Node* BinaryTree::getInOrderSuccessor(Node* n)
{
	Node* changing = n->right;
	if(changing!=nullptr)
		while (changing->left != nullptr) {
			changing = changing->left;
		}
	return changing;
}

//Deletes a node from the tree
//If the node has a right child, that goes in its place and the left child becomes the left child of it
//If there is only a left child, that takes its place
bool BinaryTree::deleteWord(string word) {
	Node* n = find(word); //will return nullptr if the word does not exist
	if (n == nullptr) {
		cerr << "Word '" << word << "' not found." << endl;
		return false;
	}
	//Node containing word is root
	//Get InOrder Successor, copy that to the root node, delete node from tree
	if (n == root) {
		Node* changing = getInOrderSuccessor(root);
		root->key = changing->getCapsule();
		changing->parent->left = nullptr;
		delete changing;
	}

	//Node containg word has children
	//Find InOrderSuccessor and copy it to that, delete that node
	if (n->left != nullptr || n->right != nullptr) {
		Node* changing = getInOrderSuccessor(n);
		n->key = changing->getCapsule();
		
	}

	//Node containing word is leaf node
	//bool isLeft determines if it's a left leaf or right
	bool isLeft = n->parent->getKey() < n->getKey();

	if (n->left == nullptr && n->right == nullptr) { 
		if (isLeft)
			n->parent->left = nullptr;
		else
			n->parent->right = nullptr;
		delete n;
		return true;
	}

	return false;
}

