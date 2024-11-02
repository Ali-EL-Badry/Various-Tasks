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
    map<char,string>Instructions{
             {'1'," LOAD the register R with the bit pattern found in the memory cell whose address is XY."}

            ,{'2'," LOAD the register R with the bit pattern XY."},

             {'3'," STORE the bit pattern found in register R in the memory cell whose address is XY."},

             {'o',"STORE to location 00,which is a memory mapping for the screen.Writing to 00 is writing to screen."}

            ,{'4'," MOVE the bit pattern found in register R to register S."},

             {'5'," ADD the bit patterns in registers S and T as though they were two’s complement representations and leave the result in register R."}

            ,{'6'," ADD the bit patterns in registers S and T as though they represented values in floating-point notation and leave the floating - point result in register R. "},

             {'7'," Bitwise OR the content of the registers S and T and put the result in register R . "},

             {'8'," Bitwise AND the content of the registers S and T and put the result in register R . "},

             {'9'," Bitwise XOR the content of the registers S and T and put the result in register R . "},

             {'A'," Rotate the content of the register R cyclically right X steps . "},

             {'B'," JUMP to the instruction located in the memory cell at address XY if the bit pattern in register R is equal to the bit pattern in register number 0.Otherwise,continue with the normal sequence of execution."},

             {'D'," JUMP to the instruction located in the memory cell at address XY if the bit pattern in register R is greater than the bit pattern in register number 0.Otherwise,continue with the normal sequence of execution. "},

             {'C',"HALT execution."}

    };

public:

    bool valid(string IR );

    // show the PC ,IR after we finish
    bool fetch(int &row,int &column,const vector<vector<string>>&memo );


    //explain the decode or the meaning of the instruction means what by the cout
    // 1 -> cu // 2->alu // 3->c000
    int decode(bool option);//done // 0 --> step by step
    // 1--> whole program


    //execute then show memo, registers
    bool excute(int& row,int& column,int Case,Memory &memo);//we have access to the registers
    //if zero continue , else stop


    void clear();//done

    string getter_PC();//done

    string getter_IR();//done

    void show_cpu();//done





};



#endif //CPU_H
