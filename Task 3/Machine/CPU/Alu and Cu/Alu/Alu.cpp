#include "Alu.h"



string Alu::decToHex(const string& number){
    long long Number = stoll(number);
    string result;
    while(Number != 0){
        long long remainder = Number % 16;

        if (remainder < 10)
            result = to_string('0' + remainder) + result; // 0-9
        else
            result = to_string('A' + (remainder - 10))+ result; // A-F

        Number /= 16;
    }
    return result;
}

string Alu::hexToDec(const string& number){
    long long result = 0;

    for(int i =number.size()-1 ; i >= 0 ; i--){
        if(number[i] - '0' < 10)
            result += (number[i] - '0')* pow(16,number.size()-1-i);
        else
            result += (number[i] - 'A')* pow(16,number.size()-1-i);
    }

    return to_string(result);
}


void Alu::add(int firstIndex, int secondIndex){

}

