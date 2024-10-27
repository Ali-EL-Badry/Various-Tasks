#include <iostream>
#include "VoleMachine.h"
#include <vector>

//**
void CPU::clear() {
    IR.clear();
    PC->clear();
    //clean registers
}
//**
void Machine ::clear( string option) {

    if(option=="1"){

        cpu.clear();
    }else if( option=="2"){

        //clean memory

    }else{

        cpu.clear();
        //clean memory
    }

}