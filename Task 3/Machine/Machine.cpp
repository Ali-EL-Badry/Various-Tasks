#include "Machine.h"

//functions used once
string lower(string s){
    for(auto &c :s)
        c= tolower(c);
    return s;
}



//done
void Machine ::clear( string option) {

    if(option=="2"){

        cpu.clear();

    }else if( option=="1"){

        memory.clear();

    }else{

        cpu.clear();
        memory.clear();
    }

}

//done
bool Machine::load_file( string name, string place) {

    // we need to validate the place string in the range or not
    // message to say that is wrong  file instruction and break and enter again by false boolean

    ifstream file(name);
    string s;
    bool first = true;
    int  row,column;


    while (!file.eof()) {

        file >> s;

        if(!cpu.valid(s)) {
            cout<<"The file contains wrong instructions !!\n\nTry again!";
            memory.clear();
            return false;
        }

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

//done
/*
void Machine:: load_instruction (string place )
{



     cout<<"When you finish type \" Done \" to stop entering instructions \n\n ";

     string s, previous ;
     bool first= true;
     int  row,column;

    while (true){
        again:
         cout<<"Enter the instruction :  ";
        cin>>s;
        string check = lower(s);
        if(check !="done")
            break;

        if(!cpu.valid(s)){
            cout<<"That instruction is wrong , Enter a correct one !!";
            goto again;
        }

        string part1, part2;
        part1=s[0]+s[1];
        part2=s[2]+s[3];

        if(first){

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
                if(row+1>=16)
                    break;
                row++;
                column = 0;
            }

            memory.set_nstrctions(row,column,part2);

            first= false;



        }
        else{
            if(column+1<16) {
                column++;
            }else if (column+1>=16) {
                if(row+1>=16)
                    break;
                row++;
                column = 0;
            }

            memory.set_nstrctions(row,column,part1);

            if(column+1<16) {
                column++;
            }else if (column+1>=16) {
                if(row+1>=16)
                    break;
                row++;
                column = 0;
            }

            memory.set_nstrctions(row,column,part2);





        }

        previous=s;

    }

    if(previous!="C000"){

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


}*/
