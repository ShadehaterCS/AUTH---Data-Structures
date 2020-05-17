#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
//Custom classes
#include "HashTable.h"
#include "CVector.h"
#include "UtilityFunctions.h"

using  namespace std;
int main()
{
    std::ifstream file("inputfile.txt");
    std::string linestr;
    std::string result;

    HashTable hashtable(10000);

 while (std::getline(file, linestr)) {
        linestr = removePunctuation(linestr); 
        
        CVector currentLine; //TODO Move this out and clear its storage for better efficiency!
        currentLine.tokenize(linestr);

        string token;
        while (currentLine.hasNext()) {
            token = currentLine.getWord(); //This is where we get each word
            hashtable.insert(token);
        }
    }

 
    return 0;
}