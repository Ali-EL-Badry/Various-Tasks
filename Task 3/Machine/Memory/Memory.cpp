#include "Memory.h"

void Memory::set_nstrctions(int row,int coloumn ,string &value)
{



    nstrctions[row][coloumn]=value;
}

void Memory:: clear()
{

    for (size_t i = 0; i < 16; ++i) {
        for (size_t j = 0; j < 16; ++j) {
            nstrctions[i][j] = "";
        }
    }
}

string& Memory::get_index(int row ,int coloumn)
{

    return nstrctions[row][coloumn];
}

void Memory:: print(){
    cout<<"Memory looks like : \n\n";
    cout<<'.'<<' ';
    for (int i = 0; i <= 15; ++i) {
        if(i<=9){ cout << i << "   "; }
        else{ cout<<char('A'+ i-10)<< "   ";}
    }
    cout<<"\n\n";

    for (int i = 0; i < 16; ++i) {
        if(i<=9){ cout << i << " "; }
        else{ cout<<char('A'+ i-10)<<" ";}
        for (int j = 0; j <16 ; ++j) {
            if(!nstrctions[i][j].empty()){ cout << nstrctions[i][j] << ' '; }
            else{cout << "00" << ' ';}
        }
        cout<<'\n';
    }


}

const vector<vector<string>> & Memory::get_nstrctions(){

    return nstrctions;
}
