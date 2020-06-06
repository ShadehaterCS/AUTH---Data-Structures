#pragma once
#include <string>
#include "Capsule.h"
class Node
{
public:
	Capsule key;
	Node* left;
	Node* right;
	Node* parent;

	std::string getKey() { return key.getWord(); }
	Capsule getCapsule() { return key; }
	Node() {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}

	Node(std::string word) {
		key = Capsule(word);
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

