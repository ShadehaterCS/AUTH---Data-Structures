#include <iostream>
#include <fstream>
#include <iterator>
#include <chrono>
//Custom classes
#include "HashTable.h"
#include "CVector.h"
#include "UtilityFunctions.h"

using  namespace std;
int main(){
    cout << "Starting" << endl;
    //std::ifstream file("inputfile.txt"); //The testing file
    std::ifstream file("small-file.txt"); //The OG file
    std::string linestr;
    std::string result;

    auto start = chrono::steady_clock::now();

    HashTable hashtable(100000);
    string token;

    CVector currentLine;
    //TODO Change this to a string[] dynamic so it won't have to do it for each data structure and everything will be faster
    while (std::getline(file, linestr)) {
            linestr = removePunctuation(linestr); 

            currentLine.tokenize(linestr);
            
            while (currentLine.hasNext()) {
                token = currentLine.getWord();//This is where we get each word
                if (!token.empty()) {
                    hashtable.insert(token);
                }
            }
            currentLine.clear();
        }
     auto end = chrono::steady_clock::now();
     cout << "Elapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

     string x;
     //hashtable.evaluate();
     hashtable.show();

     cout << "Type any key to exit" << endl;
     cin >> x;
    return 0;
}

string* randomWords() {
    string *words = new string[1000];

    return words;
}