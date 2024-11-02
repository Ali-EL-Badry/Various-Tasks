#include "Machine.h"


void Machine ::clear( string option) {

    if(option=="1"){

        cpu.clear();

    }else if( option=="2"){

        memory.clear();

    }else{

        cpu.clear();
        memory.clear();
    }

}

void Machine::load_file( string name, string place) {
    // we need to validate the place string in the range or not

    ifstream file(name);
    string s;
    bool first = true;
    int  row,column;


    while (!file.eof()) {

        file >> s;
        if(s.size()!=4)
            continue;

        string part1; part1 = s[0] + s[1];
        string part2; part2 = s[2] + s[3];

        if (first) {

           string  r,c;
           r=place[0];c=place[1];

           if(isdigit(place[0])){
               row=stoi(r);
           }else{
               row='A'-place[0]+10;
           }

           if(isdigit(place[1])){
                column=stoi(c);
           }else{
               column='A'-place[1]+10;
            }

           memory.set_nstrctions(row,column,part1);

           if(column+1<16) {
                column++;
            }else if (column+1>=16) {
                row++;
                column = 0;
                if(row>=16)
                    break;
            }

            memory.set_nstrctions(row,column,part2);

            first= false;

        }else{

            if(column+1<16) {
                column++;
            }else if (column+1>=16) {
                row++;
                column = 0;
                if(row>=16)
                    break;
            }

            memory.set_nstrctions(row,column,part1);

            if(column+1<16) {
                column++;
            }else if (column+1>=16) {
                row++;
                column = 0;
                if(row>=16)
                    break;
            }

            memory.set_nstrctions(row,column,part2);

        }

    }
    if(s!="C000"){

       if(!(column+2>=16||row+2>=16)) {

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



}

void Machine ::show_machine() {
    cout<<"Machine looks like : \n\n";

    //cpu
    cpu.show_cpu();

    //memory
    memory.print();

    cout<<"\n\n\n";

}

void Machine:: read_memory(bool option)// 0 -> whole , 1 -> step by step
{
    bool isvalid;int Case;
    for (int i = 0; i <16 ; ++i) {
        for (int j = 0; j < 16; ++j) {

            if(!memory.get_index(i,j).empty()){

                isvalid=cpu.fetch(i,j,memory.get_nstrctions());
                if(!isvalid)
                   continue;
                Case=cpu.decode(option);
                cpu.excute(i,j,Case,memory);

                if (option)
                    show_machine();

            }

        }
    }

}

//missing question
void load_instruction (bool first,string place , string instruction )
{

    // do not forget to handle the case of if the user did not enter C000

    //hashed code
    //cout<<"Please Enter the Instructions "

}