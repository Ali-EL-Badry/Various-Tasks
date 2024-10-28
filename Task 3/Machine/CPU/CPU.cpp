#include "CPU.h"



void CPU::clear() {
    IR.clear();
    PC.clear();
    registers.clear();//clean registers
}
//**
void CPU ::fetch(int& row,int& column,const vector<vector<string>>&memo) {
    //may be will be out , that will be better
    /*cout<<"IR : "<<IR<<'\n';
    cout<<"PC : "<<*PC<<'\n';*/
    again:
    string ir,pc;
    ir+=memo[row][column];
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
    if(column+1<16){
        column++;

    }else{
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
    if(row>9){

        if(row==10)
            rows="A";
        else if(row==11)
            rows="B";
        else if(row==12)
            rows="C";
        else if(row==13)
            rows="D";
        else if(row==14)
            rows="E";
        else
            rows="F";

    }else{
        rows= to_string(row);
    }
    if(column>9){
        if(column==10)
            columns="A";
        else if(column==11)
            columns="B";
        else if(column==12)
            columns="C";
        else if(column==13)
            columns="D";
        else if(column==14)
            columns="E";
        else
            columns="F";
    }else{
        columns= to_string(column);
    }
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
    }else{
        return false;
    }

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
bool CPU::excute(int Case/*, vector<vector<std::string>> &memo*/) {

    if(Case==3){
        return 1;
    }
    if(Case==1){
        //cu



    }else{
        //alu
        int R1[3];string s;
        for (int i = 1; i <= 3; ++i) {
            if(isdigit(IR[i])){
                s=IR[i];
                R1[i-1]=stoi(s);
            }else{
                R1[i-1]=IR[i]-'A'+10;
            }

        }

        if(IR[0]=='5'){
            // pass getter by refernce
        }else{
            // pass getter by refernce
        }
    }


    return 0;
}





