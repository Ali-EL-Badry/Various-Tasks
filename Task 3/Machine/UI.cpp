#include "UI.h"

//used once
string validation(std::string name){

    while (true){
        ifstream files(name);
        try {
            if (files.is_open())
                break;
            else {
                throw runtime_error("please enter again \n");
            }

        }catch(exception & e){//exception is parent to the runtime error //"class"
            cout<<"Please try again !!\n\n Enter a Valid File : ";
            getline(cin,name);
            /* cin.ignore();*/
        }

    }
    return name;

}

bool UI::display_main_menu(bool first,Machine& machine) { // if to end or to continue

    if(first) {
        cout << " Welcome To the Vole Machine Simulator \n\n\n";
        first=false;
    }

    cout<<"Choose from the Following choices : \n\n";
    cout<<"1.Clear\n2.Load instructions\n3.Exit\n\n";

    string choice;cout<<"Enter your choice :  ";
    cin>>choice;cin.ignore();

    while(choice!="1"&& choice!="2"&& choice!="3")
    {
        cout<<"Choose a valid choice : ";
        cin>>choice;
        cin.ignore();
    }

    if(choice=="1"){

        display_clear_menu(machine);

    }else if(choice=="2"){

        display_LoadInstruction_menu(machine);

    }else{

        cout<<"\n\nThanks for using our program :)\n\n";
        return false;
    }

    return true;
}

void UI ::display_clear_menu(Machine& machine) {
    string choice;
    cout<<"So Please Choose from the following list :\n\n"
        <<"1.Clear Memory\n2.Clear CPU\n3.Clear both\n\n"
        <<"Enter your choice : ";
    cin>>choice;
    cin.ignore();

    while(choice!="1"&& choice!="2"&& choice!="3")
    {
            cout<<"Choose a valid choice : ";
            cin>>choice;
            cin.ignore();
    }

    machine.clear(choice);

    //test
    cout<<"Done! , take a look ! \n\n";
    machine.show_machine();

}

void UI:: display_LoadInstruction_menu(Machine &machine){

   /* cout<<"Choose the method to input the instructions : \n\n";
    cout<<"1.Take from file\n2.Input by yourself\n";

    string choice ;cin>>choice;
    cin.ignore();

    while (choice!="1"&&choice!="2"){
        cout<<"Choose a valid choice : ";
        cin>>choice;
        cin.ignore();
    }*/
    cout<<"Which option you want to place with in the memory ?\n\n 1.Default value (10)\n2.Choose a certain place \n\n";
    cout<<"Enter your choice : ";

    string choice ;cin>>choice;
    cin.ignore();

    while (choice!="1"&&choice!="2") {
        cout << "Choose a valid choice : ";
        cin >> choice;
        cin.ignore();
    }

    string place;
   if(choice=="2") {
        cout << "Enter the place that you would like to start putting in  the memory : ";

        cin >> place;
        cin.ignore();

        while (place == "00" && place.size() != 2 && !regex_match(place, regex(".[0-9A-F]"))) {
            cout << "Enter a valid place in memory : ";
            cin >> place;
            cin.ignore();
        }
    }else
        place="10";

  //  if(choice=="1"){

         string name;

         repeat:

         cout<<"Please Enter the name of the file : ";
         getline(cin,name);
         cin.ignore();
         name= validation(name);

         bool isvalid = machine.load_file(name,place);
         if(!isvalid){
             goto repeat;
         }

   // }
    /*else {

       // machine.load_instruction(place);

    }*/
     DisplayWayOfRead (machine);

}

void UI ::DisplayWayOfRead(Machine &machine) {

  cout<<"Choose which way you want to run the instructions : \n\n";
  cout<<"1.Whole Program\n2.Step by Step\n\n";
  cout<<"Enter your choice : ";

  string choice ;
  cin>>choice;cin.ignore();

    while (choice!="1"&&choice!="2"){

        cout<<"Please Enter a valid choice : ";
        cin>>choice;
        cin.ignore();

    }

    machine.read_memory(!(choice=="2"));

}