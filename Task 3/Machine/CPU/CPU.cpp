#include "CPU.h"



void CPU::clear() {
    IR.clear();
    PC.clear();
    registers.clear();//clean registers
}
//**
void CPU ::fetch(int& row,int& column,const vector<vector<string>>&memo) {
    again:
    string ir,pc;
    if(!(row>=16||column>=16)){ ir += memo[row][column]; }
    else{return;}
    if(column+1<16){
        column++;
        ir+=memo[row][column];
    }else{
        row++;
        if(row<16)
        {
            column=0;
            ir+=memo[row][column];
        }else{
            return;
        }
    }

    //for pc
    if(column+1<16){column++;}
    else{
        row++;
        if(row<16)
        {
            column=0;

        }else{
            IR=ir;
            //pc?!
            PC="FF";
            return;
        }
    }


    string rows,columns;

    if(row>9){ rows='A'+row-10;}
    else{ rows= to_string(row);}

    if(column>9){columns='A'+column-10;}
    else{columns= to_string(column);}

    pc= rows+ columns;

    if(!valid(ir)){
        goto again;
    }else{
        IR=ir;
        PC=pc;
    }
    return;
}

bool CPU ::valid(std::string ir) {

    string part;
    if(ir.size()!=4)
        return false;

    if(ir[0]=='1'||ir[0]=='2'||ir[0]=='3'||ir[0]=='B'||ir[0]=='5'||ir[0]=='6'){

        part=ir[1]+ir[2]+ir[3];
        if(!regex_match( part, regex(".[0-9A-F]") ) ){
            return false;
        }

    }else if(ir[0]=='C'){

        if(ir!="C000")
            return false;

    }else if(ir[0]=='4'){

        if(ir[1]!='0')
            return false;
        part=ir[2]+ir[3];
        if(!regex_match( part, regex(".[0-9A-F]") ) ){
            return false;
        }

    }else
        return false;


    return true;
}

int CPU  ::decode() {

    if(IR[0]=='1'||IR[0]=='2'||IR[0]=='3'||IR[0]=='4'||IR[0]=='B'){
        return 1;
    }
    else if( IR[0]=='5'||IR[0]=='6'){
        return 2;
    }else if(IR=="C000"){
        return 3;
    }



}

bool CPU::excute(int Case, Memory &memo) {

    if(Case==3){//halt
        return 1;
    }

    vector<char>translation{IR[1],IR[2],IR[3]};
    string  s;

    if(Case==1){
        //cu

        s=translation[1]+translation[2];

        if(IR[0]=='1'){

            CU:: loadAtAdress( memo, registers,translation[0] ,s);

        }else if( IR[0]=='2'){

            CU :: loadwith(registers, translation[0], s);

        }else if(IR[0]=='3'){

            if(translation[1]==0&&translation[2]==0)
               CU:: storeScreen(memo, translation[0], s);
            else
                CU:: storeLocation(memo, registers, translation[0],s);

        }else if(IR[0]=='4'){
            CU:: moveBits(registers, translation[1], translation[2]);
        }else{

           CU:: jumpToLocation(registers , memo, s, translation[0]);

        }

    }
    else{
        //alu
        //char R1[3]={IR[1],IR[2],IR[3]};string s;
        /*for (int i = 1; i <= 3; ++i) {
            if(isdigit(IR[i])){
                s=IR[i];
                R1[i-1]=stoi(s);
            }else{
                R1[i-1]=IR[i]-'A'+10;
            }

        }*/

        if(IR[0]=='5'){
            // pass getter by refernce
        }else{
            // pass getter by refernce
        }
    }


    return 0;
}

string CPU :: getter_PC(){
    return PC;
}

string  CPU:: getter_IR(){
    return IR;
}

void CPU ::show_cpu() {
    cout << "The PC : ";
    if(!PC.empty()){ cout<<PC<<'\n'; }
    else{cout<<"00\n";}

    cout<<"The IR : ";
    if(!IR.empty()){cout<<IR<<'\n';}
    else{cout<<"00\n";}
    cout<<"\n\n";

    cout<<"The Registers looks like : \n\n";
    registers.print_rgstr();
    cout<<"\n\n\n";
}