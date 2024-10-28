#include "Register.h"
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

string& Register:: get_rgstr(int location)
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

