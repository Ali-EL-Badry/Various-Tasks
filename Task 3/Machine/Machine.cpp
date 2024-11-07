#include "Machine.h"

//functions used once
string lower(string s){
    for(auto &c :s)
        c= tolower(c);
    return s;
}



//done
void Machine ::clear( /*string option*/) {



        cpu.clear();
        memory.clear();


}

//done
bool Machine::load_file( string name, string place) {


    ifstream file(name);
    string s;
    bool first = true;
    int  row,column;


    while ( file >> s) {



        if(!cpu.valid(s)) {
            cout<<"The file contains wrong instructions !!\n\nTry again!";
            memory.clear();
            return false;
        }

        string part1;
        part1=s.substr(0,2);
        string part2;
        part2=s.substr(2,2);

        if (first) {

           string  r,c;
           r=place[0];c=place[1];

           if(isdigit(place[0])){
               row=stoi(r);
           }else{
               row=place[0]-'A'+10;
           }

           if(isdigit(place[1])){
                column=stoi(c);
           }else{
               column=place[1]-'A'+10;
            }

           memory.set_nstrctions(row,column,part1);

           if(column+1<16) {
                column++;
            }else if (column+1>=16) {
               if(row+1>=16) {
                  cout<<"The space is insufficient ! Try again !! \n\n";
                  memory.clear();
                   return false;
               }
               row++;
               column = 0;
           }

            memory.set_nstrctions(row,column,part2);

            first= false;

        }else{

            if(column+1<16) {
                column++;
            }else if (column+1>=16) {
                if(row+1>=16) {
                    cout<<"The space is insufficient ! Try again !! \n\n";
                    memory.clear();
                    return false;
                }
                row++;
                column = 0;
            }

            memory.set_nstrctions(row,column,part1);

            if(column+1<16) {
                column++;
            }else if (column+1>=16) {
                if(row+1>=16)
                {
                    cout<<"The space is insufficient ! Try again !! \n\n";
                    memory.clear();
                    return false;
                }
                row++;
                column = 0;
            }

            memory.set_nstrctions(row,column,part2);

        }

    }
    if(s!="C000"){

       if(!(column+2>=16&&row+1>=16)) {

           if (column + 1 >= 16) {
                row++;
                column = 0;
            } else
                column++;

            string part = "C0";
            memory.set_nstrctions(row, column, part);

            if (column + 1 >= 16) {
                row++;
                column = 0;
            } else
                column++;

            part="00";
           memory.set_nstrctions(row, column, part);
        }

    }
    return true;


}

//done
void Machine ::show_machine() {
    cout<<"Machine looks like : \n\n";

    //cpu
    cpu.show_cpu();

    //memory
    memory.print();

    cout<<"\n\n\n";

}

//done
void Machine:: read_memory(bool option)// 0 -> step by step , 1 -> whole
{
    bool isvalid, isHalt= false;int Case;
    for (int i = 0; i < 16 ; ++i) {
        for (int j = 0; j < 16; ++j) {

            if(!memory.get_index(i,j).empty()){

                isvalid=cpu.fetch(i,j,memory.get_nstrctions());
                if(!isvalid)
                   continue;
                Case=cpu.decode(option);
                isHalt=cpu.excute(i,j,Case,memory);

                if (!option)
                    show_machine();

                if(isHalt){
                    cout<<"\n\n\n ####### The program is ended #######  \n\n\n";
                    break;
                }

            }

        }

        if(isHalt)
            break;
    }

    if(option)
        show_machine();

}


