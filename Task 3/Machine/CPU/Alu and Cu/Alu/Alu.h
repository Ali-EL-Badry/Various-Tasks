
#ifndef ALU_H
#define ALU_H

#include <string>
using namespace std;

class Alu {

public:
    static string decToHex(const string& number);
    static string hexToDec(const string& number);
    static void add(int firstIndex, int secondIndex);
};


#endif
