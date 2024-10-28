#ifndef CPU_H
#define CPU_H
#include "Register/Register.h"
#include "Alu and Cu/Alu/Alu.h"
#include "Alu and Cu/CU/CU.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<limits>
#include <regex>
using namespace std;


// the required elements from the cpu --> IR, PC ,clear cpu
class CPU{
private:


    string IR ;
    string  PC ;
    Register registers;
    Alu alu;
    CU cu ;

    bool valid(string IR );

public:
    // show the PC ,IR after we finish
    void fetch(int &row,int &column,const vector<vector<string>>&memo );

    //explain the decode or the meaning of the instruction means what by the cout
    // 1 -> cu // 2->alu // 3->c000
    int decode();

    //execute then show memo, registers
    bool excute(int Case/*,vector<vector<string>>&memo*/);//we have access to the registers
    //if zero continue , else stop

    void clear();//++
    string getter_PC();
    string getter_IR();
    void show_cpu();

    //void setter_register(location , value) ;



};



#endif //CPU_H
