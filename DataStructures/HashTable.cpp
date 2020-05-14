#include "HashTable.h"

HashTable::HashTable()
{
}

HashTable::HashTable(int size)
{
    tableSize = size;
    table = new Capsule[tableSize];
}
//Hash function that hashes a string char by char
long long HashTable::hash(string s)
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p);
    }
    
    return abs(hash_value % tableSize);
}

bool HashTable::addWord(string s)
{ //add exception handling
    long long hashValue = hash(s);
    table[hashValue] = Capsule(s, 1);
    return true;
}
