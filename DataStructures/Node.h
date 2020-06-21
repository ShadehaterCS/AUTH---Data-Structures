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

	int height;
	string getKey() { return key->getWord(); }
	Capsule* getCapsule() { return key; }
	Node() {
		key = nullptr;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		height = 0;
	}
	Node(string word) {
		key = new Capsule(word);
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		height = 1;
	}
	~Node() {}
};

