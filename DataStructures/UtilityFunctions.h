#pragma once
#include <string>
#include <iostream>
#include <sstream> //std::stringstream

#include "HashTable.h"
#include "CVector.h"
#include "CVector.h"

class UtilityFunctions
{
    static std::string removePunctuation(std::string linestr);
    static void testHashTable();
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

inline void testHashTable() {
    HashTable a(10000);
    string b = "liakoshotmail.com";
    std::cout << "String: " << b << " - hash: ";
    std::cout << a.hash(b) << std::endl;
}




