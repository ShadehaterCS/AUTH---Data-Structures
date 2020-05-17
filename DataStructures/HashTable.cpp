#include "HashTable.h"
#include "Capsule.h"
HashTable::HashTable()
{
    tableSize = 1000;
    table = new Capsule[tableSize];
}
HashTable::HashTable(int size)
{
    tableSize = size;
    table = new Capsule[tableSize];
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

bool HashTable::insert(string word)
{ //add exception handling
    long long hashValue = hash(word);
    long quadraticProbe;
    for (int i=0; i<100; i++){ //Quadratic probing to avoid clustering
        quadraticProbe = hashValue + i*i;
        cout << "Probed at: " <<quadraticProbe <<endl;
        if (table[quadraticProbe].getStatus()){
            table[quadraticProbe] = Capsule(word);
            return true;
        }
        else
            if (table[quadraticProbe].getWord() == word){
                table[quadraticProbe].increment();
                cout << "Found word: " <<word << " this many times: "<<table[quadraticProbe].getTimesFound();
                return true;
            }
    }
    //Adding a comment to test something
    return false;
}
