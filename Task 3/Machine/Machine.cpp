#include "Machine.h"




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
void Machine::load_file(bool option, string name) {

    ofstream file(name);

    if(option==0){//whole




    }else{//step by step




    }



}