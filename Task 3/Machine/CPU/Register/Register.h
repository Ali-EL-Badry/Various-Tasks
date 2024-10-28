#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<limits>
#include <regex>
using namespace std;


class Register{
private:
    vector<string> rgstr;
public:
    void set_rgstr(int location,string &value);
    void clear();
    string& get_rgstr(int location);
    void print_rgstr();
};



#endif //REGISTER_H
