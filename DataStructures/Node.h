#pragma once
#include <string>

class Node
{
public:
	std::string key;
	Node* left;
	Node* right;

	std::string getKey() { return key; }

	Node() {
		left = nullptr;
		right = nullptr;
	}

	Node(std::string word) {
		key = word;
		left = nullptr;
		right = nullptr;
	}
};

