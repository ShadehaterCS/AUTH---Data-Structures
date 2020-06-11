#pragma once
#include <string>
#include "Capsule.h"
using namespace std;
class Node
{
public:
	Capsule* key;
	Node* left;
	Node* right;
	Node* parent;

	string getKey() { return key->getWord(); }
	Capsule* getCapsule() { return key; }
	Node() {
		key = nullptr;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}

	Node(string word) {
		key = new Capsule(word);
		left = nullptr;
		right = nullptr;
	}

	void setLeft(Node* n) {
		left = n;
	}
	void setRight(Node* n) {
		right = n;
	}

	void clearConnections() {
		left = right = nullptr;
	}
};

