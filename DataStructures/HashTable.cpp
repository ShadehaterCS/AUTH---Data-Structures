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
    loadFactor = 0;
}
HashTable::~HashTable(){
    delete[] table;
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

bool HashTable::exists()
{
    return false;
}

bool HashTable::insert(string word)
{
    long long hashValue = hash(word);
    long quadraticProbe;
    for (int i=0; i<10; i++){ //Quadratic probing to avoid clustering
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
