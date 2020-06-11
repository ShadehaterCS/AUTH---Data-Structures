#pragma once
#include <string>
#include <iostream>
#include <sstream> //std::stringstream
#include <ctime>

#include "HashTable.h"
#include "CVector.h"
#include "CVector.h"
#include "BinaryTree.h"
class UtilityFunctions
{
};

inline static std::string removePunctuation(std::string linestr) {
    for (int i = 0, len = linestr.size(); i < len; i++)
    {
        // check whether parsing character is punctuation or not 
        unsigned char c = linestr[i];
        if (ispunct(c))
            linestr[i] = ' ';
    }
    return linestr;
}

inline static void testHashTable(HashTable* table) {
    
}

inline static void testBST(BinaryTree* tree) {


}

inline static void testBSTPrints(BinaryTree* tree) {
    cout << "Inorder: ";
    tree->printInOrder(tree->getRoot());
    cout << endl;
    cout << "PostOrder: ";
    tree->printPostOrder(tree->getRoot());
    cout << endl;
    cout << "PreOrder: ";
    tree->printPreOrder(tree->getRoot());
}
//Takes the pointer from main that contatins all the words
//of the text and choose 1000 random words from it
inline static string* chooseRandomWords(string* allWords, int ammount) {
    srand(time(NULL));

    string* randoms = new string[1000];
    int ammountOfRandoms = 0;
    for (int i = 0; i < ammount; i++) {
            if ((rand() % 10 + 1) > 5) {
                randoms[ammountOfRandoms] = allWords[i];
                ammountOfRandoms++;
                if (ammountOfRandoms == 1000)
                    return randoms;
        }
    }
}




