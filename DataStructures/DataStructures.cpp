#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "HashTable.h"
#include <ctype.h>
#include "CVector.h"
#include "UtilityFunctions.h"

int main()
{
    std::ifstream file("inputfile.txt");
    std::string linestr;
    std::string result;
   
    while (std::getline(file, linestr)) {
        linestr = removePunctuation(linestr);
        
        CVector currentLine; //TODO Move this out and clear its storage for better efficiency!
        currentLine.tokenize(linestr);
        string token;

        while (currentLine.hasNext()) {
            token = currentLine.getWord(); //This is where we get each word
            cout << token;
        }
    }
    cout << endl;
    testHashTable();
    
    string a;
    cin >> a;
    return 0;
}
