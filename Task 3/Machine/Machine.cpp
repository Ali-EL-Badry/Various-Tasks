#include "Machine.h"




void Machine ::clear( string option) {

    if(option=="1"){

        cpu.clear();

    }else if( option=="2"){

        memory.clear();

    }else{

        cpu.clear();
        memory.clear();
    }

}

void Machine::load_file(bool option, string name, string place) {

    ifstream file(name);

    if(option==0){//whole
        string s;
        bool first =true;
        while (!file.eof()){
            file>>s;
            string part1 ;part1=s[0]+s[1];
            string part2 ;part2=s[0]+s[1];
            if(){
                memory.set_nstrctions();
            }
        }



    }else{//step by step




    }


}
void Machine ::show_machine() {
    cout<<"Machine looks like : \n\n";

    //cpu
    cpu.show_cpu();

    //memory
    memory.print();

    cout<<"\n\n\n";

}