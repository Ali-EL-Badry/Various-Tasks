#ifndef VOLE_MACHINE_VOLEMACHINE_H
#define VOLE_MACHINE_VOLEMACHINE_H
#include <iostream>

using namespace std;

//Classes

class Memory{};
class Register{};
class CU{};
class ALU{};

// the required elements from the cpu --> IR, PC ,clear cpu
class CPU{
private:

    string IR ;
    string * PC ;
    Register registers;
    ALU alu;
    CU cu ;

    void valid(string IR );

public:
    // show the PC ,IR after we finish
    void fetch(string * PC );

    //explain the decode or the meaning od the instruction means what by the cout
    // 1 -> cu // 2->alu // 3->c000
    int decode(string IR);

    //execute then show memo, registers
    void excute(int Case);

    void clear();//++
    string getter_PC();
    string getter_IR();
    void show_cpu();

    //void setter_register(location , value) ;



};
class Machine {
private:
  CPU cpu;
  Memory memory;

public:

    // show options to clear //++
    void clear(string option );// 1. if to clear registers (of course will be the cpu too),2. clean memo ,3. clean all

    // Take option to see option of storing way
    void load_file(bool option,string name);
    void show_machine();

};
class UI{};


#endif
