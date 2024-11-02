#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<limits>
#include <regex>

#include "Memory/Memory.h"
#include "CPU/CPU.h"
using namespace std;


class Machine {
private:
    CPU cpu;
    Memory memory;


public:

    // show options to clear
    void clear(string option );// 1. if to clear registers (of course will be the cpu too),2. clean memo ,3. clean all

//0 -> all , 1 -> step by step
    bool load_file(string name, string place);//add c000 if not found in the end of the file

    // weather the whole thing or
    // step by step
    void show_machine();

    void read_memory(bool option);// 0 -> step by step , 1 -> whole

    void load_instruction (string place  );

};



#endif //MACHINE_H
