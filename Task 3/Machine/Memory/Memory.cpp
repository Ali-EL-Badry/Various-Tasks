#include "Memory.h"

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

string& Memory::get_index(int row ,int coloumn)
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
