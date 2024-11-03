#include <iostream>
#include "Machine/UI.h"
#include "Machine/Machine.h"
using namespace std;


int main() {

Machine machines;
bool first=true,end;
    while (true){

        end=UI::display_main_menu(first,machines);
        first=false;
        if(!end)
            break;
    }
    return 0;
}
