#include "Alu.h"
#include <cmath>


int Alu::hexToDec(const char& number){
    if(number - '0' < 10)
        return  number - '0';
    return  number - 'A' + 10;
}

string Alu::decToHex( int number){
    if (number == 0) return "0";
    string result;

    while (number != 0) {
        long long remainder = number % 16;

        if (remainder < 10)
            result = char('0' + remainder) + result;
        else
            result = char('A' + (remainder - 10)) + result;

        number /= 16;
    }

    return result;
}


string Alu::decToBinary(int number){
    string result;
    for(int i = 0 ; i < 4; i++){
        result = to_string(number % 2) + result;
        number /= 2;
    }
    return result;
}


string Alu::hexToBinary(const string& number){
    string result;
    for(int i = 0 ; i < number.length() ;i++){
        int temp = hexToDec(number[i]);
        result += decToBinary(temp);
    }
    return result;
}

int Alu::twosComplementToDec(const string& number){
    string binaryNumber = hexToBinary(number);
    int value = 0, length = binaryNumber.length();

    for (int i = 0; i < length; i++)
        value = value * 2 + (binaryNumber[i] - '0');

    value -= (binaryNumber[0]-'0') * int(pow(2, length));

    return value;
}

void Alu::addTwosComplement(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);

    int _valueRegister2_ = twosComplementToDec(_register2Value_);
    int _valueRegister3_ = twosComplementToDec(_register3Value_);

    string result = decToHex(_valueRegister2_ + _valueRegister3_);
    reg.set_rgstr(register1, result);
}
////////////////////////////////////////////////////////////////////////
void Alu::addFloatingPoint(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);
}
////////////////////////////////////////////////////////////////////////

void Alu::bitwiseOrRegisters(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);

    int _valueRegister2_ = 0, _valueRegister3_ = 0;

    for (char ch : _register2Value_)
        _valueRegister2_ = _valueRegister2_ * 16 + hexToDec(ch);

    for (char ch : _register3Value_)
        _valueRegister3_ = _valueRegister3_ * 16 + hexToDec(ch);

    string result = decToHex(_valueRegister2_ | _valueRegister3_);
    reg.set_rgstr(register1, result);
}

void Alu::bitwiseAndRegisters(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);

    int _valueRegister2_ = 0, _valueRegister3_ = 0;

    for (char ch : _register2Value_)
        _valueRegister2_ = _valueRegister2_ * 16 + hexToDec(ch);

    for (char ch : _register3Value_)
        _valueRegister3_ = _valueRegister3_ * 16 + hexToDec(ch);

    string result = decToHex(_valueRegister2_ & _valueRegister3_);
    reg.set_rgstr(register1, result);
}

void Alu::bitwiseXorRegisters(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);

    int _valueRegister2_ = 0, _valueRegister3_ = 0;

    for (char ch : _register2Value_)
        _valueRegister2_ = _valueRegister2_ * 16 + hexToDec(ch);

    for (char ch : _register3Value_)
        _valueRegister3_ = _valueRegister3_ * 16 + hexToDec(ch);

    string result = decToHex(_valueRegister2_ & _valueRegister3_);
    reg.set_rgstr(register1, result);

}
/////////////////////////////////////////////////////////////////////////
void Alu::rotateContentRegister(Register& reg, const string& index){

}
////////////////////////////////////////////////////////////////////////
