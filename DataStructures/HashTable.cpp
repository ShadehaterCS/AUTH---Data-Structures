#include "HashTable.h"
#include "Capsule.h"

HashTable::HashTable()
{
    tableSize = 1000;
    table = new Capsule[tableSize];
    loadFactor = 0;
}
HashTable::HashTable(int size)
{
    tableSize = size;
    table = new Capsule[tableSize];
    loadFactor = operationsDone = 0;
}
HashTable::~HashTable(){
    delete[] table;
}
//Hash function that hashes a string char by char
long long HashTable::hash(string s)
{
    const int p = 31; //Prime Number
    const int m = 1e9 + 9; //Large Prime Number
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p);
    }
    return abs(hash_value % tableSize);
}

bool HashTable::insert(string word)
{
    long long hashValue = hash(word);
    long quadraticProbe;
    for (int i=0; i<15; i++){ //Quadratic probing to avoid clustering
        quadraticProbe = hashValue + i*i;
        if (table[quadraticProbe].getStatus()){
            table[quadraticProbe] = Capsule(word);
            uniqueWords++;
            operationsDone++;
            return true;
        }
        else
            if (table[quadraticProbe].getWord() == word){
                table[quadraticProbe].increment();
                operationsDone++;
                return true;
            }
    }
    return false;
}

Capsule* HashTable::find(string word) //If it exists, returns the capsule object containing the word the program needs.
{
    long long hashValue = hash(word);
    long quadraticProbe;
    for (int i = 0; i < 15; i++) { //Quadratic probing to avoid clustering
        quadraticProbe = hashValue + i * i;
        if (!table[quadraticProbe].getStatus()) { //Will return false if it's occupied
            if (table[quadraticProbe].getWord() == word)
                return &table[quadraticProbe];
        }
    }
    return nullptr;
}
