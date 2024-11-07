#ifndef SEPARETED_VOLE_MACHINE_UI_H
#define SEPARETED_VOLE_MACHINE_UI_H

#include "Machine.h"

class UI {



public:

/*Some declarations for the menu how it goes
 *
 * 1. clear -> (memory , cpu , both)////
 * 2. load instructions  --> input from where to put the instructions
 * --> (file , by hand)-->choose weather whole program or step by step
 * 3.Exit ////
 *
 * */


 static bool display_main_menu(bool first,Machine& machine);

 //static void display_clear_menu(Machine & machine);

 static void display_LoadInstruction_menu(Machine &machine);

 static void DisplayWayOfRead (Machine &machine);



};


#endif //SEPARETED_VOLE_MACHINE_UI_H
