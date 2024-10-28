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
// functions of Memory class
//funcion to set an index
void Memory::set_nstrctions(int row,int coloumn ,string &value)
    {


        while(cin.fail()||row>=16||row<0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>row;
        }
        while(cin.fail()||coloumn>=16||coloumn<0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>coloumn;
        }
        nstrctions[row][coloumn]=value;
    }

    void Memory:: clear()
    {
       nstrctions.clear();
    }

    string Memory::get_index(int row ,int coloumn)
    {
        while(cin.fail()||row>=16||row<0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>row;
        }
        while(cin.fail()||coloumn>=16||coloumn<0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>coloumn;
        }
        return nstrctions[row][coloumn];
    }

    void Memory:: print(){
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j <16 ; ++j) {
                cout<<nstrctions[i][j];
            }
        }

    }

vector<vector<string>> Memory::get_nstrctions(){

    return nstrctions;
}
//end of the functions of class Memory


//functions of class Register

  void  Register:: set_rgstr(int location,string &value)
    {
        while(cin.fail()||location>=16||location<0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>location;
        }
        rgstr[location]=value;
    }
void Register:: clear()
    {
        rgstr.clear();
    }


string Register:: get_rgstr(int location)
    {
        while(cin.fail()||location>=16||location<0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>location;
        }
    return rgstr[location];
    }


void Register ::print_rgstr()
    {
    for (int i = 0; i < 16; ++i)
      {
        cout<<rgstr[i]<<endl;
      }
    }
//end of functions of class Register
