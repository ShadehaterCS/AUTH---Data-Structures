#pragma once
#include <string>
#include <iostream>
#include <sstream> //std::stringstream
#include <ctime>
#include <chrono>

#include "HashTable.h"
#include "CVector.h"
#include "CVector.h"
#include "BinaryTree.h"
#include "AVLTree.h"
class UtilityFunctions
{
};
//This functions checks every character in a given string and
//replaces that character with an empty space so it can be tokenized
//by the CVector class
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

inline static void testHashTable(HashTable* table, int ammountOfWords, string* allWords, string* randomWords) {
    cout << "------------------------------------------------" << endl;
    cout << "Hashtable Testing" << endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < ammountOfWords; i++) {
        table->insert(allWords[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "Unique words: " << table->uniqueWords << endl;
    cout << "Insertion time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << ", " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "Average insertion time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / ammountOfWords << " ns" << endl;
    start = chrono::high_resolution_clock::now();
    
    Capsule* current;
    for (int i = 0; i < 1000; i++) {
        current = table->find(randomWords[i]);
        cout << "Word: '" << current->getWord() << "' Times found: " << current->getTimesFound() << endl;

    }
    end = chrono::high_resolution_clock::now();
    cout << "Searching time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << ", " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "Average searching time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000 << " ns" << endl;

    cout << "------------------------------------------------" << endl;
}

inline static void testBST(BinaryTree* tree, int ammountOfWords, string* allWords, string* randomWords) {
    cout << "------------------------------------------------" << endl;
    cout << "BST Testing" << endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < ammountOfWords; i++) {
        tree->insert(allWords[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "Unique words: " << tree->ammountOfNodes() << endl;
    cout << "Insertion time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << ", " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" <<endl;
    cout << "Average insertion time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / ammountOfWords << " ns" << endl;
    start = chrono::high_resolution_clock::now();
    Node* current;
    for (int i = 0; i < 1000; i++) {
        current = tree->find(randomWords[i]);
        cout << "Word: " << current->getCapsule()->getWord() << " Times found: " << current->getCapsule()->getTimesFound() << endl;
    }
    end = chrono::high_resolution_clock::now();
    cout << "Searching time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << ", " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "Average searching time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000 << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        tree->deleteWord(randomWords[i]);
    }
    end = chrono::high_resolution_clock::now();
    cout << "Deletion time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << ", " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
    cout << "Average deletion time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000 << " ns" << endl;
    }

inline static void testAVL(AVLTree* tree, int ammountOfWords, string* allWords, string* randomWords) {
    cout << "------------------------------------------------" << endl;
    cout << "AVL Testing" << endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < ammountOfWords; i++) {
        tree->root = tree->insert(&allWords[i], tree->root);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "Unique words: " << tree->nodes << endl;
    cout << "Insertion time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << ", " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "Average insertion time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / ammountOfWords << " ns" << endl;
    start = chrono::high_resolution_clock::now();
    Node* current;
    for (int i = 0; i < 1000; i++) {
        current = tree->find(tree->root,&randomWords[i]);
        if(current)
            cout << "Word: " << current->getCapsule()->getWord() << " Times found: " << current->getCapsule()->getTimesFound() << endl;
    }
    end = chrono::high_resolution_clock::now();
    cout << "Searching time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << ", " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "Average searching time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000 << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        tree->root = tree->deleteNode(&randomWords[i], tree->root);
    }
    end = chrono::high_resolution_clock::now();
    cout << "Deletion time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << ", " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
    cout << "Average deletion time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000 << " ns" << endl;
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




