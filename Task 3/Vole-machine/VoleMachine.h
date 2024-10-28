#ifndef VOLE_MACHINE_VOLEMACHINE_H
#define VOLE_MACHINE_VOLEMACHINE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<limits>

using namespace std;

//Classes

class Memory{
private:
    vector<vector<string>> nstrctions;
public:
    Memory():nstrctions(16, vector<string>(16,"00")){}
    void set_nstrctions(int row,int coloumn ,string &value);
    void clear();
    string get_index(int row,int coloumn);
    void print();
    vector<vector<string>> get_nstrctions();

};
class Register{
private:
    vector<string> rgstr;
public:
    void set_rgstr(int location,string &value);
    void clear();
    string get_rgstr(int location);
    void print_rgstr();
};
class CU{};
class ALU{};

// the required elements from the cpu --> IR, PC ,clear cpu
class CPU{
private:


    string IR ;
    string  PC ;
    Register registers;
    ALU alu;
    CU cu ;

    bool valid(string IR );

public:
    // show the PC ,IR after we finish
    void fetch(int &row,int &column,vector<vector<string>>&memo );

    //explain the decode or the meaning of the instruction means what by the cout
    // 1 -> cu // 2->alu // 3->c000
    int decode();

    //execute then show memo, registers
    bool excute(int Case,vector<vector<string>>&memo);//we have access to the registers
    //if zero continue , else stop

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

//0 -> all , 1 -> step by step
    void load_file(bool option,string name);//add c000 if not found in the end of the file

    // weather the whole thing or
    // step by step
    void show_machine(bool option);

};
class UI{};


#endif
