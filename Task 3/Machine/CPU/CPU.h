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
    map<string,string>Instructions{{"1"," LOAD the register R with the bit pattern found in the memory cell whose address is XY."}
            ,{"2"," LOAD the register R with the bit pattern XY."},
            {"3"," STORE the bit pattern found in register R in the memory cell whose address is XY."},
             {"33","STORE to location 00,which is a memory mapping for the screen.Writing to 00 is writing to screen."}
            ,{"4"," MOVE the bit pattern found in register R to register S."},
            };
    bool valid(string IR );

public:
    // show the PC ,IR after we finish
    void fetch(int &row,int &column,const vector<vector<string>>&memo );

    //explain the decode or the meaning of the instruction means what by the cout
    // 1 -> cu // 2->alu // 3->c000
    int decode();//done

    //execute then show memo, registers
    bool excute(int Case,Memory &memo);//we have access to the registers
    //if zero continue , else stop

    void clear();//done
    string getter_PC();//done
    string getter_IR();//done
    void show_cpu();//done

    //void setter_register(location , value) ;



};



#endif //CPU_H
