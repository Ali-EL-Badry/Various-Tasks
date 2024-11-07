#include "Register.h"
void  Register:: set_rgstr(int location,string &value)
{

    rgstr[location]=value;
}

void Register:: clear()
{

    for (int i = 0; i < 16; ++i) {
        rgstr[i]="";
    }
}

string& Register:: get_rgstr(int location)
{

    return rgstr[location];
}

void Register ::print_rgstr()
{
    for (int i = 0; i < 16; ++i)
    {
        if (i<10){
            cout<<"R"<<i<<" : ";
        }else{
            cout<<"R"<<char('A'+(i%10))<<" : ";
        }

        if(!rgstr[i].empty()) { cout << rgstr[i] << endl; }
        else {cout<<"00"<<'\n';}
    }
}

