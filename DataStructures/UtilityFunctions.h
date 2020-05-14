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
    linestr.erase(std::remove_if(
        linestr.begin(), linestr.end(),
        [](unsigned char c) { return std::ispunct(c); }
    ), linestr.end());
    return linestr;
}

inline void testHashTable() {
    HashTable a(10000);
    string b = "liakoshotmail.com";
    std::cout << "String: " << b << " - hash: ";
    std::cout << a.hash(b) << std::endl;
}



